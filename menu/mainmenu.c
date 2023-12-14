
#include "stdlib.h"
#include "stdio.h"
#include "../utils/sleep.h"
#include "../utils/color.h"
#include "../utils/size.h"
#include "../utils/keysHandler.h"

#define couleur3 newAttr(red, black)

void cadre(int longueur, int largeur){

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
    cadre(40,12);
    gotoXY(2, 2);
    colorPrintf(couleur3,"Jeu realise par :");
    sleep_ms(1000);
    gotoXY(2, 4);
    colorPrintf(couleur3,"- Hugo Roure ");
    sleep_ms(1000);
    gotoXY(2, 6);
    colorPrintf(couleur3,"- Pierre Juramie ");
    sleep_ms(1000);
    gotoXY(2, 8);
    colorPrintf(couleur3,"- Otniel 102");
    sleep_ms(1000);
    gotoXY(2, 10);
    colorPrintf(couleur3,"- Nicolas Tremblay");
    sleep_ms(1000);
    system("cls");
}

void choisirNiveau(int mdp){
    system("cls");
    sleep_ms(100);
    cadre(40,6);
    gotoXY(2, 2);
    colorPrintf(couleur3,"Veuillez rentrer le mot de passe :");
    gotoXY(2,4);
    colorPrintf(couleur3, "Mot de Passe:");
    gotoXY(17, 4);
    mdp=0;
    scanf("%d", &mdp);
    return mdp;
}


int menu() {

    kpStruct kps = {none, 0};
    getAsyncKey(&kps);


menu:


    int longueur = 45;
    system("cls");
    sleep_ms(100);
    gotoXY(0,2);
    colorPrintf(couleur3, "  %c  : Commencer / reprendre une partie \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Acceder a un niveau specifique \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Voir tes meilleurs scores \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Credits \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Parametres \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Quitter le jeu \n\n", 0xDB);
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
                int mdp=0;
                choisirNiveau(mdp);
                switch (mdp)
                    {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    default:
                        colorPrintf(couleur3,"Ce mot de passe est faux.");
                        sleep_ms(1000);
                        goto menu;
                    }
                    break;
                    mdp=0;
                case 2:
                    break;
                case 3:
                    voirCredit();
                    goto menu;
                    break;
                case 4:
                    break;
                case 5:;
            }
        }
    }while(1);
}