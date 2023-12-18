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
    long long score_total = 0 ;
    int vie = 3;

    time_t time_left = 120, variable_timer;

    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);

    key oldval = none;

    FILE *fptr = fopen("..\\stockage\\data.txt", "r");
    if( fgetc(fptr) == EOF ) {
        level = 1;
    }
    fclose(fptr);

    Start_timer(&time_left);

    switch (level) {
        case 2:
            level = 2;
            break;
        case 3:
            level = 3;
            break;
        case 4 :
            level = 4;
            break;
    }

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


    while(1) {
        if (kps.k != none) {
            if (kps.k == p) {
                kps.shouldStop = 1;
                sauve(def_case, x, y, time_left);
                break;
            }
            Movement(def_case, keyToChar(kps.k), &x, &y/*, &valeur*/,&oiseau, &vie);
            updateElement(x, y, def_case, None, &x, &y);
            kps.k = none;
        }
        if (affichage_oiseau(oiseau)==1){
            score_total = score_total + time_left;
            FILE *fptr = fopen("..\\stockage\\data.txt", "w");
            fclose(fptr);
            colorPrintf(newAttr(black,black),"");
            system("cls");
            gotoXY(10,10);
            printf("WIN");
            gotoXY(10,11);
            printf("score total : %lld", score_total*100);
            sleep_ms(1000);
            variable = 0;
            x = 2, y = 2;
            oiseau = 0;
            level += 1;
            time_left = 120;
            if (level == 4 ){
                abort();
            }
            goto start;
        }
        if (time_left==0){
            FILE *fptr = fopen("..\\stockage\\data.txt", "w");
            fclose(fptr);
            colorPrintf(newAttr(black,black)," ");
            system("cls");
            gotoXY(10,10);
            printf("Game Over");
            sleep_ms(1000);
            abort();
        }
    }
    system("cls");
}

int main(){
    int a = menu();
    launchGame(a);

}
