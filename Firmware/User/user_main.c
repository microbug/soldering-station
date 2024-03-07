#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "lcd_hd44780_i2c.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"
#include "adc.h"

#include "user_main.h"
#include "thermocouple.h"
#include "control_loop.h"
#include "ui.h"
#include "util.h"



/**
 * NOTE
 * This project uses the LL GPIO library to save flash and RAM.
 * Interrupt handlers are called from file stm32l0xx_it.c (in Core/Src).
 *
 * HAL_GPIO_EXTI_Callback is not called, unless manually added to the
 * interrupt handlers in stm32l0xx_it.c!
 *
 * Calls to HAL_GPIO_EXTI_Callback have been added for the button pins.
 */

/**
 * Tasks for the firmware:
 * - Control temperature (PID or bang-bang)
 *  - Optional: report temperature over UART for PID tuning
 * - Run UI (50Hz is ok)
 * 	- Debounce button inputs
 *
 */

/**
 * Timer tasks:
 * - N=10 take first current reading
 * - N=N_PWM + 20 take second current reading and temperature reading
 */

volatile bool buttons_process_flag = false;
volatile bool refresh_display_flag = false;
volatile bool check_tip_active_flag = false;

volatile bool tip_active = false;

void user_main(void) {
	lcdInit(&hi2c1, 0x27, 2, 16);

	volatile uint32_t a = *(uint32_t*)DATA_EEPROM_BASE;
//	HAL_FLASHEx_DATAEEPROM_Unlock();
//	HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, DATA_EEPROM_BASE, 0xDEADCAFE);
//	HAL_FLASHEx_DATAEEPROM_Lock();

#ifdef REPORT_TEMPERATURE_LPUART
	LL_LPUART_Enable(LPUART1);
#endif
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);  // Disable tip heater

	if (!LL_ADC_IsEnabled(ADC1)) {
		uint32_t adc_dma_settings_backup = LL_ADC_REG_GetDMATransfer(ADC1);
		LL_ADC_REG_SetDMATransfer(ADC1, LL_ADC_REG_DMA_TRANSFER_NONE);
		LL_ADC_StartCalibration(ADC1);
		while (LL_ADC_IsCalibrationOnGoing(ADC1) != 0);
		LL_ADC_REG_SetDMATransfer(ADC1, adc_dma_settings_backup);
	}

	// Must set up DMA after calibration (otherwise cal data will be transferred)
	LL_DMA_EnableIT_TC(DMA1, LL_DMA_CHANNEL_1);
	LL_DMA_EnableIT_TE(DMA1, LL_DMA_CHANNEL_1);
	LL_DMA_ConfigAddresses(DMA1, LL_DMA_CHANNEL_1,
		LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
		(uint32_t)&adc_dma_buf, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
	LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, 1);
	LL_DMA_SetPeriphRequest(DMA1, LL_DMA_CHANNEL_1, LL_DMA_REQUEST_0);

	LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);
	LL_ADC_Enable(ADC1);
	while (!LL_ADC_IsActiveFlag_ADRDY(ADC1));

	if (!LL_ADC_IsEnabled(ADC1)
			|| LL_ADC_IsDisableOngoing(ADC1)
			|| LL_ADC_REG_IsConversionOngoing(ADC1)) {
		fatal_error("ADC setup err");
	}

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 600);
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2);  // Starts control loop

	while (true) {
		if (buttons_process_flag) {
			buttons_process_debounced();
			buttons_process_flag = false;
		}
		if (refresh_display_flag) {
			refresh_display();
			refresh_display_flag = false;
		}

		if (check_tip_active_flag) {
			check_tip_active();
			check_tip_active_flag = false;
		}

		HAL_Delay(1);
	}
}

void check_tip_active(void) {
	static float last_active_setpoint;

	// Tip active is active high (placing tip in stand pulls pin low)
	if (LL_GPIO_ReadInputPort(TIP_ACTIVE_GPIO_Port) & TIP_ACTIVE_Pin) {
		tip_active = true;
		if (last_active_setpoint != 0.0F) {
			tip_pid.setpoint_degC = last_active_setpoint;
			last_active_setpoint = 0.0F;
		}
	} else {
		if (last_active_setpoint == 0.0F) {
			last_active_setpoint = tip_pid.setpoint_degC;
		}
		tip_pid.setpoint_degC = TIP_SLEEP_SETPOINT_DEGC;
		tip_active = false;
	}
}


/**
 * TIM2 output compare callback. Called after the PWM high period so that
 * current measurement can be performed at the correct time.
 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) {
	LL_DMA_DisableChannel(DMA1, LL_DMA_CHANNEL_1);
	// CDNTR is decremented every DMA transfer, and cannot be set while the channel is enabled.
	LL_DMA_SetDataLength(DMA1, LL_DMA_CHANNEL_1, 1);
	LL_DMA_EnableChannel(DMA1, LL_DMA_CHANNEL_1);

	LL_ADC_REG_StartConversion(ADC1);
}

/**
 * Called by SysTick_Handler() every 1ms.
 */
void user_systick_handler(void) {
	if (HAL_GetTick() % TASK_PERIOD_CTRL_LOOP_MS == 0) {
		control_loop_run();
	}

	// Runs every 1ms to handle debounce timers for buttons
	button_debounce_handler();

	if (HAL_GetTick() % TASK_PERIOD_CHECK_BUTTONS_MS == 0) {
		buttons_process_flag = true;
	}

	if (HAL_GetTick() % TASK_PERIOD_REFRESH_DISPLAY_MS == 0) {
		refresh_display_flag = true;
	}

	if (HAL_GetTick() % TASK_PERIOD_CHECK_TIP_ACTIVE_MS == 0) {
		check_tip_active_flag = true;
	}
}
