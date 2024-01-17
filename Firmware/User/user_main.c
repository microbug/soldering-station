#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "lcd_hd44780_i2c.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

#include "user_main.h"

// Accurate within 20%
#define DELAY_US(t) do {for(uint32_t delay_i = 0; delay_i < (t)*4; delay_i++) __asm__("NOP");} while (0);


void user_main(void) {
	lcdInit(&hi2c1, 0x27, 2, 16);
	char str[] = "Hello, world!";
	lcdPrintStr(str);
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 980);
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 980);
	sprintf(str, "%d test", 56);
	while (true);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	lcdSetCursorPosition(0, 1);
	switch (GPIO_Pin) {
	case BTN_ENTER_Pin:
		lcdPrintStr("E");
		break;

	case BTN_UP_Pin:
		lcdPrintStr("U");
		break;

	case BTN_DOWN_Pin:
		lcdPrintStr("D");
		break;

	case BTN_MENU_Pin:
		lcdPrintStr("M");
		break;

	default:
		assert(false);
	}
}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim) {
	DELAY_US(50);
	LL_GPIO_SetOutputPin(OC_TEST_GPIO_Port, OC_TEST_Pin);
	DELAY_US(50);
	LL_GPIO_ResetOutputPin(OC_TEST_GPIO_Port, OC_TEST_Pin);

}
