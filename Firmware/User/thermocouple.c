/*
 * thermocouple.c
 *
 *  Created on: Sep 27, 2020
 *      Author: richard
 */


#include "thermocouple.h"
#include <stdint.h>

/**
 * Convert a thermocouple voltage to temperature in degrees C
 */
float tc_voltage_to_temperature(float V) {
	return V * TC_COEFF_K_PER_V;
}

