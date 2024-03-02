/*
 * ui.h
 *
 *  Created on: Jan 21, 2024
 *      Author: richard
 */

#ifndef UI_H_
#define UI_H_

#include <stdbool.h>

// Above this temperature, controller will assume no tool is connected (as the input to
// the thermocouple amp is weakly pulled up)
#define NO_TOOL_TEMPERATURE_DEGC  550.0F
// Degrees about the setpoint where 'Ready' will be displayed on the LCD
#define READY_WINDOW_DEGC  15.0F
#define BTN_DEBOUNCE_CYCLES 50  // Cycles of TIM2 to check button again for debounce purposes
#define BTN_REPEAT_PERIOD_MS 200 // When holding a button, new presses are registered every <this> ms
#define BTN_TEMPERATURE_STEP 10  // Each up/down press increases/decreases temperature by this amount

typedef enum {
	BTN_NONE,
	BTN_ENTER,
	BTN_UP,
	BTN_DOWN,
	BTN_MENU
} Button;

void button_debounce_handler(void);
void buttons_process_debounced(void);
void button_event_up(void);
void button_event_down(void);
bool button_pressed(Button button);
void string_pad(char* str, size_t n);
void refresh_display(void);

#endif /* UI_H_ */
