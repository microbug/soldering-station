/*
 * util.c
 *
 *  Created on: Mar 3, 2024
 *      Author: richard
 */

#include <string.h>
#include "control_loop.h"

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
