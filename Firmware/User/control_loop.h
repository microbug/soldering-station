#ifndef CONTROL_LOOP_H_
#define CONTROL_LOOP_H_

#include <stdbool.h>
#include <stdint.h>

// Uncomment to enable the full PID loop instead of PI
// #define USE_PID_NOT_PI

typedef struct PIDData {
	const float k_p, k_i;
	const float period_s;  // Period between evalutions of PID loop
	const float pid_window_positive_degC;  // Temperature above the setpoint when PID is disabled
	const float pid_window_negative_degC;  // Temperature below the setpoint when PID is disabled

	volatile float setpoint_degC;
	float integral_degCs;
#ifdef USE_PID_NOT_PI
	const float k_d;
	float last_deltaT_degC;  // Used to calculate derivative
#endif
} PIDData;

#define TIP_PWM_MAX 499  // Max high cycles (zero indexed) of PWM counter
#define TIP_INITIAL_SETPOINT_DEGC 150

// If defined, temperature is reported on LPUART1 PA4 9600 baud
//#define REPORT_TEMPERATURE_LPUART

void control_loop_init(void);
void control_loop_run(void);
float run_pid(PIDData* data, float temp_degC);
void adc_dma_transfer_complete_callback(void);
float get_adc_V(void);

extern volatile float tip_temperature_degC;
extern PIDData tip_pid;
extern volatile uint16_t adc_dma_buf;


#endif /* CONTROL_LOOP_H_ */
