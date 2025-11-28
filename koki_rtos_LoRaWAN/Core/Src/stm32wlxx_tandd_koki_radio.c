/**
  ******************************************************************************
  * @file    stm32wlxx_tandd_radio.c
  * @author  MCD Application Team
  * @brief   This file provides set of firmware functions to manage:
  *          - RF circuitry available on STM32WLXX-Nucleo
  *            Kit from STMicroelectronics
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "_td_config.h" 
#if CONFIG_THIS_BOARD_IS_TandD

#include "stm32wlxx_tandd_koki_radio.h"
#include "radio_board_if.h" 

#include "td_defs.h" 

#include "radio_driver.h" //REG_XTA_TRIM

#define RF_SW_CTRL_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE
/* from main.h
//GLOBALS
#define RF_SW_CTRL_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE
// from main #define RF_SW_CTRL_Pin GPIO_PIN_0
#define RF_SW_CTRL_GPIO_Port GPIOB

// #define RF_SW_CTRL_Pin LL_GPIO_PIN_0
// #define RF_SW_CTRL_GPIO_Port GPIOB
#define RF_SW_CTRL_Pin LL_GPIO_PIN_0
#define RF_SW_CTRL_GPIO_Port GPIOB
*/


/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32WLXX_NUCLEO
  * @{
  */

/** @addtogroup STM32WLXX_NUCLEO_RADIO_LOW_LEVEL
  * @brief This file provides set of firmware functions to Radio switch 
  *        available on STM32WLXX-Nucleo Kit from STMicroelectronics.
  * @{
  */

/** @addtogroup STM32WLXX_NUCLEO_RADIO_LOW_LEVEL_Exported_Functions
  * @{
  */
  
/**
  * @brief  Init Radio Switch 
  * @retval BSP status
  */
int32_t BSP_RADIO_Init(void)
{
#if 0 // NUCLEO
  GPIO_InitTypeDef  gpio_init_structure = {0};
  
  /* Enable the Radio Switch Clock */
  RF_SW_CTRL3_GPIO_CLK_ENABLE();
  
  /* Configure the Radio Switch pin */
  gpio_init_structure.Pin   = RF_SW_CTRL1_PIN;
  gpio_init_structure.Mode  = GPIO_MODE_OUTPUT_PP;
  gpio_init_structure.Pull  = GPIO_NOPULL;
  gpio_init_structure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  
  HAL_GPIO_Init(RF_SW_CTRL1_GPIO_PORT, &gpio_init_structure);
  
  gpio_init_structure.Pin = RF_SW_CTRL2_PIN;
  HAL_GPIO_Init(RF_SW_CTRL2_GPIO_PORT, &gpio_init_structure);
  
  gpio_init_structure.Pin = RF_SW_CTRL3_PIN;
  HAL_GPIO_Init(RF_SW_CTRL3_GPIO_PORT, &gpio_init_structure);

  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET); 
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET); 
  HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET); 

  return BSP_ERROR_NONE;
#endif
Printf("BSP_RADIO_Init\r\n");
    GPIO_InitTypeDef  GPIO_InitStruct = { 0 };
 
    RF_SW_CTRL_CLK_ENABLE();

    /* Configure the Radio Switch pin */
    GPIO_InitStruct.Pin = RF_SW_CTRL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(RF_SW_CTRL_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(RF_SW_CTRL_GPIO_Port, RF_SW_CTRL_Pin, GPIO_PIN_RESET);

//karel
        SUBGRF_WriteRegister( REG_XTA_TRIM, 0x10 ); //karel
        SUBGRF_WriteRegister( REG_XTB_TRIM, 0x10 ); //karel


    return BSP_ERROR_NONE;
}

/**
  * @brief  DeInit Radio Switch
  * @retval BSP status
  */
int32_t BSP_RADIO_DeInit(void)
{
#if 0 // NUCLEO
  RF_SW_CTRL3_GPIO_CLK_ENABLE();

  /* Turn off switch */
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET); 
  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET); 
  HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET); 
  
  /* DeInit the Radio Switch pin */
  HAL_GPIO_DeInit(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN);

  return BSP_ERROR_NONE;
#endif

    GPIO_InitTypeDef  GPIO_InitStruct = { 0 };
 
    RF_SW_CTRL_CLK_ENABLE();

    /* Configure the Radio Switch pin */
    GPIO_InitStruct.Pin = RF_SW_CTRL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(RF_SW_CTRL_GPIO_Port, &GPIO_InitStruct);

    HAL_GPIO_WritePin(RF_SW_CTRL_GPIO_Port, RF_SW_CTRL_Pin, GPIO_PIN_RESET);

    return BSP_ERROR_NONE;
}

/**
  * @brief  Configure Radio Switch.
  * @param  Config: Specifies the Radio RF switch path to be set. 
  *         This parameter can be one of following parameters:
  *           @arg RADIO_SWITCH_OFF
  *           @arg RADIO_SWITCH_RX
  *           @arg RADIO_SWITCH_RFO_LP
  *           @arg RADIO_SWITCH_RFO_HP
  * @retval BSP status
  */
int32_t BSP_RADIO_ConfigRFSwitch(BSP_RADIO_Switch_TypeDef Config)
{
#if 0 // NUCLEO
  switch (Config)
  {
    case RADIO_SWITCH_OFF:
    {
      /* Turn off switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
      break;      
    }
    case RADIO_SWITCH_RX:
    {
      /*Turns On in Rx Mode the RF Switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET); 
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET); 
      break;
    }
    case RADIO_SWITCH_RFO_LP:
    {
      /*Turns On in Tx Low Power the RF Switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET); 
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET); 
      break;
    }
    case RADIO_SWITCH_RFO_HP:
    {
      /*Turns On in Tx High Power the RF Switch */
      HAL_GPIO_WritePin(RF_SW_CTRL3_GPIO_PORT, RF_SW_CTRL3_PIN, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET); 
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET); 
      break;
    }
    default:
      break;    
  }  

  return BSP_ERROR_NONE;
#endif
//Printf("BSP_RADIO_ConfigRFSwitch\r\n");
    switch (Config)
    {
    case RADIO_SWITCH_OFF: //RBI_SWITCH_OFF:
    {
        /* Turn off switch */
        Printf("[>> OFF: ]");
        HAL_GPIO_WritePin(RF_SW_CTRL_GPIO_Port, RF_SW_CTRL_Pin, GPIO_PIN_RESET); // LOW SWITCH==RX
        break;
    }
    case RADIO_SWITCH_RX: //RBI_SWITCH_RX:
    {
        /*Turns On in Rx Mode the RF Switch */
        Printf("[>> RX]: ");
        HAL_GPIO_WritePin(RF_SW_CTRL_GPIO_Port, RF_SW_CTRL_Pin, GPIO_PIN_RESET); // LOW SWITCH==RX
        break;
    }
    case RADIO_SWITCH_RFO_LP: //RBI_SWITCH_RFO_LP:
    {
        /*Turns On in Tx Low Power the RF Switch */
        Printf("[>> LP]: ");
        HAL_GPIO_WritePin(RF_SW_CTRL_GPIO_Port, RF_SW_CTRL_Pin, GPIO_PIN_SET); // HIGH SWITCH==TX
        // NO LOW/HIGH POWER SWITCH - Only LOW POWER OUTPUT IS CONNECTED
        break;
    }
    case RADIO_SWITCH_RFO_HP: //RBI_SWITCH_RFO_HP:
    {
        /*Turns On in Tx High Power the RF Switch */
        Printf("[>> HP]: ");
        HAL_GPIO_WritePin(RF_SW_CTRL_GPIO_Port, RF_SW_CTRL_Pin, GPIO_PIN_SET); // HIGH SWITCH==TX
        // NO LOW/HIGH POWER SWITCH - Only LOW POWER OUTPUT IS CONNECTED
        break;
    }
    default:
        PrintDbg(TD_ERROR, "[>> ERROR]\r\n");
        break;
    }
    return BSP_ERROR_NONE;
}

/**
  * @brief  Return Board Configuration
  * @retval 
  *  RADIO_CONF_RFO_LP_HP
  *  RADIO_CONF_RFO_LP
  *  RADIO_CONF_RFO_HP
  */
int32_t BSP_RADIO_GetTxConfig(void)
{
#if 0 // NUCLEO
  return RADIO_CONF_RFO_LP_HP;
#endif
  return RADIO_CONF_RFO_LP;
}

/**
  * @brief  Get If TCXO is to be present on board
  * @note   never remove called by MW,
  * @retval
  *  RADIO_CONF_TCXO_NOT_SUPPORTED
  *  RADIO_CONF_TCXO_SUPPORTED
  */
int32_t BSP_RADIO_IsTCXO(void)
{
#if 0 // NUCLEO
  return RADIO_CONF_TCXO_SUPPORTED;
#endif
//  return IS_TCXO_SUPPORTED;
//  return RADIO_CONF_TCXO_SUPPORTED;
    return RADIO_CONF_TCXO_NOT_SUPPORTED;
}

/**
  * @brief  Get If DCDC is to be present on board
  * @note   never remove called by MW,
  * @retval
  *  RADIO_CONF_DCDC_NOT_SUPPORTED
  *  RADIO_CONF_DCDC_SUPPORTED  
  */
int32_t BSP_RADIO_IsDCDC(void)
{
#if 0 // NUCLEO
  return RADIO_CONF_DCDC_SUPPORTED;
#endif
  return RADIO_CONF_DCDC_SUPPORTED;
}

/**
  * @brief  Return RF Output Max Power Configuration
  * @retval
  *    RADIO_CONF_RFO_LP_MAX_15_dBm for LP mode
  *    RADIO_CONF_RFO_HP_MAX_22_dBm for HP mode
  */
int32_t BSP_RADIO_GetRFOMaxPowerConfig(BSP_RADIO_RFOMaxPowerConfig_TypeDef Config)
{
#if 0 // NUCLEO
  int32_t ret;

  if(Config == RADIO_RFO_LP_MAXPOWER)
  {
    ret = RADIO_CONF_RFO_LP_MAX_15_dBm;
  }
  else
  {
    ret = RADIO_CONF_RFO_HP_MAX_22_dBm;
  }

  return ret;
#endif
  int32_t ret;

  if(Config == RADIO_RFO_LP_MAXPOWER)
  {
    ret = RADIO_CONF_RFO_LP_MAX_15_dBm;
  }
  else
  {
    ret = RADIO_CONF_RFO_HP_MAX_22_dBm;
  }

  return ret;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif //CONFIG_THIS_BOARD_IS_TandD

