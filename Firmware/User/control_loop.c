/*
 * control_loop.c
 *
 *  Created on: Jan 21, 2024
 *      Author: richard
 */

#include "adc.h"
#include "tim.h"

#include "user_main.h"
#include "control_loop.h"
#include "thermocouple.h"
#include "util.h"

#ifdef REPORT_TEMPERATURE_LPUART
#include "usart.h"
#include <string.h>
#include <stdlib.h>
#endif

// Accurate within 20%
#define DELAY_US(t) do {for(uint32_t delay_i = 0; delay_i < (t)*4; delay_i++) __asm__("NOP");} while (0);

typedef enum {
	OC_HIGH_PERIOD,
	OC_LOW_PERIOD
} OCTrigger;

volatile uint16_t adc_dma_buf;
volatile uint32_t accumulator = 0;
volatile uint32_t counter = 0;

volatile float tip_temperature_degC = 0.0F;

// Tuned using Ziegler-Nichols method
// Ku = 0.19, Tu = 1.33
// PI controller, not PID
PIDData tip_pid = {
	// Const data
	.k_p = 0.0855F,
	.k_i = 0.0770F,

	.pid_window_degC = 100.0F,
	.period_s = (float) TASK_PERIOD_CTRL_LOOP_MS / 1000.0F,

	// Non-const data
	.setpoint_degC = TIP_INITIAL_SETPOINT_DEGC,
	// Must initialise these to 0
	.integral_degCs = 0.0F,
};



void control_loop_init(void) {
	HAL_ADC_Start_DMA(&hadc, (uint32_t*)&adc_dma_buf, 1);
}


void control_loop_run(void) {

	__disable_irq();  // Critical section
	uint32_t acc_copy = accumulator;
	uint32_t count_copy = counter;
	accumulator = 0;
	counter = 0;
	__enable_irq();

	LL_GPIO_SetOutputPin(OC_TEST_GPIO_Port, OC_TEST_Pin);
	float adc_code = (float) acc_copy / (float) count_copy;
	float result_V = adc_code * 3.3F / 4095.0F;
	result_V /= TC_AMP_GAIN;  // Remove amplifier gain

	tip_temperature_degC = tc_voltage_to_temperature(result_V);

	float duty_cycle = run_pid(&tip_pid, tip_temperature_degC);

	#ifdef REPORT_TEMPERATURE_LPUART
		char buf[5];
		itoa((10.0F*tip_temperature_degC)+0.5F, buf, 10);
		print_lpuart(buf);
		print_lpuart("\r\n");
	#endif

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty_cycle * TIP_PWM_MAX);
}


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
	__disable_irq();  // Critical section
	accumulator += (adc_dma_buf & 0xFFF);
	counter++;
	__enable_irq();
}


/**
 * Evaluates a PID loop with constants and state in `data`.
 *
 * Returns a float representing the duty cycle output. This value is capped between 0.0F and 1.0F.
 */
float run_pid(PIDData* data, float temp_degC) {
	float error_degC = data->setpoint_degC - temp_degC;
	float duty_cycle;

	// Fix duty_cycle if outside PID window
	if (error_degC > data->pid_window_degC) {
		duty_cycle = 1.0F;
		data->integral_degCs = 0.0F;
	} else if (error_degC < -data->pid_window_degC) {
		duty_cycle = 0.0F;
		data->integral_degCs = 0.0F;
	} else {  // Use PID control if abs(temp_degC) < pid_window_degC
		// Run PI loop
		data->integral_degCs += error_degC * data->period_s;
		duty_cycle = data->k_p*error_degC + data->k_i*data->integral_degCs;
#ifdef USE_PID_NOT_PI
		// Optionally add derivative
		float derivative_degCps = (error_degC - data->last_deltaT_degC) / data->period_s;
		duty_cycle -= data->k_d*derivative_degCps;
#endif

		// Cap output to 0.0F - 1.0F (inclusive)
		duty_cycle = (duty_cycle < 1.0F) ? duty_cycle : 1.0F;
		duty_cycle = (duty_cycle > 0.0F) ? duty_cycle : 0.0F;
	}
#ifdef USE_PID_NOT_PI
	data->last_deltaT_degC = error_degC;
#endif

	return duty_cycle;
}

