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

void rules(){
    system("cls");
    sleep_ms(100);
    cadre(60, 23);
    gotoXY(2, 2);
    colorPrintf(couleur3, "Regles du jeu:");
    gotoXY(2,5);
    colorPrintf(couleur3, "L'objectif de Snoopy est d'attraper tout les oiseaux ");
    colorPrintf(newAttr(yellow, black), " %c ", 0x0F);
    gotoXY(2,6);
    colorPrintf(couleur3, "Vous avez 3 vies, et 120 secondes pour reussir le niveau.");
    gotoXY(2,7);
    colorPrintf(couleur3, "Si le temps est ecoule avant de recuperer les oiseaux");
    gotoXY(2,8);
    colorPrintf(couleur3, "vous perdrez une vie, idem si vous touchez une bombe : ");
    colorPrintf(newAttr(red, red), "   ");
    gotoXY(2,9);
    colorPrintf(couleur3, "Plus vous finissez rapidement un niveau, plus vous obtenez");
    gotoXY(2,10);
    colorPrintf(couleur3, "de points.");
    gotoXY(2, 12);
    colorPrintf(couleur3, "Vous pouvez consulter vos scores dans l'onglet du menu.");
    gotoXY(2, 13);
    colorPrintf(couleur3, "Si vous souhaitez quitter la partie en cours, pressez P.");
    gotoXY(2,14);
    colorPrintf(couleur3, "De nombreux blocs sont disponibles sur le jeu :");
    gotoXY(2,16);
    colorPrintf(couleur3, "Le tapis roulant : ");
    colorPrintf(newAttr(red, black), " %c ", 0x1F);
    colorPrintf(newAttr(red, black), " %c ", 0x1E);
    colorPrintf(newAttr(red, black), " %c ", 0x10);
    colorPrintf(newAttr(red, black), " %c ", 0x11);
    gotoXY(2,17);
    colorPrintf(couleur3, "La Balle : ");
    colorPrintf(newAttr(red, black), " o ");
    gotoXY(2, 18);
    colorPrintf(couleur3, "Les blocs cassables, cassable avec ESPACE : ");
    colorPrintf(newAttr(white, black),"%c%c%c", 0xB2, 0xB2, 0xB2);
    gotoXY(2,19);
    colorPrintf(couleur3, "Les blocs poussables une seule fois : ");
    colorPrintf(newAttr(yellow, yellow), " %c ", "   ");
    gotoXY(2,21);
    colorPrintf(couleur3, "Quittez avec p.");


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
    colorPrintf(couleur3,"- Otniel Sandeu");
    sleep_ms(1000);
    gotoXY(2, 10);
    colorPrintf(couleur3,"- Nicolas Tremblay");
    sleep_ms(1000);
    system("cls");
}

int choisirNiveau(int mdp){
    system("cls");
    sleep_ms(100);
    cadre(40,6);
    gotoXY(2, 2);
    colorPrintf(couleur3,"Veuillez rentrer le mot de passe :");
    gotoXY(2,4);
    colorPrintf(couleur3, "Mot de Passe:");
    gotoXY(16, 4);
    scanf("%d", &mdp);
    printf("%d",mdp);
    return mdp;
}

int voirScore(int score1, int score2, int score3){
    system("cls");
    sleep_ms(100);
    cadre(30,12);
    gotoXY(2, 2);
    colorPrintf(couleur3, "Vos meilleurs scores:");
    gotoXY(2,4);
    colorPrintf(couleur3, "1 : %d", score1);
    gotoXY(2,6);
    colorPrintf(couleur3, "2 : %d", score2);
    gotoXY(2,8);
    colorPrintf(couleur3, "3 : %d", score3);
    gotoXY(2,10);
    colorPrintf(couleur3, "Q pour quitter.");
}

int menu() {

    kpStruct kps = {none, 0};
    getAsyncKey(&kps);
    cpStruct cps = {none, 0};

    int longueur = 45;
menu:



    system("cls");
    sleep_ms(100);
    gotoXY(0,2);
    colorPrintf(couleur3, "  %c  : Commencer / reprendre une partie \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Acceder a un niveau specifique \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Voir tes meilleurs scores \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Credits \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Regles du jeu \n\n", 0xDB);
    colorPrintf(couleur3, "  %c  : Quitter le jeu \n\n", 0xDB);
    cadre(longueur, 14);

    int choix=0;
    int old=0;
    gotoXY(2, 2);
    colorPrintf(newAttr(white, black), "%c", 0xDB);
    int mdp = 0;
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
                    return 0;
                case 1:
                    mdp = choisirNiveau(mdp);
                    switch (mdp) {
                        case 1:
                            return 1;
                        case 2:
                            return 2;
                        case 3:
                            return 3;
                        case 4:
                            return 4;
                        default:
                            colorPrintf(couleur3,"Ce mot de passe est faux.");
                            sleep_ms(1000);
                            goto menu;
                            mdp=1;
                        }
                        break;
                case 2:
                    voirScore(12, 15, 17);
                    while (kps.k!=q)
                    {
                    }
                    goto menu;
                    break;
                case 3:
                    voirCredit();
                    goto menu;
                    break;
                case 4:
                    rules();
                    while (kps.k!=p)
                    {
                    }
                    goto menu;
                    
                    
                case 5:
                    system("cls");
                    abort();
            }
        }
    } while(1);
}