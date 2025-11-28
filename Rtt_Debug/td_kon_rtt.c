#include "_td_config.h"

#if CONFIG_USE_TD_KON_RTT

#define _TD_KON_RTT_C_
#include "td_kon_rtt.h"

#include "td_defs.h"

#include "string.h" // strcpy, strlen



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void Printf_StartUp(void)
{
  //SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
    SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_NO_BLOCK_TRIM); // OK for when No RTT server running
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void Printf_Shutdown(void)
{
#if 0    //TODO
    SEGGER_RTT_BUFFER_UP *pRing;
    pRing = &_SEGGER_RTT.aUp[0/*BufferIndex*/];
    while (pRing->WrOff != pRing->RdOff)
    {
        tx_thread_sleep (1);
    }
#endif
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
int Printf(const char *format, ... )
{
    int r;
    unsigned int BufferIndex = 0;
    va_list ParamList;
    va_start(ParamList, format);
    r = SEGGER_RTT_vprintf(BufferIndex, format, &ParamList);
    va_end(ParamList);
    return r;
}



//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
static int _printfType (int TYPE);
static int _printfType (int TYPE)
{
    int done;
    char _buffer[20];
    switch(TYPE)
    {
#if 1 //Segger https://en.wikipedia.org/wiki/ANSI_escape_code#CSI_(Control_Sequence_Introducer)_sequences
        case TD_EVENT:
            strcpy(_buffer, "\x1b[42m");    // Bright Green
            break;
        case TD_INFO:
            strcpy(_buffer, "\x1b[46m");    // Bright Light Blue (Cyan)
            break;
        case TD_DEBUG:
            strcpy(_buffer, "\x1b[44m");    // Blue
            break;
        case TD_WARN:
            strcpy(_buffer, "\x1b[43m");    // Bright Yellow
            break;
        case TD_ERROR:
            strcpy(_buffer, "\x1b[41m");    // Bright Red
            break;
        case TD_PINK:
            strcpy(_buffer, "\x1b[45m");    // Magenta
            break;
        default:
            strcpy(_buffer, "\x1b[0m");     // BG-Black FG-White
            break;
#else
        case TD_EVENT:
            strcpy(_buffer, "\x1b[38;5;10m"); //10 Bright Green
            break;
        case TD_INFO:
            strcpy(_buffer, "\x1b[38;5;14m"); //14 Bright Light Blue (Cyan)
            break;
        case TD_DEBUG:
            strcpy(_buffer, "\x1b[38;5;12m"); //12 Purple
            break;
        case TD_WARN:
            strcpy(_buffer, "\x1b[38;5;11m"); //11 Bright Yellow
            break;
        case TD_ERROR:
            strcpy(_buffer, "\x1b[38;5;9m"); //9 Bright Red
            break;
        default:
            strcpy(_buffer, "\x1b[38;5;15m"); //15 Bright White
            break;
#endif
    }
    if(strlen( _buffer) != 0 )
    {
        Printf( _buffer );
    }
    done = 0;
    return done;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#define USE_TYPE_IN_PRINT 1
int PrintDbg(int TYPE, const char *format, ...)
{

#if USE_TYPE_IN_PRINT    // just treat as same as Printf
    _printfType(TYPE);
#else
    (void)(TYPE);
#endif

    int r = 0;
    unsigned int BufferIndex = 0;
    va_list ParamList;
    va_start(ParamList, format);
    r = SEGGER_RTT_vprintf(BufferIndex, format, &ParamList);
    va_end(ParamList);

#if USE_TYPE_IN_PRINT    // just treat as same as Printf
    _printfType(TD_NORM);
#endif

    return r;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
static void DumpHex(int addText, const void* data, size_t size);
static void DumpHex(int addText, const void* data, size_t size)
{
    char ascii[17];
    size_t i, j;
    ascii[16] = '\0';
    for (i = 0; i < size; ++i) {
        Printf("%02X ", ((unsigned char*)data)[i]);
        if(addText != 0)
        {
            if (((unsigned char *) data)[i] >= ' ' && ((unsigned char *) data)[i] <= '~')
            {
                ascii[i % 16] = ((unsigned char *) data)[i];
            }
            else
            {
                ascii[i % 16] = '.';
            }
            if ((i + 1) % 8 == 0 || i + 1 == size)
            {
                Printf (" ");
                if ((i + 1) % 16 == 0)
                {
                    Printf ("|  %s \r\n", ascii);
                }
                else if (i + 1 == size)
                {
                    ascii[(i + 1) % 16] = '\0';
                    if ((i + 1) % 16 <= 8)
                    {
                        Printf (" ");
                    }
                    for (j = (i + 1) % 16; j < 16; ++j)
                    {
                        Printf ("   ");
                    }
                    Printf ("|  %s \r\n", ascii);
                }
            }
        }
    }
    if(addText == 0)
    {
        Printf("\r\n");
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
int PrintHex( char* banner, uint8_t* pData, int len)
{
    int r = 0;
    
    Printf("%s\r\n", banner);
    DumpHex( 1, pData, (size_t)len);
    
    return r;
}



#endif


