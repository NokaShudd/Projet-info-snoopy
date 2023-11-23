#include <stdio.h>
#include <stdarg.h>
#include "color.h"

// Fait a partir de https://cplusplus.com/reference/cstdio/vsprintf/
int colorPrintf(char colorP[8], char* format, ...){
    char buffer[256];
    va_list args;
    va_start (args, format);
    vsprintf (buffer,format, args);
    printf(colorP);
    printf(buffer);
    printf(White);
    va_end (args);

    return 0;
}


int humanColorTest(){
    char rep = 'o';

    printf("Ce texte est-il en rouge ? :\n");
    printf(Red "lorem ipsum\n" White);
    printf("\n('n' = non, defaut : oui)");

    scanf("%c", &rep);

    return (rep != 'n');
}