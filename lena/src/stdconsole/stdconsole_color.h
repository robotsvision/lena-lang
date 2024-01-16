#ifndef __LENA_STDCONSOLE_COLOR_H__
#define __LENA_STDCONSOLE_COLOR_H__

/**************************************************************************//**
 * @file     stdconsole_color.h
 * @brief    Project L - Lena programming language stdconsole_color
 * @version  V0.0.1
 * @date     6. Jan 2024
 ******************************************************************************/

#include "ltypes/ltypes.h"
#include "stdconsole.h"

#include <stdbool.h>

#ifdef _WIN32
#include <windows.h>
#else
#endif 

/* lena_stdcolor_t */

typedef enum {
#ifdef _WIN32
    LENA_TEXT_COLOR     = 0x0F,
    LENA_ERROR_COLOR    = FOREGROUND_RED    | FOREGROUND_INTENSITY,
    LENA_WARNING_COLOR  = FOREGROUND_RED    | FOREGROUND_GREEN,
    LENA_INFO_COLOR     = FOREGROUND_BLUE   | FOREGROUND_INTENSITY,
    LENA_HELP_COLOR     = FOREGROUND_GREEN  | FOREGROUND_INTENSITY,
    LENA_LABEL_COLOR    = FOREGROUND_BLUE   | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
#else
    LENA_TEXT_COLOR     = 8,
    LENA_ERROR_COLOR    = 1,
    LENA_WARNING_COLOR  = 3,
    LENA_INFO_COLOR     = 4,
    LENA_HELP_COLOR     = 2,
    LENA_LABEL_COLOR    = 7,
#endif 
} lena_stdcolor_t;


#ifdef _WIN32


void lstdout_set_color(lena_stdcolor_t color);


void lstderr_set_color(lena_stdcolor_t color);

#else /* UNIX */


/* Lenght of l("\x1b[3Xm") */
#define __LSTDCONSOLE_CODE_LENGHT 6



void lstdout_set_color(lena_stdcolor_t color);


void lstderr_set_color(lena_stdcolor_t color);

#endif 

#endif // __LENA_STDCONSOLE_COLOR_H__