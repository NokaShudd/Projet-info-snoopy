#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "color.h"


WORD wFromColor(int color, short isBackground){
    switch (color){
        case red:
            return isBackground ? 0x40 : 0x4;
        case green:
            return isBackground ? 0x20 : 0x2;
        case blue:
            return isBackground ? 0x10 : 0x1;
        case yellow:
            return isBackground ? 0x60 : 0x6;
        case cyan:
            return isBackground ? 0x30 : 0x3;
        case magenta:
            return isBackground ? 0x50 : 0x5;
        case black:
            return isBackground ? 0x70 : 0x7;
        case white:
            return 0x0;

        default :
            return 0x0;
    }
}

wTxtAtt newAttr(int fColor, int bColor){
    wTxtAtt attr = {
        fColor, bColor, 0, 0, 0
    };
    return attr;
}

int colorPrintf(wTxtAtt attr, char* format, ...){
    char buffer[256];
    va_list args;
    va_start (args, format);
    vsprintf (buffer,format, args);

    HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD oldAttribute;

    GetConsoleScreenBufferInfo(hndl, &consoleInfo);
    oldAttribute = consoleInfo.wAttributes;


    WORD newAtt = 0;

    newAtt += wFromColor(attr.fColors, 0);
    newAtt += wFromColor(attr.bColors, 1);

    newAtt += (attr.fInt)       ? FOREGROUND_INTENSITY  : 0x0;
    newAtt += (attr.bInt)       ? BACKGROUND_INTENSITY  : 0x0;
    newAtt += (attr.underscore) ? COMMON_LVB_UNDERSCORE : 0x0;


    SetConsoleTextAttribute(
        hndl,
        newAtt
    );
    
    printf(buffer);
    va_end (args);

    SetConsoleTextAttribute(
        hndl,
        oldAttribute
    );
    
    return 0;
}
