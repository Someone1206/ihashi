#include <ihashi.h>

#include <stdio.h>

int IhashiPrintClr(unsigned int clr, const char* str)
{
    IhashiSetClr(clr);

    int rv = fputs(str, stdout);

    IhashiResetClr();

    return rv;
}

int IhashiPrintClrMax(unsigned int clr, const char* str)
{
    IhashiSetClrMax(clr);

    int rv = fputs(str, stdout);

    IhashiResetClr();

    return rv;
}