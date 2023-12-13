#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"
#include "utils\sleep.h"
#include "stockage\save.h"
#include "score\score.h"

#define max_x  60
#define max_y  12
#define min_x  0
#define min_y  1



int main(){
    system("cls");

    int variable = 0;
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

    def_case[0][1].object = Air;
    def_case[0][2].object = Wall;
    def_case[0][3].object = BlinkingWall0;
    def_case[0][4].object = BlinkingWall1;
    def_case[0][5].object = MouvableWall;
    def_case[0][6].object = BrakableWall;
    def_case[0][7].object = BombWall;
    def_case[0][8].object = ConveyorBeltUp;
    def_case[0][9].object = ConveyorBeltDown;
    def_case[0][10].object = ConveyorBeltLeft;
    def_case[0][11].object = ConveyorBeltRight;
    def_case[0][12].object = Bird;

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

    time_t time_left = 120, variable_timer;
    Start_timer(&time_left);

    while(1) {
        if (kps.k != none) {
            if (kps.k == p) {
                kps.shouldStop = 1;
                break;
            }
            Movement(def_case, keyToChar(kps.k), &x, &y, &valeur);
            updateElement(x, y, def_case, None);
            kps.k = none;
        }



        //gestion defaite => supprimer fichier de jeu
        // remove (data.txt)

        sauve(def_case, x, y);

    }
}

