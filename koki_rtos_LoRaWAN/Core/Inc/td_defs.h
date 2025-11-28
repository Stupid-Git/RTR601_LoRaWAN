/*
 * td_defs.h
 *
 *  Created on: Nov 25, 2025
 *      Author: karel.seeuwen
 */

#ifndef TD_DEFS_H_
#define TD_DEFS_H_

#include "stdint.h"
#include "stdbool.h"
#include "string.h"

#include "time.h"

//TODO ? #include "td_debug.h"

#if CONFIG_USE_TD_KON_UART
#include "td_kon_uart.h"
#endif
#if CONFIG_USE_TD_KON_RTT
#include "td_kon_rtt.h"
#endif
#if CONFIG_USE_TD_KON_STUB
#include "td_kon_stub.h"
#endif




#endif /* TD_DEFS_H_ */
