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

void user_main(void) {
	lcdInit(&hi2c1, 0x27, 2, 16);

	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 600);

	// Must be run before HAL_ADC_Start()
	HAL_ADCEx_Calibration_Start(&hadc, ADC_SINGLE_ENDED);
	HAL_Delay(1);  // Must allow 2 ADC clock cycles before starting

	control_loop_init();

	while (true) {
		if (buttons_process_flag) {
			buttons_process_debounced();
			buttons_process_flag = false;
		}
		if (refresh_display_flag) {
			refresh_display();
			refresh_display_flag = false;
		}

		HAL_Delay(1);
	}
}


/**
 * TIM2 output compare callback. Called after the PWM high period so that
 * current measurement can be performed at the correct time.
 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_ADC_Start_DMA(&hadc, (uint32_t*)&adc_dma_buf, 1);
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
}
