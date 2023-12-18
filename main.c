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







    //rajouter stockage vie + oiseau recuperer






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

    FILE *fptr = fopen("..\\stockage\\data.txt", "r");
    if( fgetc(fptr) == EOF ) {
        level = 1;
    }
    fclose(fptr);
    start :


    reading(level, def_case, &x, &y, &time_left);

    grille(def_case);

    display(def_case);

    gotoXY(x,y);
    afficherSnoopy(def_case[y-2][(x-2)/3].color);
    startIntervals(def_case, &x, &y);

    affichage_vie(3);
    gotoXY(70,12);
    colorPrintf(newAttr(white,magenta),"nombre d'oiseau : %d",oiseau);
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
            variable = 0;
            x = 2, y = 2;
            oiseau = 0;
            level += 1;
            time_left = 120;
            goto start;
        }
    }
    system("cls");
}

int main(){
    int a = menu();
    launchGame(a);

}
