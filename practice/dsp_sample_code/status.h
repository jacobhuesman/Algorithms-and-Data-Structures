/*******************************************************************************
 * @file    mstatus.h
 * @brief   Common macros and functions for indicating status
 * @author  Jacob Huesman
 *  ******************************************************************************/

#ifndef MSTATUS_H
#define MSTATUS_H

#include "mprint.h"

#if defined(MPRINT_ENABLE) && (MPRINT_ENABLE == 1)

#else
#define STATUS(FNCALL) { FNCALL; }
#endif

#define INFO(...)  PRINT("[INFO] ", __VA_ARGS__);
#define WARN(...)  PRINT("[" ANSI_YELLOW "WARN" ANSI_RESET "] ", __VA_ARGS__);
#define ERROR(...) PRINT("[" ANSI_RED    "FAIL" ANSI_RESET "] ",      __VA_ARGS__);


#ifndef STATUS
#define STATUS(FNCALL)                       \
{                                            \
    if (FNCALL == kStatus_Success)           \
    {                                        \
        INFO("Call to "#FNCALL" succeeded"); \
    }                                        \
    else                                     \
    {                                        \
        ERROR("Call to "#FNCALL" failed");   \
    }                                        \
}
#endif

#endif // MSTATUS_H