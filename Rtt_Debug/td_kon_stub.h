#ifndef TD_KON_STUB_H_
#define TD_KON_STUB_H_

#include "_td_config.h"

#if CONFIG_USE_TD_KON_STUB

#include "stdint.h"
#include "stdbool.h"

#undef EDF

#ifdef _TD_KON_STUB_C_
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

#define Printf_StartUp(...) 
#define Printf_Shutdown(...) 
#define Printf(...) 
#define PrintDbg(...) 
#define PrintHex(...) 


#endif // CONFIG_USE_TD_KON_STUB

#endif /* TD_KON_STUB_H_ */

