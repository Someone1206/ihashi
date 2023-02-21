#if !defined(IHASHI_DEFS)
#define IHASHI_DEFS

#if defined(_WIN32)

#include <Windows.h>
extern HANDLE ihashiConsoleHandle;
extern DWORD  ihashiConsoleState;

#else

#include <stdio.h>
extern char ihashiClrCode[20];
#define SET_CODE_AT(i, c) ihashiClrCode[i] = c

#endif // _WIN32


#endif // IHASHI_DEFS
