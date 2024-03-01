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

PIDData tip_pid = {
	// const data
	.k_p = 0.02F,
	.k_i = 0.01F,
	.k_d = 0.005F,
	.pid_window_degC = 50.0F,
	.period_s = (float) TASK_PERIOD_CTRL_LOOP_MS / 1000.0F,

	.setpoint_degC = 0.0F,
	.integral_degCs = 0.0F,
	.last_deltaT_degC = 0.0F
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

		// Run the PID loop
		float derivative_degCps = (error_degC - data->last_deltaT_degC) / data->period_s;
		data->integral_degCs += error_degC * data->period_s;
		duty_cycle = data->k_p*error_degC + data->k_i*data->integral_degCs - data->k_d*derivative_degCps;

		// Cap to 0.0F - 1.0F (inclusive)
		duty_cycle = (duty_cycle < 1.0F) ? duty_cycle : 1.0F;
		duty_cycle = (duty_cycle > 0.0F) ? duty_cycle : 0.0F;
	}
	data->last_deltaT_degC = error_degC;


	return duty_cycle;
}
