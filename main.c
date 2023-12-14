#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"*
#include "utils\sleep.h"
#include "stockage\save.h"
#include "menu/mainmenu.h"

#define max_x  60
#define max_y  12
#define min_x  0
#define min_y  1

// ne pas supprimer (support macos / linux (j'espère))
#ifndef _WIN32

#include <curses.h>

#endif

#define DATA_SIZE 10000

int main() {
    // ne pas supprimer non plus
    #ifndef _WIN32



    initscr();
    refresh();

    #endif
    menu();

    /*int variable = 0;
    int x=2, y=2;
    int valeur = 1;
    int info_mdp =0;
    value_case def_case[10][20];
    grille(def_case);

    //gestion mdp
    if (info_mdp != 0) {
        if (info_mdp ==1) {
            //reading fichier 1
        }
        else if (info_mdp ==2) {
            //reading fichier 2
        }
        else if (info_mdp ==3) {
            //reading fichier 3
        }
    }


    //si dans menu appuie sur relancer partie renvoie une valeur spécifique
    if (variable == 1 ) {
        //lancer la sauvegarde (vérifié si il y a une sauvegarde
        //changer le x y de snoopy seulement
    }
    else {
        gotoXY(x,y);
        afficherSnoopy(valeur);
    }
    kpStruct kps = {none, 0};
    void* hT = getAsyncKey(&kps);

    key oldval = none;

    while(1){
        if (kps.k != none) {
            Movement(def_case, keyToChar(kps.k),&x, &y,&valeur);
            kps.k = none;
        }
        if (kps.k == p) {
            //sauvegarde donné
            kps.shouldStop = 1; break;
        }
    }

    closeThread(hT);

    //gestion defaite => supprimer fichier de jeu
    // remove (data.txt)

    sauve(def_case, x, y);

*/
}