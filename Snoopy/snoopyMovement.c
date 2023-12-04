#include "snoopyMovement.h"
#include <stdio.h>
#include "..\utils\color.h"
#include "..\utils\keysHandler.h"
#include "..\utils\size.h"
#include "..\elements\elements.h"

int couleur_case[10][20];

#define max_x  60
#define max_y  12
#define min_x  0
#define min_y  1

// structure avec les 3 tableau
void afficherSnoopy(int valeur){
    colorPrintf(newAttr(red,valeur), " %c ", 0x03);
}


void grille(value_case def_case[10][20]){
    int valeur = 1, variable = 0;
    value_case toutes_valeur_case;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j+=1) {
            variable = variable + 2;
            gotoXY(j+variable, i + 2);
            toutes_valeur_case.color = valeur;
            toutes_valeur_case.x = j+variable;
            toutes_valeur_case.y = i+2;
            def_case[i][j] = toutes_valeur_case;
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

void Movement(value_case def_case[10][20], char k, int* x, int* y, int* valeur){  //value_case
    // toute les couleur
    //colorPrintf(newAttr(red,black),"%c",k);
    int action;
        if (k == 'd'){
            if (*x+3 < max_x) {
                switch (def_case[*y-2][(*x+3-2)/3].object) {
                    case 0 :
                    case 1 :
                        break;
                    case 2 :
                        action = MoveWallRight;
                        //lancer la fonction move wall Right avec x et y
                    case 4 :
                    case 5 :
                    case 6 :
                    case 7 :
                    case 8 :
                    case 9 :
                    case 10 :
                        //perte vie
                        break;
                    case 11 :
                        //conveyor up
                    case 12 :
                        //conveyor left
                    case 13 :
                        //conveyor down
                    case 14 :
                        //conveyor right
                    case 16 :
                        //gagner une vie
                }
                *x=*x+3;
                *valeur = def_case[*y-2][(*x-2)/3].color;
                gotoXY(*x-3, *y);
                if (*valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(*x, *y);
                afficherSnoopy(*valeur);
            }
        }
        if (k == 's'){
            if (*y+1<max_y) {
                switch (def_case[*y+1-2][(*x-2)/3].object) {
                    case 0 :
                    case 1 :
                        break;
                    case 2 :
                        action = MoveWallDown;
                        //lancer la fonction move wall Right avec x et y
                    case 4 :
                    case 5 :
                    case 6 :
                    case 7 :
                    case 8 :
                    case 9 :
                    case 10 :
                        //perte vie
                        break;
                    case 11 :
                        //conveyor up
                    case 12 :
                        //conveyor left
                    case 13 :
                        //conveyor down
                    case 14 :
                        //conveyor right
                    case 16 :
                        //gagner une vie
                }
                *y=*y+1;
                *valeur = def_case[*y-2][(*x-2)/3].color;
                gotoXY(*x, *y-1);
                if (*valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(*x, *y);
                afficherSnoopy(*valeur);
            }
        }
        if (k == 'z'){
            if (*y-1>min_y) {
                switch (def_case[*y-1-2][(*x+3-2)/3].object) {
                    case 0 :
                    case 1 :
                        break;
                    case 2 :
                        action = MoveWallUp;
                        //lancer la fonction move wall Right avec x et y
                    case 4 :
                    case 5 :
                    case 6 :
                    case 7 :
                    case 8 :
                    case 9 :
                    case 10 :
                        //perte vie
                        break;
                    case 11 :
                        //conveyor up
                    case 12 :
                        //conveyor left
                    case 13 :
                        //conveyor down
                    case 14 :
                        //conveyor right
                    case 16 :
                        //gagner une vie
                }
                *y=*y-1;
                *valeur = def_case[*y-2][(*x-2)/3].color;
                gotoXY(*x, *y+1);
                if (*valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(*x, *y);
                afficherSnoopy(*valeur);
            }
        }
        if (k == 'q') {
            if (*x-3>min_x) {
                switch (def_case[*y-2][(*x-3-2)/3].object) {
                    case 0 :
                    case 1 :
                        break;
                    case 2 :
                        action = MoveWallLeft;
                        //lancer la fonction move wall Right avec x et y
                    case 4 :
                    case 5 :
                    case 6 :
                    case 7 :
                    case 8 :
                    case 9 :
                    case 10 :
                        //perte vie
                        break;
                    case 11 :
                        //conveyor up
                    case 12 :
                        //conveyor left
                    case 13 :
                        //conveyor down
                    case 14 :
                        //conveyor right
                    case 16 :
                        //gagner une vie
                }
                *x = *x - 3;
                *valeur = def_case[*y-2][(*x-2)/3].color;
                gotoXY(*x+3, *y);
                if (*valeur == 1) {
                    colorPrintf(newAttr(2, 2), "   ");
                }
                else {
                    colorPrintf(newAttr(1, 1), "   ");
                }
                gotoXY(*x, *y);
                afficherSnoopy(*valeur);
            }
        }

}

/* recupere valeur de la case puis switch pour chaque différente case (par exemple bloc => il faut le deplacé*/