#ifndef USER_MAIN_H_
#define USER_MAIN_H_

#define TIP_MIN_TEMP_DEGC 0
#define TIP_MAX_TEMP_DEGC 450

#define TASK_PERIOD_CTRL_LOOP_MS 99
#define TASK_PERIOD_CHECK_BUTTONS_MS 10
#define TASK_PERIOD_REFRESH_DISPLAY_MS 50

void user_systick_handler(void);
void user_main(void);


#endif /* USER_MAIN_H_ */
