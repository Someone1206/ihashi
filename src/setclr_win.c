#include <ihashi.h>
#include "privInc/idefs.h"

#include <stdio.h>

#if defined(_WIN32)

int __ihashi_setclr_win(unsigned int clr)
{
    DWORD fin_clr = 0, clr_part;

    if ((clr & IFG_INTENSE) == IFG_INTENSE) {
        fin_clr = FOREGROUND_INTENSITY;
    }

    if ((clr & IFG_GREY) == IFG_GREY) {
        fin_clr = FOREGROUND_INTENSITY;
    }
    else {
        clr_part = (clr & 0xff);

        if (clr_part == IFG_BLACK)
            clr_part = 0;

        fin_clr |= clr_part;
    }

    if ((clr & IBG_INTENSE) == IBG_INTENSE) {
        fin_clr |= BACKGROUND_INTENSITY;
    }

    if ((clr & IBG_GREY) == IBG_GREY) {
        fin_clr |= BACKGROUND_INTENSITY;
    }
    else {
        clr_part = (clr & 0x00ff0000);

        if (clr_part == IBG_BLACK)
            clr_part = 0;

        fin_clr |= (clr_part >> 12);
    }

    if ((clr & IFG_CLR_NORM) == IFG_CLR_NORM) {
        fin_clr &= 0xfffffff0;
        fin_clr |= (ihashiConsoleState & 0xf);
    }

    if ((clr & IBG_CLR_NORM) == IBG_CLR_NORM) {
        fin_clr &= 0xffffff0f;
        fin_clr |= (ihashiConsoleState & 0xf0);
    }

    if (ihashiConsoleHandle == INVALID_HANDLE_VALUE)
        return -1;

    SetConsoleTextAttribute(ihashiConsoleHandle, fin_clr);

    return 0;
}

#endif // WIN32