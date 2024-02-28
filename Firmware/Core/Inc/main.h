/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

#include "stm32l0xx_ll_crs.h"
#include "stm32l0xx_ll_rcc.h"
#include "stm32l0xx_ll_bus.h"
#include "stm32l0xx_ll_system.h"
#include "stm32l0xx_ll_exti.h"
#include "stm32l0xx_ll_cortex.h"
#include "stm32l0xx_ll_utils.h"
#include "stm32l0xx_ll_pwr.h"
#include "stm32l0xx_ll_dma.h"
#include "stm32l0xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_ENTER_Pin LL_GPIO_PIN_9
#define BTN_ENTER_GPIO_Port GPIOB
#define BTN_ENTER_EXTI_IRQn EXTI4_15_IRQn
#define BTN_MENU_Pin LL_GPIO_PIN_14
#define BTN_MENU_GPIO_Port GPIOC
#define BTN_MENU_EXTI_IRQn EXTI4_15_IRQn
#define BTN_UP_Pin LL_GPIO_PIN_15
#define BTN_UP_GPIO_Port GPIOC
#define BTN_UP_EXTI_IRQn EXTI4_15_IRQn
#define TIP_TC_AMP_Pin LL_GPIO_PIN_0
#define TIP_TC_AMP_GPIO_Port GPIOA
#define HEATER_CURRENT_AMP_Pin LL_GPIO_PIN_1
#define HEATER_CURRENT_AMP_GPIO_Port GPIOA
#define TIP_ACTIVE_Pin LL_GPIO_PIN_2
#define TIP_ACTIVE_GPIO_Port GPIOA
#define OC_TEST_Pin LL_GPIO_PIN_3
#define OC_TEST_GPIO_Port GPIOA
#define TIP_PWM_Pin LL_GPIO_PIN_5
#define TIP_PWM_GPIO_Port GPIOA
#define BTN_DOWN_Pin LL_GPIO_PIN_1
#define BTN_DOWN_GPIO_Port GPIOB
#define BTN_DOWN_EXTI_IRQn EXTI0_1_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
