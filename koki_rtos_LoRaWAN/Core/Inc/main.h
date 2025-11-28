/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32wlxx_hal.h"

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
#define RTC_PREDIV_A ((1<<(15-RTC_N_PREDIV_S))-1)
#define RTC_N_PREDIV_S 10
#define RTC_PREDIV_S ((1<<RTC_N_PREDIV_S)-1)
#define BAT_REGISTER_Pin GPIO_PIN_3
#define BAT_REGISTER_GPIO_Port GPIOB
#define R4_7K_Pin GPIO_PIN_4
#define R4_7K_GPIO_Port GPIOB
#define R75K_Pin GPIO_PIN_5
#define R75K_GPIO_Port GPIOB
#define SENSOR_Pin GPIO_PIN_6
#define SENSOR_GPIO_Port GPIOB
#define BLE_RESET_Pin GPIO_PIN_7
#define BLE_RESET_GPIO_Port GPIOB
#define BLE_CONNECT_Pin GPIO_PIN_8
#define BLE_CONNECT_GPIO_Port GPIOB
#define BLE_SLP_MON_Pin GPIO_PIN_1
#define BLE_SLP_MON_GPIO_Port GPIOA
#define BLE_FREEZ_Pin GPIO_PIN_4
#define BLE_FREEZ_GPIO_Port GPIOA
#define CAP_047uF_Pin GPIO_PIN_5
#define CAP_047uF_GPIO_Port GPIOA
#define CAP_8200pF_Pin GPIO_PIN_6
#define CAP_8200pF_GPIO_Port GPIOA
#define CAP_01uF_Pin GPIO_PIN_7
#define CAP_01uF_GPIO_Port GPIOA
#define R680_Pin GPIO_PIN_8
#define R680_GPIO_Port GPIOA
#define LCD_RESET_Pin GPIO_PIN_9
#define LCD_RESET_GPIO_Port GPIOA
#define RF_SW_CTRL_Pin GPIO_PIN_0
#define RF_SW_CTRL_GPIO_Port GPIOB
#define BAT_DIVIED_Pin GPIO_PIN_12
#define BAT_DIVIED_GPIO_Port GPIOB
#define CE_2_7V_Pin GPIO_PIN_13
#define CE_2_7V_GPIO_Port GPIOC
#define LOAD_2_7_V_Pin GPIO_PIN_15
#define LOAD_2_7_V_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
