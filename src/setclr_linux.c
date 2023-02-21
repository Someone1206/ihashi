#include <ihashi.h>
#include "privInc/idefs.h"

#if !defined(_WIN32)

void __ihashi_setclr_linux(unsigned int clr)
{
    unsigned char i = 2;
    unsigned int clr_part = clr >> 24; // text mode

    SET_CODE_AT(i++, (clr_part + '0'));

    /*
    clr_part = clr & 0xff000000; // text mode
    switch (clr_part) {
    case IFG_NORMAL:
        SET_CODE_AT(i++, '0');
        break;
    case IFG_BOLD:
        SET_CODE_AT(i++, '1');
        break;
    case IFG_FAINT:
        SET_CODE_AT(i++, '2');
        break;
    case IFG_ITALICS:
        SET_CODE_AT(i++, '3');
        break;
    case IFG_UNDERLINE:
        SET_CODE_AT(i++, '4');
        break;
    }
    why this?
    */

    clr_part = clr & 0xff; // fg

    if (clr_part)
        SET_CODE_AT(i++, ';');

    if ((clr & IFG_GREY) == IFG_GREY) {
        SET_CODE_AT(i++, '9');
        SET_CODE_AT(i++, '0');
    }
    else {
        if ((clr & IFG_INTENSE) == IFG_INTENSE) {
            SET_CODE_AT(i++, '9');
        }
        else if (clr_part) {
            SET_CODE_AT(i++, '3');
        }

        switch (clr_part) {
        case IFG_BLUE:
            SET_CODE_AT(i++, '4');
            break;
        case IFG_GREEN:
            SET_CODE_AT(i++, '2');
            break;
        case IFG_RED:
            SET_CODE_AT(i++, '1');
            break;
        case IFG_CYAN:
            SET_CODE_AT(i++, '6');
            break;
        case IFG_MAGENTA:
            SET_CODE_AT(i++, '5');
            break;
        case IFG_YELLOW:
            SET_CODE_AT(i++, '3');
            break;
        case IFG_WHITE:
            SET_CODE_AT(i++, '7');
            break;
        case IFG_BLACK:
            SET_CODE_AT(i++, '0');
        }
    }

    clr_part = clr & 0x00ff0000; // bg
    if (clr_part)
        SET_CODE_AT(i++, ';');

    if ((clr & IBG_GREY) == IBG_GREY) {
        SET_CODE_AT(i++, '1');
        SET_CODE_AT(i++, '0');
        SET_CODE_AT(i++, '0');
    }
    else {
        if ((clr & IBG_INTENSE) == IBG_INTENSE) {
            SET_CODE_AT(i++, '1');
            SET_CODE_AT(i++, '0');
        }
        else if (clr_part) {
            SET_CODE_AT(i++, '4');
        }


        switch (clr_part) {
        case IBG_BLUE:
            SET_CODE_AT(i++, '4');
            break;
        case IBG_GREEN:
            SET_CODE_AT(i++, '2');
            break;
        case IBG_RED:
            SET_CODE_AT(i++, '1');
            break;
        case IBG_CYAN:
            SET_CODE_AT(i++, '6');
            break;
        case IBG_MAGENTA:
            SET_CODE_AT(i++, '5');
            break;
        case IBG_YELLOW:
            SET_CODE_AT(i++, '3');
            break;
        case IBG_WHITE:
            SET_CODE_AT(i++, '7');
            break;
        case IBG_BLACK:
            SET_CODE_AT(i++, '0');
            break;
        }
    }

    SET_CODE_AT(i++, 'm');
    SET_CODE_AT(i, 0);
}


#endif // !_WIN32