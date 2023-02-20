#if !defined(IHASHI_H)
#define IHASHI_H

#define IFG_INTENSE             (0x00000800)
#define IBG_INTENSE             (0x00008000)

#define IFG_BLUE                (0x00000001)
#define IFG_GREEN               (0x00000002)
#define IFG_RED                 (0x00000004)

#define IFG_BLUE_GREEN          (IFG_BLUE | IFG_GREEN)
#define IFG_CYAN                (IFG_BLUE_GREEN)

#define IFG_PURPLE              (IFG_BLUE | IFG_RED)
#define IFG_MAGENTA             (IFG_PURPLE)
#define IFG_YELLOW              (IFG_RED | IFG_GREEN)

#define IFG_WHITE               (IFG_RED | IFG_BLUE | IFG_GREEN)

#define IFG_GREY                (0x00000400)
#define IFG_GRAY                (IFG_GREY)


#define IBG_BLUE                (0x00010000)
#define IBG_GREEN               (0x00020000)
#define IBG_RED                 (0x00040000)

#define IBG_BLUE_GREEN          (IBG_BLUE | IBG_GREEN)
#define IBG_CYAN                (IBG_BLUE_GREEN)

#define IBG_PURPLE              (IBG_BLUE | IBG_RED)
#define IBG_MAGENTA             (IBG_PURPLE)
#define IBG_YELLOW              (IBG_RED | IBG_GREEN)

#define IBG_WHITE               (IBG_RED | IBG_BLUE | IBG_GREEN)

#define IBG_GREY                (0x00002000)
#define IBG_GRAY                (IBG_GREY)

#if (defined(__APPLE__) && defined(__MACH__)) || defined(Macintosh) || defined(macintosh)
#error "Ihashi hasn't yet been configured for mac os..."
#endif


int IhashiInit();

int IhashiSetClr(unsigned int clr);

int IhashiResetClr();

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
