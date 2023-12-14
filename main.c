#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"
#include "utils\sleep.h"
#include "stockage\save.h"
#include "menu/mainmenu.h"
#include "score\score.h"

int launchGame(int level){
    system("cls");

    int variable = 0;
    int x = 2, y = 2;
    // int valeur = 1;
    int info_mdp = 0;
    value_case def_case[10][20];



    time_t time_left = 120, variable_timer;

    reading(level, def_case, &x, &y, &time_left);

    grille(def_case);

    display(def_case);

    gotoXY(x,y);
    afficherSnoopy(def_case[y-2][(x-2)/3].color);
    startIntervals(def_case);

    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);

    key oldval = none;

    
    Start_timer(&time_left);

    while(1) {
        if (kps.k != none) {
            if (kps.k == p) {
                kps.shouldStop = 1;
                break;
            }
            Movement(def_case, keyToChar(kps.k), &x, &y/*, &valeur*/);
            updateElement(x, y, def_case, None);
            kps.k = none;
        }



        //gestion defaite => supprimer fichier de jeu
        // remove (data.txt)


    }
    system("cls");
    sauve(def_case, x, y, time_left);
}


int main(){
    int a = menu();
    launchGame(a);

}


