#include "privInc/idefs.h"

#if defined(_WIN32)

#include <Windows.h>
HANDLE ihashiConsoleHandle;
DWORD  ihashiConsoleState;

#else

char ihashiClrCode[20] = {  0x1B, '[', '0', ';', 'x', 'x', ';' };

#endif // _WIN32