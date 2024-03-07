#include <string.h>
#include "main.h"
#include "control_loop.h"
#include "lcd_hd44780_i2c.h"
#include "tim.h"

#ifdef REPORT_TEMPERATURE_LPUART
#include "usart.h"

void print_lpuart(char* str) {
	for (size_t i = 0; i < strlen(str); i++) {
		while (!LL_LPUART_IsActiveFlag_TXE(LPUART1));
		LL_LPUART_TransmitData8(LPUART1, str[i]);
	}
	while (!LL_LPUART_IsActiveFlag_TC(LPUART1));
}
#endif


/**
 * Prints an error to the LCD and optionally LPUART, and then calls Error_Handler.
 *
 * msg: string with max length 16 (17 including null terminator).
 */
void fatal_error(char* msg) {
	// Must do this here as well as in Error_Handler, in case LCD I2C fails and stops progression to Error_Handler().
	__disable_irq();
	// Disable tip PWM
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);

	lcdDisplayClear();
	lcdSetCursorPosition(0, 1);
	lcdPrintStr(msg);

#ifdef REPORT_TEMPERATURE_LPUART
	print_lpuart("Error: ");
	print_lpuart(msg);
	print_lpuart("\r\n");
#endif

	Error_Handler();
}
