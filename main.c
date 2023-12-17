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
    int oiseau = 0;

    time_t time_left = 120, variable_timer;

    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);

    key oldval = none;

    if (1 == 0){
        //gestion victoire
        start :
        variable = 0;
        x = 2, y = 2;
        oiseau = 0;
        level += 1;
        time_left = 120;
    }

    FILE * fichier = fopen("stockage\\data.txt", "r");

    if (fichier == NULL) {
        level = 1;
    }
    fclose(fichier);
    reading(level, def_case, &x, &y, &time_left);

    grille(def_case);

    display(def_case);

    gotoXY(x,y);
    afficherSnoopy(def_case[y-2][(x-2)/3].color);
    startIntervals(def_case);

    affichage_vie(3);
    Start_timer(&time_left);

    while(1) {
        if (kps.k != none) {
            if (kps.k == p) {
                kps.shouldStop = 1;
                sauve(def_case, x, y, time_left);
                break;
            }
            Movement(def_case, keyToChar(kps.k), &x, &y/*, &valeur*/,&oiseau);
            updateElement(x, y, def_case, None);
            kps.k = none;
        }
        if (affichage_oiseau(oiseau)==1){
            remove("stockage\\data.txt");
            goto start;
        }
    }
    system("cls");
}

int main(){
    int a = menu();
    launchGame(a);

}
