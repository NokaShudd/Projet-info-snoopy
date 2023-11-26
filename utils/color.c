#include <stdio.h>
#include <stdarg.h>

#ifdef _WIN32

#include <windows.h>

#else

#include <string.h>

#endif

#include "color.h"


#ifdef _WIN32

// transforme une couleur en 'code couleur' 
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
        case white:
            return isBackground ? 0x70 : 0x7;
        case black:
            return 0x0;

        default :
            return 0x0;
    }
}

#else 

char* getColorNumber(int color, int isBackground){
    switch(color){
        case balck:     return isBackground ? "40" : "30";
        case red:       return isBackground ? "41" : "31";
        case green:     return isBackground ? "42" : "32";
        case yellow:    return isBackground ? "43" : "33";
        case blue:      return isBackground ? "44" : "34";
        case magenta:   return isBackground ? "45" : "35";
        case cyan:      return isBackground ? "46" : "36";
        default:        return isBackground ? "47" : "37";
    }
}

char* stringFromAttr(wTxtAtt attr){
    char* str = "\x1b[";

    strcat(str, getColorNumber(attr.fColor, 0));
    strcat(str, ";");
    strcat(str, getColorNumber(attr.bColor, 1));

    // TODO implémenter souligner et intensité


    return str;
}

#endif

// génère un nouvel attribut couleur
wTxtAtt newAttr(int fColor, int bColor){
    wTxtAtt attr = {
        fColor, bColor, 0, 0, 0
    };
    return attr;
}

// écrit sur la console en couleur
int colorPrintf(wTxtAtt attr, char* format, ...){
    char buffer[256];
    va_list args;
    va_start (args, format);
    vsprintf (buffer,format, args);

    #ifdef _WIN32

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

    #else

    printf(stringFromAttr(attr));

    #endif
    
    printf(buffer);
    va_end (args);

    #ifdef _WIN32

    SetConsoleTextAttribute(
        hndl,
        oldAttribute
    );

    #else 

    printf("\x1b[37m");

    #endif

    return 0;
}
