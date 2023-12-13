#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements\elements.h"
#include "utils\sleep.h"
#include "stockage/save.h"

#define max_x  60
#define max_y  12
#define min_x  0
#define min_y  1

// ne pas supprimer (support macos / linux (j'espère))
#ifndef _WIN32

#include <curses.h>

#endif

#define DATA_SIZE 10000

int main(){
    system("cls");

    int variable = 0;
    int x=2, y=2;
    int snoopx =2, snoopy = 2;
    int valeur = 1;
    int info_mdp =0;
    value_case def_case[10][20];
    grille(def_case);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            def_case[i][j].object = Air;
        }
        
    }

    def_case[5][9].object = BlinkingWall1;
    def_case[5][10].object = Wall;
    def_case[5][8].object = BombWall;
    def_case[4][9].object = BlinkingWall1;

    display(def_case);


    //si dans menu appuie sur relancer partie renvoie une valeur spécifique
    if (variable == 1 ) {
        //lancer la sauvegarde (vérifié si il y a une sauvegarde
        //changer le x y de snoopy seulement
    }
    else {
        gotoXY(x,y);
        afficherSnoopy(valeur);
        startIntervals(def_case);
    }
    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);

    key oldval = none;


    while(1){
        if (kps.k != none) {
            Movement(def_case, keyToChar(kps.k),&x, &y,&valeur);
            updateElement(x, y, def_case, None);
            kps.k = none;
        }
        if (kps.k == p) {
            //sauvegarde donné
            kps.shouldStop = 1; break;
        }

    }



}

