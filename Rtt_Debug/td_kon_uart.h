/*
 * td_kon_uart.h
 *
 *  Created on: Nov 26, 2025
 *      Author: karel.seeuwen
 */

#ifndef TD_KON_UART_H_
#define TD_KON_UART_H_

#include "_td_config.h"

#if CONFIG_USE_TD_KON_UART

#include "stdint.h"
#include "stdbool.h"

#undef EDF

#ifdef _TD_KON_UART_C_
#define EDF
#else
#define EDF extern
#endif


#define TD_NORM  0
#define TD_EVENT 1
#define TD_INFO  2
#define TD_DEBUG 3
#define TD_WARN  4
#define TD_ERROR 5
#define TD_PINK  6


void Printf_StartUp(void);
void Printf_Shutdown(void);

#if 0
int Printf(const char *fmt, ... );
#else
#include "stm32_adv_trace.h"
#include "utilities_conf.h"
UTIL_ADV_TRACE_Status_t UTIL_ADV_TRACE_COND_FSend(uint32_t VerboseLevel, uint32_t Region, uint32_t TimeStampState, const char *strFormat, ...);
#define Printf(...) do{ {UTIL_ADV_TRACE_COND_FSend(VLEVEL_ALWAYS, T_REG_OFF, TS_OFF, __VA_ARGS__);} }while(0);
#endif

int PrintDbg(int TYPE, const char *format, ...);
int PrintHex( char* banner, uint8_t* pData, int len);

#endif // CONFIG_USE_TD_KON_UART


#endif /* TD_KON_UART_H_ */
