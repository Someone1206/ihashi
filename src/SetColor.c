#include <ihashi.h>

#include "privInc/idefs.h"

#if defined(_WIN32)

#include <Windows.h>

#else

#include <stdio.h>

#endif // _WIN32

int IhashiSetClr(unsigned int clr)
{
#if defined(_WIN32)
    return __ihashi_setclr_win(clr);
#else

    __ihashi_setclr_linux(clr);

    SET_CODE_AT(2, '0');

    fputs(ihashiClrCode, stdout);

    return 0;
#endif // _WIN32
}

int IhashiSetClrMax(unsigned int clr)
{
#if defined(_WIN32)
    return __ihashi_setclr_win(clr);
#else

    __ihashi_setclr_linux(clr);

    fputs(ihashiClrCode, stdout);

    return 0;
#endif // _WIN32
}