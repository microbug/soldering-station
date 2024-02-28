/*
 * ui.c
 *
 *  Created on: Jan 21, 2024
 *      Author: richard
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "gpio.h"
#include "tim.h"

#include "control_loop.h"
#include "lcd_hd44780_i2c.h"
#include "ui.h"
#include "user_main.h"

volatile Button button_raw, button_debounced;

/**
 * Refreshes the display by redrawing all elements. lcdClear() is not used to
 * avoid flickering. Redrawing same character in same position does not cause
 * flickering, but display clear followed by redraw does.
 */
void refresh_display(void) {
	char line[17] = "";

	// Top row
	lcdSetCursorPosition(0, 0);
	float error = tip_temperature_degC - tip_pid.setpoint_degC;
	if (error > -10.0F && error < 10.0F) {
		strcat(line, "Ready");
	} else if (error < 10.0F) {
		strcat(line, "Heating");
	} else {
		strcat(line, "OverTemp!");
	}
	string_pad(line, 16);
	lcdPrintStr(line);

	// Bottom row LCD format: "T:YYY/ZZZ  P:YYY"
	line[0] = 0;
	strcat(line, "T:");
	char num[5];  // Buffer for itoa

	// Left hand side
	itoa(tip_temperature_degC + 0.5F, num, 10);
	strcat(line, num);
	strcat(line, "/");
	itoa(tip_pid.setpoint_degC + 0.5F, num, 10);
	strcat(line, num);

	// Right hand side
	string_pad(line, 11);
	strcat(line, "P:");
	itoa(__HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_1) / 10, num, 10);
	strcat(line, num);
	string_pad(line, 16);
	lcdSetCursorPosition(0, 1);
	lcdPrintStr(line);
}


// Callback for button press interrupts
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	lcdSetCursorPosition(0, 1);
	switch (GPIO_Pin) {
	case BTN_ENTER_Pin:
		button_raw = BTN_ENTER;
		break;

	case BTN_UP_Pin:
		button_raw = BTN_UP;
		break;

	case BTN_DOWN_Pin:
		button_raw = BTN_DOWN;
		break;

	case BTN_MENU_Pin:
		button_raw = BTN_MENU;
		break;
	}
}


/**
 * Periodic task checking whether debounced button flags are set, and handling
 * button actions.
 */
void check_buttons(void) {
	switch (button_debounced) {
		case BTN_UP:
			if (tip_pid.setpoint_degC < TIP_MAX_TEMP_DEGC) {
				__disable_irq();
				tip_pid.setpoint_degC += 10;
				__enable_irq();
			}
			break;
		case BTN_DOWN:
			if (tip_pid.setpoint_degC > TIP_MIN_TEMP_DEGC) {
				__disable_irq();
				tip_pid.setpoint_degC -= 10;
				__enable_irq();
			}
			break;
		case BTN_ENTER:
		case BTN_MENU:
		case BTN_NONE:
			break;
	}

	button_debounced = BTN_NONE;
}


/**
 * Timer update task called every 1ms. Debounces buttons by waiting for
 * BTN_DEBOUNCE_CYCLES*1ms and then checking if button is still pressed.
 */
void button_debounce_handler(void) {
	if (button_raw != BTN_NONE) {
		static uint8_t counter = BTN_DEBOUNCE_CYCLES;
		if (counter != 0) {
			counter--;
			return;
		}

		GPIO_TypeDef* button_port;
		uint32_t button_pin;

		switch (button_raw) {
		case BTN_ENTER:
			button_port = BTN_ENTER_GPIO_Port;
			button_pin = BTN_ENTER_Pin;
			break;
		case BTN_MENU:
			button_port = BTN_MENU_GPIO_Port;
			button_pin = BTN_MENU_Pin;
			break;
		case BTN_DOWN:
			button_port = BTN_DOWN_GPIO_Port;
			button_pin = BTN_DOWN_Pin;
			break;
		case BTN_UP:
			button_port = BTN_UP_GPIO_Port;
			button_pin = BTN_UP_Pin;
			break;
		default:  // Includes BTN_NONE
			Error_Handler();
			return;
		}

		// Buttons are active low
		if (!(LL_GPIO_ReadInputPort(button_port) & button_pin)) {
			button_debounced = button_raw;
		}

		counter = BTN_DEBOUNCE_CYCLES;
		button_raw = BTN_NONE;
	}
}


/**
 * Pad string with spaces after it up to length n.
 */
void string_pad(char* str, size_t n) {
	size_t len = strlen(str);
	size_t spaces = n - len;
	for (size_t i = 0; i < spaces; i++) {
		strcat(str, " ");
	}
//	while (strlen(str) < n) {
//		strcat(str, " ");
//	}
}
