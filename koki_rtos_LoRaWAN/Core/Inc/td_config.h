/*
 * td_config.h
 *
 *  Created on: Nov 25, 2025
 *      Author: karel.seeuwen
 */

#ifndef TD_CONFIG_H_
#define TD_CONFIG_H_

#define CONFIG_THIS_BOARD_IS_TandD	1

#define CONFIG_THIS_BOARD_IS_RX 	0

#if CONFIG_THIS_BOARD_IS_RX
//#define USE_THIS_RX_SP  7
//#define USE_THIS_RX_SP  8
//#define USE_THIS_RX_SP  9
#define USE_THIS_RX_SP  12
#endif

#define CONFIG_USE_TX_RSP			1

//##### KON ##### KON ##### KON ##### KON ##### KON ##### KON ##### KON #####
#define _DEBUG 1

#ifdef _DEBUG
#define CONFIG_USE_TD_KON_UART          0
#define CONFIG_USE_TD_KON_RTT           1
#define CONFIG_USE_TD_KON_STUB          0
#else
#define CONFIG_USE_TD_KON_STUB          1
#endif
//##### KON ##### KON ##### KON ##### KON ##### KON ##### KON ##### KON #####


#endif /* TD_CONFIG_H_ */
