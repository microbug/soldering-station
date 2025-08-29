#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#include <stdbool.h>

#define TIP_MIN_TEMP_DEGC 0
#define TIP_MAX_TEMP_DEGC 450
#define TIP_SLEEP_SETPOINT_DEGC 100.0F

#define TASK_PERIOD_CTRL_LOOP_MS 99
#define TASK_PERIOD_CHECK_BUTTONS_MS 10
#define TASK_PERIOD_REFRESH_DISPLAY_MS 32
#define TASK_PERIOD_CHECK_TIP_ACTIVE_MS 101
#define TASK_PERIOD_SAVE_SETPOINT 1000

#define SAVED_SETPOINT (*(volatile uint32_t*)DATA_EEPROM_BASE)

void user_systick_handler(void);
void user_main(void);
void check_tip_active(void);
void save_setpoint(void);

extern bool tip_active;
extern bool menu_sleep;

#endif /* USER_MAIN_H_ */
