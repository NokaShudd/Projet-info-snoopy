#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"

// ne pas supprimer (support macos / linux (j'espère))
#ifndef _WIN32

#include <curses.h>

#endif


int main(){
    // ne pas supprimer non plus
    #ifndef _WIN32

    initscr();
    refresh();

    #endif
    value_case def_case[10][20];

    grille(def_case);

    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);
    int x=2, y=2;
    int valeur = 1;
    gotoXY(x,y);
    afficherSnoopy(valeur);

    key oldval = none;

    while(1){
        key currentk = kps.k;
        Movement(def_case, currentk,&x, &y,&valeur);
        if (kps.k == p) {kps.shouldStop = 1; break;}
        if (currentk == oldval) kps.k = none;
        oldval = kps.k;
    }
    closeThread(hT);
    return 0;
}