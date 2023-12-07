#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"
#include "utils\sleep.h"

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
        if (kps.k != none) {
            Movement(def_case, keyToChar(kps.k),&x, &y,&valeur);
            kps.k = none;
        }
        if (kps.k == p) {kps.shouldStop = 1; break;}
    }
    closeThread(hT);





    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */
    FILE * fPtr;
    /*
     * Open file in w (write) mode.
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("stockage\\data.txt", "w");

    // writing to file
    fwrite(&def_case, sizeof(def_case), 1, fPtr);

    // close file
    fclose(fPtr);

    return 0;

}

