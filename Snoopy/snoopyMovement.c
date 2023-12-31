#include "snoopyMovement.h"
#include <stdio.h>
#include "..\utils\color.h"
#include "..\utils\keysHandler.h"
#include "..\utils\size.h"
#include "..\elements\elements.h"
#include "..\score\score.h"

#define max_x  60
#define max_y  12
#define min_x  0
#define min_y  1

// structure avec les 3 tableau
void afficherSnoopy(int valeur){
    colorPrintf(newAttr(red, valeur), " %c ", 0x03);
}


void grille(value_case def_case[10][20]){
    int variable = 0;
    value_case toutes_valeur_case;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j+=1) {
            variable += 2;
            gotoXY(j+variable, i + 2);
            // toutes_valeur_case.color = valeur;
            toutes_valeur_case.x = j+variable;
            toutes_valeur_case.y = i+2;
            def_case[i][j].x = j+variable;
            def_case[i][j].y = i+2;
            colorPrintf(newAttr(white, def_case[i][j].color), "   ");

        }
        variable = 0;
    }
    gotoXY(32, 11);
    colorPrintf(newAttr(blue, blue), "   ");

}

void Movement(value_case def_case[10][20], char k, int* x, int* y/*, int* valeur*/, int * oiseau, int * vie, tmStruct* tps , int * stop){  //value_case
    // toute les couleur
    //colorPrintf(newAttr(red,black),"%c",k);
    /*if (def_case[*y-2][(*x+3-2)/3].object == 1){
        vie = vie -1;
        affichage_vie(vie);
        goto feur;

    }*/
    int valeur = 4;
    int action = 0;
    if (k == 'd' || k == '>'){
        if (*x+3 < max_x) {
            switch (def_case[*y-2][(*x-2)/3+1].object) {
                case 0 :
                case 1 :
                case 3 :
                    goto feur;
                case 2 :
                    action = MoveWallRight;
                    updateElement((*x-2)/3+1,*y-2,def_case,action, x, y);
                    goto feur;
                    break;
                case 5 :
                case 6 :
                case 7 :
                case 8 :
                case 9 :
                    if (!realBall(*y-2, (*x-2)/3)) break;
                case 4 :
                    *vie = *vie - 1;
                    affichage_vie(*vie, tps, stop) ;
                    goto feur;
                case 11 :
                case 12 :
                case 13 :
                case 14 :
                
                    gotoXY(*x, *y);
                    colorPrintf(newAttr(2, def_case[*y-2][(*x-2)/3].color), "   ");
                    *x+=3;
                    onConvoyer(x, y, def_case);
                    goto feur;
                case 16 :
                    *oiseau += 1;
                    def_case[*y-2][(*x-2)/3+1].object = Air;
                    gotoXY(70,12);
                    colorPrintf(newAttr(white,magenta),"nombre d'oiseau : %d",*oiseau);

            }
            *x=*x+3;
            valeur = def_case[*y-2][(*x-2)/3].color;
            gotoXY(*x-3, *y);
            if (valeur == 1) {
                colorPrintf(newAttr(2, 2), "   ");
            }
            else {
                colorPrintf(newAttr(1, 1), "   ");
            }
            gotoXY(*x, *y);
            afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
        }
    }
    if (k == 's' || k == 'v'){
        if (*y+1<max_y) {
            switch (def_case[*y+1-2][(*x-2)/3].object) {
                case 0 :
                case 1 :
                case 3:
                    goto feur;
                case 2 :
                    action = MoveWallDown;
                    updateElement((*x-2)/3, *y+1-2, def_case, action, x, y);
                    goto feur;
                case 5 :
                case 6 :
                case 7 :
                case 8 :
                case 9 :
                    if (!realBall(*y-2, (*x-2)/3)) break;
                case 4 :
                    *vie = *vie - 1;
                    affichage_vie(*vie, tps, stop) ;
                    goto feur;
                case 11 :
                case 12 :
                case 13 :
                case 14 :
                    gotoXY(*x, *y);
                    colorPrintf(newAttr(2, def_case[*y-2][(*x-2)/3].color), "   ");
                    *y = *y + 1;
                    onConvoyer(x, y, def_case);
                    goto feur;
                    
                    break;
                case 16 :
                    *oiseau += 1;
                    def_case[*y+1-2][(*x-2)/3].object = Air;
                    gotoXY(70,12);
                    colorPrintf(newAttr(white,magenta),"nombre d'oiseau : %d",*oiseau);

            }
            *y=*y+1;
            valeur = def_case[*y-2][(*x-2)/3].color;
            gotoXY(*x, *y-1);
            if (valeur == 1) {
                colorPrintf(newAttr(2, 2), "   ");
            }
            else {
                colorPrintf(newAttr(1, 1), "   ");
            }
            gotoXY(*x, *y);
            afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
        }
    }
    if (k == 'z' || k == '^'){
        if (*y-1>min_y) {
            switch (def_case[*y-1-2][((*x-2)/3)].object) {
                case 0 :
                case 1 :
                case 3:
                    goto feur;
                case 2 :
                    action = MoveWallUp;
                    updateElement(((*x-2)/3),*y-1-2,def_case, action, x, y);
                    goto feur;

                    break;

                case 5 :
                case 6 :
                case 7 :
                case 8 :
                case 9 :
                    if (!realBall(*y-2, (*x-2)/3)) break;
                case 4 :
                    *vie = *vie - 1;
                    affichage_vie(*vie, tps, stop) ;
                    goto feur;
                case 11 :
                case 12 :
                case 13 :
                case 14 :
                
                    gotoXY(*x, *y);
                    colorPrintf(newAttr(2, def_case[*y-2][(*x-2)/3].color), "   ");
                    *y = *y - 1;
                    onConvoyer(x, y, def_case);
                    goto feur;
                    break;
                case 16 :
                    *oiseau += 1;
                    def_case[*y-2-1][(*x-2)/3].object = Air;
                    gotoXY(70,12);
                    colorPrintf(newAttr(white,magenta),"nombre d'oiseau : %d",*oiseau);

            }

            *y=*y-1;
            valeur = def_case[*y-2][(*x-2)/3].color;
            gotoXY(*x, *y+1);
            if (valeur== 1) {
                colorPrintf(newAttr(2, 2), "   ");
            }
            else {
                colorPrintf(newAttr(1, 1), "   ");
            }
            gotoXY(*x, *y);
            afficherSnoopy(def_case[*y-2][(*x-2)/3].color );
        }
    }
    if (k == 'q' || k == '<') {
        if (*x-3>min_x) {
            switch (def_case[*y-2][(*x-2)/3-1].object) {
                case 0 :
                case 1 :
                case 3:
                    goto feur;
                case 2 :
                    action = MoveWallLeft;
                    updateElement((*x-2)/3-1,*y-2,def_case,action, x, y);
                    
                    goto feur;
                case 5 :
                case 6 :
                case 7 :
                case 8 :
                case 9 :
                    if (!realBall(*y-2, (*x-2)/3)) break;
                case 4 :
                    *vie = *vie - 1;
                    affichage_vie(*vie, tps, stop) ;
                    goto feur;
                case 11 :
                case 12 :
                case 13 :
                case 14 :
                    gotoXY(*x, *y);
                    colorPrintf(newAttr(2, def_case[*y-2][(*x-2)/3].color), "   ");
                    *x-=3;
                    onConvoyer(x, y, def_case);
                    goto feur;
                case 16 :
                    *oiseau += 1;
                    def_case[*y-2][(*x-2)/3-1].object = Air;
                    gotoXY(70,12);
                    colorPrintf(newAttr(white,magenta),"nombre d'oiseau : %d",*oiseau);

            }
            *x = *x - 3;
            valeur = def_case[*y-2][(*x-2)/3].color;
            gotoXY(*x+3, *y);
            if (valeur == 1) {
                colorPrintf(newAttr(2, 2), "   ");
            }
            else {
                colorPrintf(newAttr(1, 1), "   ");
            }
            gotoXY(*x, *y);
            afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
        }

    }
    feur :
    if  (k == ' '){
        action = Punch;
        updateElement((*x - 2) / 3,*y - 2,def_case, action, x, y);
    }
}

/* recupere valeur de la case puis switch pour chaque différente case (par exemple bloc => il faut le deplacé*/