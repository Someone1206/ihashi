#include <ihashi.h>

#include "privInc/idefs.h"


int IhashiInit()
{
#if defined(_WIN32)

    ihashiConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!ihashiConsoleHandle) {
        return -1;
    }
    CONSOLE_SCREEN_BUFFER_INFO b_info;
    GetConsoleScreenBufferInfo(ihashiConsoleHandle, &b_info);
    ihashiConsoleState = b_info.wAttributes;

#else
    // nothing for linux ig...
#endif // _WIN32
}
