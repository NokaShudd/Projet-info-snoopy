#include "..\\menu\\mainmenu.h"
#include "..\\utils\\color.h"
#include "..\\utils\\size.h"
#include "..\\utils\\keysHandler.h"

int setPause(){

    wTxtAtt col = newAttr(red, black);
    col.fInt = 1;
    col.underscore = 1;

    cadre(60, 23);
    gotoXY(2, 2);
    colorPrintf(col, "LE JEU EST EN PAUSE");
    gotoXY(2, 5);
    colorPrintf(col, "Appuiez sur \"q\" pour quitter (la partie sera sauvegardee)");
    gotoXY(2, 8);
    colorPrintf(col, "Appuiez sur n'importe quelle touche pour reprendre");

    gotoXY(30, 11);


    key k = getKey();

    if (k == q) return 1;
    return 0;

}