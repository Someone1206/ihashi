#include <ihashi.h>

#include "privInc/idefs.h"

#include <stdio.h>

#if defined(_WIN32)

#include <Windows.h>

#else

#include <stdio.h>

#endif // _WIN32

extern char ihashiClrCode[20];
// 13 atm

char debug[100];

int IhashiSetClr(unsigned int clr)
{
#if defined(_WIN32)
    DWORD fin_clr = 0;

    if ((clr & IFG_INTENSE) == IFG_INTENSE) {
        fin_clr = FOREGROUND_INTENSITY;
    }

    if ((clr & IFG_GREY) == IFG_GREY) {
        fin_clr = FOREGROUND_INTENSITY;
    }
    else {
        fin_clr |= (clr & 0xff);
    }

    if ((clr & IBG_INTENSE) == IBG_INTENSE) {
        fin_clr |= BACKGROUND_INTENSITY;
    }

    if ((clr & IBG_GREY) == IBG_GREY) {
        fin_clr |= BACKGROUND_INTENSITY;
    }
    else {
        fin_clr |= ((clr >> 16) & 0xff);
    }

    SetConsoleTextAttribute(ihashiConsoleHandle, fin_clr);
#else


#endif // _WIN32
    return 0;
}