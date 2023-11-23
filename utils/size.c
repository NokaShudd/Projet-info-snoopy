#include <windows.h>
#include <stdio.h>
#include "size.h"


// fait a partir de https://stackoverflow.com/a/12642749
int getSize(int sizes[2]) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    sizes[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    sizes[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return sizes[0]/sizes[1];
}

int horribleGotoXY(int x, int y){
    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &coninfo);
    coninfo.dwCursorPosition.Y = y;
    coninfo.dwCursorPosition.X = x;
    SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);
}

int humanSizeTest(){
    char rep = 'o';
    int sizes[2];

    getSize(sizes);

    printf("#");
    for (int i = 0; i < sizes[0]-2; i++){
        printf("=");
    }
    printf(">\n");

    for (int i = 0; i < sizes[1]-2; i++){
        printf("|");

        if (sizes[0] >= 34){
            if (i == sizes[1] / 2 - 1){
                printf("   Est-ce de la bonne taille ?");
            } else if (i == sizes[1] / 2 ){
                printf("   ('n' = non, defaut = oui)");
            } else if (i == sizes[1] / 2 + 1){
                printf("   (ou redim. la fenetre)");
            }
        }
        printf("\n");
    }

    printf("v");

    if (sizes[0] >= 34){
        printf("    ");
        scanf("%c", &rep);
    } else {
        printf("\nLes fleches sont-elles de la bonne taille ? \n('n' = non, défaut : oui) ");
        scanf("%c", &rep);    
    }
    
    return (rep != 'n'); 
}