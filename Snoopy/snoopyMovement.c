#include "snoopyMovement.h"
#include <stdio.h>
#include "..\utils\color.h"
#include "..\utils\keysHandler.h"
#include "..\utils\size.h"


void afficherSnoopy(){
    colorPrintf(newAttr(red,white), " %c ", 0x03);
}

void grille(){
    for (int i = 0; i < 11; i++) {
        for (int j = 1; j < 62; j+=3) {
            gotoXY(j, i + 2);
            colorPrintf(newAttr(white, white), "   ");
        }
    }
}

void Movement(){
    // toute les couleurs
    int max_x = 60, max_y = 13, min_x = 0, min_y = 1;
    int x=2, y=2;

    gotoXY(x,y);
    afficherSnoopy();
    kpStruct kps = {none, 0};

    void* hT = getAsyncKey(&kps);

    while (1){
        if (kps.k == d){
            if (x+3 <max_x) {
                x=x+3;
                gotoXY(x-3, y);
                colorPrintf(newAttr(white, white), "   ");
                gotoXY(x, y);
                afficherSnoopy();
            }
            kps.k = 0;
        }
        if (kps.k == s){
            if (y+1<max_y) {
                y=y+1;
                gotoXY(x, y-1);
                colorPrintf(newAttr(white, white), "   ");
                gotoXY(x, y);
                afficherSnoopy();
            }
            kps.k = 0;
        }
        if (kps.k == z){
            if (y-1>min_y) {
                y=y-1;
                gotoXY(x, y+1);
                colorPrintf(newAttr(white, white), "   ");
                gotoXY(x, y);
                afficherSnoopy();
            }
            kps.k = 0;
        }
        if (kps.k == q) {
            if (x-3>min_x) {
                x = x - 3;
                gotoXY(x+3, y);
                colorPrintf(newAttr(white, white), "   ");
                gotoXY(x, y);
                afficherSnoopy();
            }
            kps.k = 0;
        }
        if (kps.k == p) {kps.shouldStop = 1; break;}

    }

    closeThread(hT);
}