#include <ihashi.h>

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int IhashiPrintfClr(
    unsigned int clr, const char* fmt, ...
) {

    va_list args;
    va_start(args, fmt);

    int len = vsnprintf(NULL, 0, fmt, args);
    
    if (len < 0)
        return len;

    IhashiSetClr(clr);

    len += 2;
    char* buf = (char*)malloc(len * sizeof(char));
    va_start(args, fmt); // hope this doesnt break
    vsnprintf(buf, len, fmt, args);
    fputs(buf, stdout);

    va_end(args);

    IhashiResetClr();

    return len;
}

int IhashiPrintfClrMax(
    unsigned int clr, const char* fmt, ...
) {

    va_list args;
    va_start(args, fmt);

    int len = vsnprintf(NULL, 0, fmt, args);
    
    if (len < 0)
        return len;

    IhashiSetClrMax(clr);
    
    len += 2;
    char* buf = (char*)malloc(len * sizeof(char));
    va_start(args, fmt); // hope this doesnt break
    vsnprintf(buf, len, fmt, args);
    fputs(buf, stdout);

    va_end(args);

    IhashiResetClr();

    return len;
}