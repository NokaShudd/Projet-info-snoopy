#include "snoopyMovement.h"
#include <stdio.h>
#include "..\utils\color.h"
#include "..\utils\keysHandler.h"
#include "..\utils\size.h"

int couleur_case[10][20];

void afficherSnoopy(int valeur){
    colorPrintf(newAttr(red,valeur), " %c ", 0x03);
}

void grille(){
    int valeur = 1, variable = 0;
    int x_case [10][20];
    int y_case [10][20];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j+=1) {
            variable = variable + 2;
            gotoXY(j+variable, i + 2);
            couleur_case[i][j]= valeur;
            colorPrintf(newAttr(valeur, valeur), "   ");
            if (valeur == 1  ) {
                valeur = 2;
            }
            else {
                valeur = 1;
            }
        }
        variable = 0;
        if (valeur == 1  ) {
            valeur = 2;
        }
        else {
            valeur = 1;
        }
    }
}

void Movement(){
    // toute les couleurs
    int max_x = 60, max_y = 12, min_x = 0, min_y = 1;
    int x=2, y=2;
    int valeur = 1, variable = 0;
    gotoXY(x,y);
    afficherSnoopy(valeur);
    kpStruct kps = {none, 0};

    void* hT = getAsyncKey(&kps);

    while (1){

        if (kps.k == d){
            if (x+3 < max_x) {
                x=x+3;
                valeur = couleur_case[y-2][(x-2)/3];
                gotoXY(x-3, y);
                if (valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(x, y);
                afficherSnoopy(valeur);
            }
            kps.k = 0;
        }
        if (kps.k == s){
            if (y+1<max_y) {
                y=y+1;
                valeur = couleur_case[y-2][(x-2)/3];
                gotoXY(x, y-1);
                if (valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(x, y);
                afficherSnoopy(valeur);
            }
            kps.k = 0;
        }
        if (kps.k == z){
            if (y-1>min_y) {
                y=y-1;
                valeur = couleur_case[y-2][(x-2)/3];
                gotoXY(x, y+1);
                if (valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(x, y);
                afficherSnoopy(valeur);
            }
            kps.k = 0;
        }
        if (kps.k == q) {
            if (x-3>min_x) {
                x = x - 3;
                valeur = couleur_case[y-2][(x-2)/3];
                gotoXY(x+3, y);
                if (valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(x, y);
                afficherSnoopy(valeur);
            }
            kps.k = 0;
        }
        if (kps.k == p) {kps.shouldStop = 1; break;}

    }

    closeThread(hT);
}