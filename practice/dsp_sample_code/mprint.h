/*******************************************************************************
 * @file    mprint.h
 * @brief   Base macros for printing in an embedded system
 * @author  Jacob Huesman
 *  ******************************************************************************/

#ifndef MPRINT_H
#define MPRINT_H

#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_RESET   "\x1b[0m"

// Print Macros (Can handle up to ten arguments)
#define GET_PRINT_VERSION(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define PRINT(HEADER, ...) GET_PRINT_VERSION(__VA_ARGS__, PRINTN, PRINTN, PRINTN, \
		                                                  PRINTN, PRINTN, PRINTN, \
										         	      PRINTN, PRINTN, PRINTN, \
										            	  PRINT1)(HEADER, __VA_ARGS__)

// Only define if enabled
#if defined(MPRINT_ENABLE) && (MPRINT_ENABLE == 1)

#define PRINT1(HEADER, FORMAT)      PRINTF(HEADER FORMAT "\n")
#define PRINTN(HEADER, FORMAT, ...) PRINTF(HEADER FORMAT "\n", __VA_ARGS__)
#define SPACE(...) PRINTF("\n")

#else

// Define but do nothing
#define PRINT1(HEADER, FORMAT)
#define PRINTN(HEADER, FORMAT, ...)
#define SPACE(...)

#endif

#endif // MPRINT_H