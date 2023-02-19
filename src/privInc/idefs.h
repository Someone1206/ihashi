#if !defined(IHASHI_DEFS)
#define IHASHI_DEFS

#if defined(_WIN32)

#include <Windows.h>
extern HANDLE ihashiConsoleHandle;
extern DWORD  ihashiConsoleState;

#else

extern char ihashiClrCode[20];

#endif // _WIN32


#endif // IHASHI_DEFS
