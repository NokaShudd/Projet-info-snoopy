#include <stdio.h>
#include <windows.h>
#include "size.h"

void setTitle(){
    SetConsoleTitleA(
        "Snoppy"
    );
}


// fait a partir de https://stackoverflow.com/a/12642749 (windows)
// et https://stackoverflow.com/a/1022961 (macos / linux)
// récupère la taille de la console et l'écrit dans size (size[0] = largeur, size[1] = hauteur)
int getSize(int size[2]) {
    
    #ifdef _WIN32    

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    size[0] = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    size[1] = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    #else 

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    size[0] = w.ws_row;
    size[0] = w.ws_col;

    #endif

    return size[0]/size[1];
}

// positionne le curseur au points (x, y) dans la console
int gotoXY(int x, int y){
    
    #ifdef _WIN32

    CONSOLE_SCREEN_BUFFER_INFO coninfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &coninfo);
    coninfo.dwCursorPosition.Y = y;
    coninfo.dwCursorPosition.X = x;
    SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);

    #else 

    initscr();

    move(x, y);

    refresh();

    #endif

    return 0;
}
