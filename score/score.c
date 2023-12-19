#include "score.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "..\utils\color.h"
#include "..\utils\sleep.h"
#include "..\utils\size.h"

void setContour(){
    for(int j=1; j<=3; j++){
    for (int i = 1; i<=62 ; ++i) {
        gotoXY(i, 1);
        colorPrintf(newAttr(cyan, cyan), " ");
    }
    for (int i = 2; i < 12; ++i) {
        gotoXY(62, i);
        colorPrintf(newAttr(cyan, cyan), " ");
    }
    for (int i = 62; i >= 1; --i) {
        gotoXY(i, 12);
        colorPrintf(newAttr(cyan, cyan), " ");
    }
    for (int i = 11; i >=2; --i) {
        gotoXY(1, i);
        colorPrintf(newAttr(cyan, cyan), " ");
    }
}
    gotoXY(3,1);
    colorPrintf(newAttr(blue, cyan), "SNOOPY'S");
    gotoXY(54,1);
    colorPrintf(newAttr(blue, cyan), "REVENGE");
}

void affichage_vie(int vie_restante, tmStruct *tps, int  * stop){
    gotoXY(70,10);
    colorPrintf(newAttr(white,magenta),"Nombre de vies : %d",vie_restante);
    if (vie_restante == 0){
        tps->shouldStop = 1;
        *stop = 1;
        system("cls");
        gotoXY(10,10);
        printf("Game Over");
        sleep_ms(1000);
        FILE *fptr = fopen("..\\stockage\\data.txt", "w");
        abort();
    }
}

int affichage_oiseau(int oiseau){
    if (oiseau == 4){
        system("cls");
        gotoXY(10,10);
        printf("Win");
        sleep_ms(1000);
        return 1;
    }
    return 0;
}

DWORD WINAPI timer_score (LPVOID timeur){
    tmStruct * tpS = (tmStruct *)timeur;

    wTxtAtt attr = newAttr(white, magenta);

    attr.underscore = 1;
    attr.fInt = 1;
    int i;

//COMMENCEMENT DE LA PARTIE
for (i = 12; i <= 51; ++i) {
    if (tpS->shouldStop==0){
        gotoXY(i, 1);
        colorPrintf(newAttr(blue, white), "-");
        gotoXY(i, 1);
        colorPrintf(newAttr(blue, white), "-");
        sleep_ms(1000);
        --(*tpS->time_left);


    }
    else return (DWORD)0;
    }
for (i = 2; i <= 11; ++i){
    if (tpS->shouldStop==0){
        gotoXY(62, i);
        colorPrintf(newAttr(blue, white), "|");
        sleep_ms(1000);
        --(*tpS->time_left);
        sleep_ms(1000);
        --(*tpS->time_left);
    }
    else return (DWORD)0;
    }
    if (tpS->shouldStop==0){
        gotoXY(70,5);
        colorPrintf(newAttr(white, cyan), "HALF TIME");
        sleep_ms(1000);
        --(*tpS->time_left);
    }
    else return (DWORD)0;


for (i = 51; i >= 12; --i) {
    if (tpS->shouldStop==0){
        gotoXY(i, 12);
        colorPrintf(newAttr(blue, white), "-");
        sleep_ms(1000);
        --(*tpS->time_left);
    }
    else return (DWORD)0;
}
for (i = 11; i >= 2; --i) {
    if (tpS->shouldStop==0){
        gotoXY(1, i);
        colorPrintf(newAttr(blue, white), "|");
        sleep_ms(1000);
        --(*tpS->time_left);
        sleep_ms(1000);
        --(*tpS->time_left);
    }
    else return (DWORD)0;
    }
}


HANDLE Start_timer(tmStruct* tpS){
    return CreateThread(
            NULL, 0, timer_score, (void *) tpS, 0, NULL
    );
}

