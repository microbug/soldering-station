/*
 * ui.h
 *
 *  Created on: Jan 21, 2024
 *      Author: richard
 */

#ifndef UI_H_
#define UI_H_

#define BTN_DEBOUNCE_CYCLES 50  // Cycles of TIM2 to check button again for debounce purposes
typedef enum {
	BTN_NONE,
	BTN_ENTER,
	BTN_UP,
	BTN_DOWN,
	BTN_MENU
} Button;

void button_debounce_handler(void);
void check_buttons(void);
void string_pad(char* str, size_t n);
void refresh_display(void);

#endif /* UI_H_ */
