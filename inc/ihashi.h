#if !defined(IHASHI_H)
#define IHASHI_H

#define IFG_RESET               (0xffffffff)

#define IFG


int IhashiInit();

#if (defined(__APPLE__) && defined(__MACH__)) || defined(Macintosh) || defined(macintosh)
#error "Ihashi hasn't yet been configured for mac os..."
#endif



#if defined(IHASHI_PLATFORM_OPTIMISE)

#if defined(_WIN32)

#include <Windows.h>
extern HANDLE ihashiConsoleHandle;
extern DWORD  ihashiConsoleState;

#else

extern char ihashiClrCode[20];

#endif // _WIN32

#endif // IHASHI_PLATFORM_OPTIMISE


#if defined(IHASHI_PLATFORM_MAX)

// use the maximum capabilities of the platform available

#endif // IHASHI_PLATFORM_MAX



#endif // !IHASHI_H
