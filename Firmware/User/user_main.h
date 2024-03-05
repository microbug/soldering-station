#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#include <stdbool.h>

#define TIP_MIN_TEMP_DEGC 0
#define TIP_MAX_TEMP_DEGC 450
#define TIP_SLEEP_SETPOINT_DEGC 100.0F

#define TASK_PERIOD_CTRL_LOOP_MS 99
#define TASK_PERIOD_CHECK_BUTTONS_MS 10
#define TASK_PERIOD_REFRESH_DISPLAY_MS 49
#define TASK_PERIOD_CHECK_TIP_ACTIVE_MS 101

void user_systick_handler(void);
void user_main(void);
void check_tip_active(void);

extern volatile bool tip_active;

#endif /* USER_MAIN_H_ */
