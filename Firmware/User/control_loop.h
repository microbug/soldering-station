/*
 * control_loop.h
 *
 *  Created on: Jan 21, 2024
 *      Author: richard
 */

#ifndef CONTROL_LOOP_H_
#define CONTROL_LOOP_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct PIDData {
	const float k_p, k_i, k_d;
	const float period_s;  // Period between evalutions of PID loop
	const float pid_window_degC;  // Temperature range (plus/minus about setpoint) in which the PID loop is active
	volatile float setpoint_degC;
	float integral_degCs;
	float last_deltaT_degC;  // Used to calculate derivative
} PIDData;

#define TIP_PWM_MAX 499  // Max high cycles (zero indexed) of PWM counter

void control_loop_init(void);
void control_loop_run(void);
float run_pid(PIDData* data, float temp_degC);

extern volatile float tip_temperature_degC;
extern PIDData tip_pid;
extern volatile uint16_t adc_dma_buf;


#endif /* CONTROL_LOOP_H_ */
