/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PA0   ------> S_TIM2_CH1
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, BAT_REGISTER_Pin|R4_7K_Pin|R75K_Pin|SENSOR_Pin
                          |BLE_RESET_Pin|RF_SW_CTRL_Pin|BAT_DIVIED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, BLE_FREEZ_Pin|CAP_047uF_Pin|CAP_8200pF_Pin|CAP_01uF_Pin
                          |R680_Pin|LCD_RESET_Pin|LOAD_2_7_V_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CE_2_7V_GPIO_Port, CE_2_7V_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BAT_REGISTER_Pin R4_7K_Pin R75K_Pin SENSOR_Pin
                           BLE_RESET_Pin RF_SW_CTRL_Pin BAT_DIVIED_Pin */
  GPIO_InitStruct.Pin = BAT_REGISTER_Pin|R4_7K_Pin|R75K_Pin|SENSOR_Pin
                          |BLE_RESET_Pin|RF_SW_CTRL_Pin|BAT_DIVIED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : BLE_CONNECT_Pin */
  GPIO_InitStruct.Pin = BLE_CONNECT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BLE_CONNECT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BLE_SLP_MON_Pin */
  GPIO_InitStruct.Pin = BLE_SLP_MON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BLE_SLP_MON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BLE_FREEZ_Pin CAP_047uF_Pin CAP_8200pF_Pin CAP_01uF_Pin
                           R680_Pin LCD_RESET_Pin LOAD_2_7_V_Pin */
  GPIO_InitStruct.Pin = BLE_FREEZ_Pin|CAP_047uF_Pin|CAP_8200pF_Pin|CAP_01uF_Pin
                          |R680_Pin|LCD_RESET_Pin|LOAD_2_7_V_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : CE_2_7V_Pin */
  GPIO_InitStruct.Pin = CE_2_7V_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CE_2_7V_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
