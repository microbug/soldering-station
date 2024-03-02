/*
 * ui.c
 *
 *  Created on: Jan 21, 2024
 *      Author: richard
 */
#include <stdbool.h>
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
 * avoid flickering. Redrawing the same character in the same position does not cause
 * flickering, but a display clear followed by a redraw does.
 */
void refresh_display(void) {
	char line[17] = "";

	// Top row
	lcdSetCursorPosition(0, 0);
	float error = tip_temperature_degC - tip_pid.setpoint_degC;
	bool tool = true;
	if (tip_temperature_degC > NO_TOOL_TEMPERATURE_DEGC) {
		tool = false;
		strcat(line, "No tool");
	} else if (error > -READY_WINDOW_DEGC && error < READY_WINDOW_DEGC) {
		strcat(line, "Ready");
	} else if (error < -READY_WINDOW_DEGC) {
		strcat(line, "Heating");
	} else {
		strcat(line, "Over temp!");
	}
	string_pad(line, 16);
	lcdPrintStr(line);

	// Bottom row LCD format:   "T:YYY/ZZZ  P:YYY"
	// When no tool is present: "T:-/ZZZ    P:-  "
	line[0] = 0;
	strcat(line, "T:");
	char num[5];  // Buffer for itoa

	// Left hand side
	if (tool) {
		itoa(tip_temperature_degC + 0.5F, num, 10);
	} else {
		strcpy(num, "-");
	}
	strcat(line, num);
	strcat(line, "/");
	itoa(tip_pid.setpoint_degC + 0.5F, num, 10);
	strcat(line, num);

	// Right hand side
	string_pad(line, 11);
	strcat(line, "P:");
	if (tool) {
		itoa(__HAL_TIM_GET_COMPARE(&htim2, TIM_CHANNEL_1) / 10, num, 10);
	} else {
		strcpy(num, "-");
	}
	strcat(line, num);

	string_pad(line, 16);
	lcdSetCursorPosition(0, 1);
	lcdPrintStr(line);
}


// Callback for button press interrupts
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
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
 * button actions if they are.
 */
void buttons_process_debounced(void) {
	static uint32_t last_hold_event = 0;
	static Button last_button = BTN_NONE;

	bool button_pressed_first_time = button_debounced != BTN_NONE && last_hold_event == 0;
	bool button_held = button_debounced == last_button && button_pressed(button_debounced);

	if (button_pressed_first_time || button_held) {
		if (HAL_GetTick() - last_hold_event >= BTN_REPEAT_PERIOD_MS) {
			last_hold_event = HAL_GetTick();
		} else {
			// Ignore when button is held for less than the repeat period
			return;
		}
	} else {
		last_hold_event = 0;
		button_debounced = BTN_NONE;
	}
	last_button = button_debounced;

	switch (button_debounced) {
		case BTN_UP:
			button_event_up();
			break;
		case BTN_DOWN:
			button_event_down();
			break;
		case BTN_ENTER:
		case BTN_MENU:
		case BTN_NONE:
			break;
	}
}

void button_event_up(void) {
	if (tip_pid.setpoint_degC < TIP_MAX_TEMP_DEGC) {
		__disable_irq();
		tip_pid.setpoint_degC += BTN_TEMPERATURE_STEP;
		__enable_irq();
	}
}

void button_event_down(void) {
	if (tip_pid.setpoint_degC > TIP_MIN_TEMP_DEGC) {
		__disable_irq();
		tip_pid.setpoint_degC -= BTN_TEMPERATURE_STEP;
		__enable_irq();
	}
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

		// Buttons are active low
		if (button_pressed(button_raw)) {
			button_debounced = button_raw;
		}

		counter = BTN_DEBOUNCE_CYCLES;
		button_raw = BTN_NONE;
	}
}

/**
 * Returns true if `button` is pressed, false otherwise.
 */
bool button_pressed(Button button) {
	uint32_t button_pin;
	GPIO_TypeDef* button_port;

	switch (button) {
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
		return false;
	}

	// Button pins are active low
	return !(LL_GPIO_ReadInputPort(button_port) & button_pin);
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
}
