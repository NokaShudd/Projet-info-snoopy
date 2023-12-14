
#include "stdlib.h"
#include "stdio.h"
#include "../utils/sleep.h"
#include "../utils/color.h"
#include "../utils/size.h"
#include "../utils/keysHandler.h"


void cadre(int longueur, int largeur){
    wTxtAtt couleur3 = newAttr(red, black); //haut

    for(int i=1; i<longueur; i++){
        gotoXY(i, 0);
        colorPrintf(couleur3, "%c", 0xCD);
    }
    colorPrintf(couleur3, "%c", 0xBB); //bas
    for (int i = 1; i < longueur; i++) {
        gotoXY(i, largeur);
        colorPrintf(couleur3, "%c", 0xCD);
    }
    colorPrintf(couleur3,"%c", 0xBC);
    gotoXY(0, largeur);
    colorPrintf(couleur3,"%c", 0xC8);
    for (int i = 1; i < largeur; ++i) { //gauche
        gotoXY(0, i);
        colorPrintf(couleur3, "%c", 0xBA);
    }
    for (int i = 1; i < largeur; ++i) { //droit
        gotoXY(longueur, i);
        colorPrintf(couleur3, "%c", 0xBA);
    }
    gotoXY(0, 0);
    colorPrintf(couleur3, "%c", 0xC9);

}
void voirCredit(){
    system("cls");
    sleep_ms(100);
    cadre(40,13);
    gotoXY(2, 2);
    printf("Jeu realise par :\n ");
    sleep_ms(1000);
    gotoXY(2, 2);
    printf("- Hugo Roure \n");
    sleep_ms(1000);
    gotoXY(2, 2);
    printf("- Pierre Juramie \n ");
    sleep_ms(1000);
    gotoXY(2, 2);
    printf("- Otniel \n");
    sleep_ms(1000);
    gotoXY(2, 2);
    printf("- Nicolas \n");
    sleep_ms(1000);
}


int menu() {

    kpStruct kps = {none, 0};
    getAsyncKey(&kps);





    int longueur = 45;
    wTxtAtt couleur = newAttr(red, black);
    system("cls");
    sleep_ms(100);
    gotoXY(0,2);
    colorPrintf(couleur, "  %c  : Commencer / reprendre une partie \n\n", 0xDB);
    colorPrintf(couleur, "  %c  : Acceder a un niveau specifique \n\n", 0xDB);
    colorPrintf(couleur, "  %c  : Voir tes meilleurs scores \n\n", 0xDB);
    colorPrintf(couleur, "  %c  : Credits \n\n", 0xDB);
    colorPrintf(couleur, "  %c  : Parametres \n\n", 0xDB);
    colorPrintf(couleur, "  %c  : Quitter le jeu \n\n", 0xDB);
    cadre(longueur, 14);

    int choix=0;
    int old=0;
    gotoXY(2, 2);
    colorPrintf(newAttr(white, black), "%c", 0xDB);
    do {


        if (kps.k==arrowDown){
            old=choix;
            if(choix==5){
                choix=0;
            } else{
                ++choix;
            }
            kps.k=none;
        } else if(kps.k==arrowUp){
            old=choix;
            if(choix==0){
                choix=5;
            } else {
                --choix;
            }
            kps.k=none;
        }

        if (old!=choix){
            gotoXY(2, (choix+1)*2);
            colorPrintf(newAttr(white, black), "%c", 0xDB);
            gotoXY(2, (old+1)*2);
            colorPrintf(newAttr(red, black), "%c", 0xDB);
            old=choix;
        }


        if (kps.k==enter) {
            kps.k=none;
            switch (choix) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    voirCredit();
                    menu();
                    break;
                case 4:
                    break;
                case 5:;
            }
        }
    }while(1);
}