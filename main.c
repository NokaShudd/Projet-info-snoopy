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
#include "pause/pause.h"

int main();

int launchGame(int level){
    clearToBlack();
    //rajouter stockage vie + oiseau recuperer



    int stop;
    
    int variable = 0;
    int x = 2, y = 2;
    // int valeur = 1;
    int info_mdp = 0;
    value_case def_case[10][20];
    int oiseau = 0;
    long long score_total = 0 ;
    int vie = 3;

    long long scores[3];



    time_t time_left = 120, variable_timer;
    tmStruct tpS={&time_left, 0};


    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);

    key oldval = none;

    FILE *fptr = fopen("..\\stockage\\data.txt", "r");
    if( fgetc(fptr) == EOF ) {
        level = 1;
    }
    fclose(fptr);


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

    stop = 0;
    long long newScore = 0;

    reading(&level, def_case, &x, &y, &vie, &time_left, &newScore, &oiseau);

    setContour(level);
    tpS.time_left = &time_left;

    Start_timer(&tpS);


    score_total += newScore;

    grille(def_case);

    display(def_case);

    gotoXY(x,y);
    afficherSnoopy(def_case[y-2][(x-2)/3].color);

    startIntervals(&x, &y, &vie, def_case, &stop, &tpS);

    
    affichage_vie(vie, &tpS, &stop);
    gotoXY(70,12);
    colorPrintf(newAttr(white,magenta),"nombre d'oiseau : %d",oiseau);


    while(1) {
        if (kps.k != none) {
            if (kps.k == m) {
                stop = 1;
                tpS.shouldStop = 1;
                kps.shouldStop = 1;
                sauve(def_case, x, y, time_left, score_total*100,vie, level,oiseau);
                sleep_ms(500);
                clearToBlack();
                if (setPause()) abort();
                kps.shouldStop = 0;
                tpS.shouldStop = 0;
                getAsyncKey(&kps);
                goto start;
            }
            if (kps.k == p) {
                stop = 1;
                tpS.shouldStop = 1;
                kps.shouldStop = 1;
                sleep_ms(250);
                clearToBlack();
                sauve(def_case, x, y, time_left, score_total*100,vie, level,oiseau);
                break;
            }
            Movement(def_case, keyToChar(kps.k), &x, &y, &oiseau, &vie, &tpS, &stop);
            updateElement(x, y, def_case, None, &x, &y);
            kps.k = none;
        }
        if (affichage_oiseau(oiseau)==1){
            stop = 1;
            FILE *fptr = fopen("..\\stockage\\data.txt", "w");
            fclose(fptr);
            score_total = score_total + time_left;
            colorPrintf(newAttr(black,black),"");
            sleep_ms(250);
            clearToBlack();
            gotoXY(10,10);
            printf("WIN");
            gotoXY(10,11);
            printf("score total : %lld", score_total*100);
            variable = 0;
            x = 2, y = 2;
            oiseau = 0;
            level += 1;
            tpS.shouldStop=1;
            sleep_ms(3000);
            tpS.shouldStop=0;
            setContour(level);
            time_left = 120;
            Start_timer(&tpS);
            if (level == 4){
                main();
            }
            goto start;
        }
        if (time_left==0){
            tpS.shouldStop = 1;
            stop = 1;
            FILE *fptr = fopen("..\\stockage\\data.txt", "w");
            fclose(fptr);
            colorPrintf(newAttr(black,black)," ");
            clearToBlack();
            gotoXY(10,10);
            printf("GAME OVER");
            sleep_ms(1000);
            main();
        }

    }
    clearToBlack();
}

int main(){
    setTitle();
    int a = menu();
    launchGame(a);

}
