#if !defined(IHASHI_H)
#define IHASHI_H

#if defined(__cplusplus)

extern "C" {

#endif // __cplusplus


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
#define IFG_BLACK               (0x00000008)

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
#define IBG_BLACK               (0x00080000)

#define IBG_GREY                (0x00002000)
#define IBG_GRAY                (IBG_GREY)


#define IFG_NORMAL              (0x00000000)
#define IFG_BOLD                (0x01000000)
#define IFG_FAINT               (0x02000000)
#define IFG_ITALICS             (0x03000000)
#define IFG_UNDERLINE           (0x04000000)
#define IFG_UNDERLINED          (IFG_UNDERLINE)


#define IFG_CLR_NORM            (0x40000000)
#define IBG_CLR_NORM            (0x80000000)
#define ICLR_NORMAL             (IFG_CLR_NORM | IBG_CLR_NORM)


#if (defined(__APPLE__) && defined(__MACH__)) || defined(Macintosh) || defined(macintosh)
#error "Ihashi hasn't yet been configured for mac os..."
#endif


int IhashiInit();

int IhashiSetClr(unsigned int clr);

// IHASHI_PLATFORM_MAX
int IhashiSetClrMax(unsigned int clr);

int IhashiResetClr();


int IhashiPrintfClr(
    unsigned int clr, const char* fmt, ...
);

int IhashiPrintfClrMax(
    unsigned int clr, const char* fmt, ...
);

int IhashiPrintClr(unsigned int clr, const char* str);

int IhashiPrintClrMax(unsigned int clr, const char* str);

#if defined(IHASHI_PLATFORM_OPTIMISE)

#if defined(_WIN32)

#include <Windows.h>
extern HANDLE ihashiConsoleHandle;
extern DWORD  ihashiConsoleState;

#else

extern char ihashiClrCode[20];

#endif // _WIN32

#endif // IHASHI_PLATFORM_OPTIMISE


#if defined(__cplusplus)

}

#endif // __cplusplus



#endif // !IHASHI_H
