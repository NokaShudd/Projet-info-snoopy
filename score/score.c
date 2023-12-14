#include "score.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "..\utils\color.h"
#include "..\utils\sleep.h"
#include "..\utils\size.h"


DWORD WINAPI timer_score (LPVOID timeur) {
    long long * time_left = (long long *)timeur;

    wTxtAtt attr = newAttr(white, magenta);

    attr.underscore = 1;
    attr.fInt = 1;

    while (*time_left > 0) {
        *time_left = *time_left - 1;
        gotoXY(28,1);
        colorPrintf(attr," %lld ", *time_left *100);
        sleep_ms(1000);
    }
}

HANDLE Start_timer(long long * time_left){
    return CreateThread(
            NULL, 0, timer_score, (void *)time_left, 0, NULL
    );
}

void affichage_vie(int vie_restante){
    gotoXY(70,10);
    colorPrintf(newAttr(white,magenta),"%d",vie_restante);
}