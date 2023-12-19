#include "elements.h"
#include "..\utils\size.h"
#include "..\utils\color.h"
#include "..\Snoopy\snoopyMovement.h"
#include "..\utils\sleep.h"
#include "..\score\score.h"
#include <windows.h>


value_case def_case[10][20];
value_case stillDef_case[10][20];
int *snoopx, *snoopy;
int *vie;

int setBallDirection(value_case grille[10][20], int x, int y, int iteration) {
    if (iteration == 5) return Ball4;
    switch (grille[y][x].object) {
        case Ball4 : return Ball4;
        case Ball0:
            if (y == 0 ) {
                grille[y][x].object = Ball1;
                return setBallDirection(grille, x, y, ++iteration);
            }
            if (x == 0 ) {
                grille[y][x].object = Ball3;
                return setBallDirection(grille, x, y, ++iteration);
            }
            return Ball0;
        break;
        
        case Ball1:
            if (y == 9 ) {
                grille[y][x].object = Ball0;
                return setBallDirection(grille, x, y, ++iteration);
            }
            if (x == 0 ) {
                grille[y][x].object = Ball2;
                return setBallDirection(grille, x, y, ++iteration);
            }
            return Ball1;
        break;
            
        case Ball2:
            if (y == 9 ) {
                grille[y][x].object = Ball3;
                return setBallDirection(grille, x, y, ++iteration);
            }
            if (x == 19 ) {
                grille[y][x].object = Ball1;
                return setBallDirection(grille, x, y, ++iteration);
            }
            return Ball2;
        break;
            
        case Ball3:
            if (y == 0 ) {
                grille[y][x].object = Ball2;
                return setBallDirection(grille, x, y, ++iteration);
            }
            if (x == 19 ) {
                grille[y][x].object = Ball0;
                return setBallDirection(grille, x, y, ++iteration);
            }
            return Ball3;
        break;
    }

}



void drawElement(int x, int y, int object, int color){
    gotoXY(x, y);
    switch (object) {
        case Air:
            colorPrintf(newAttr(white, color), "   ");
        return;
        
        case BlinkingWall0:
            colorPrintf(newAttr(white, color),"%c%c%c", 0xB2, 0xB2, 0xB2);
        return;

        case BlinkingWall1:
            colorPrintf(newAttr(white, color),"%c%c%c", 0xB1, 0xB1, 0xB1);
        return;

        case BombWall:
            colorPrintf(newAttr(red, red), "   ");
        return;

        case Wall:
            colorPrintf(newAttr(white, white), "   ");
        return;
        
        case ConveyorBeltDown:
            colorPrintf(newAttr(red, color), " %c ", 0x1F);
        return;
        case ConveyorBeltUp:
            colorPrintf(newAttr(red, color), " %c ", 0x1E);
        return;
        case ConveyorBeltLeft:
            colorPrintf(newAttr(red, color), " %c ", 0x10);
        return;
        case ConveyorBeltRight:
            colorPrintf(newAttr(red, color), " %c ", 0x11);
        return;

        case BrakableWall:
            colorPrintf(newAttr(black, black), " %c ", "   ");
        return;
        
        case Ball0:
            colorPrintf(newAttr(red, color), " o ");
            return;
        case Ball1:
            colorPrintf(newAttr(red, color), " o ");
            return;
        case Ball2:
            colorPrintf(newAttr(red, color), " o ");
            return;
        case Ball3:
            colorPrintf(newAttr(red, color), " o ");
            return;
        case Ball4:
            colorPrintf(newAttr(red, color), " o ");
        return;
        
        case MouvableWall:
            colorPrintf(newAttr(yellow, yellow), " %c ", "   ");
        return;

        
        case Bird:
            colorPrintf(newAttr(yellow, color), " %c ", 0x0F);
        return;
    }
}


void drawCase(value_case kase){
    drawElement(
        kase.x, kase.y, kase.object, kase.color
    );
}

void drawBall(value_case kase) {
    gotoXY(kase.x, kase.y);
    int bgColor = kase.color;
    switch (kase.object) {
        case Wall:
            bgColor = white;
        break;
        case MouvableWall:
            bgColor = yellow;
        break;
        case BombWall:
            bgColor = red;
        break;        
    }
    colorPrintf(newAttr( (bgColor != red) ? red : black, bgColor), " o ");

}

void moveBall(value_case grille[10][20], int snoopx, int snoopy, int *vie){
    int xBuffer[200];
    int yBuffer[200];
    int numbPair = 0;


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (grille[i][j].object > 4 && grille[i][j].object < 10) {
                xBuffer[numbPair]   = j;
                yBuffer[numbPair++] = i;
            }
        }
        
    }


    for (int i = 0; i < numbPair; i++) {
        if (snoopx == grille[yBuffer[i]][xBuffer[i]].x && snoopy == grille[yBuffer[i]][xBuffer[i]].y) {
            *vie = *vie - 1;
        }

        
        switch (setBallDirection(grille, xBuffer[i], yBuffer[i], 1)) {
            case Ball0:
                drawBall(grille[yBuffer[i]-1][xBuffer[i]-1]);
                grille[yBuffer[i]-1][xBuffer[i]-1].object = Ball0;
            break;
            case Ball1:
                drawBall(grille[yBuffer[i]+1][xBuffer[i]-1]);
                grille[yBuffer[i]+1][xBuffer[i]-1].object = Ball1;
            break;
            case Ball2:
                drawBall(grille[yBuffer[i]+1][xBuffer[i]+1]);
                grille[yBuffer[i]+1][xBuffer[i]+1].object = Ball2;
               
            break;
            case Ball3:
                drawBall(grille[yBuffer[i]-1][xBuffer[i]+1]);
                grille[yBuffer[i]-1][xBuffer[i]+1].object = Ball3;
                
            break;
        }
      
        grille[yBuffer[i]][xBuffer[i]].object = stillDef_case[yBuffer[i]][xBuffer[i]].object;




        drawElement(
            grille[yBuffer[i]][xBuffer[i]].x,
            grille[yBuffer[i]][xBuffer[i]].y,
            stillDef_case[yBuffer[i]][xBuffer[i]].object,
            grille[yBuffer[i]][xBuffer[i]].color
        );

        if (snoopx == grille[yBuffer[i]][xBuffer[i]].x && snoopy == grille[yBuffer[i]][xBuffer[i]].y) {
            gotoXY(snoopx, snoopy);
            afficherSnoopy(grille[yBuffer[i]][xBuffer[i]].color);
        } 
    }
    
    
}



DWORD WINAPI changeAfterInterval(LPVOID lparam) {
    int numb = 0;

    int* stop = (int *)lparam;

    sleep_ms(499);


    while (!(*stop)){
        sleep_ms(498);

        moveBall(def_case, *snoopx, *snoopy, vie);

        numb = ++numb % 4;
    }
    
    return 0;
}


HANDLE startIntervals(int *x, int *y, int *v, value_case def_casep[10][20], int *stop, tmStruct *tpS) {
    snoopx = x;
    snoopy = y;
    vie = v;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            def_case[i][j] = def_casep[i][j];
            stillDef_case[i][j].color = def_casep[i][j].color;
            stillDef_case[i][j].object = def_casep[i][j].object;
            stillDef_case[i][j].x = def_casep[i][j].x;
            stillDef_case[i][j].y = def_casep[i][j].y;
            
            if (stillDef_case[i][j].object >= Ball0 && stillDef_case[i][j].object <= Ball4) {
                stillDef_case[i][j].object = Air;
            }

        }
    }
    
    return CreateThread(
        NULL, 0, changeAfterInterval, (void*)stop, 0, NULL
    );
}

void onConvoyer(int* x, int* y, value_case def_case[10][20]){
    gotoXY(*x, *y);
    afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
    sleep_ms(900);
    drawCase(def_case[*y-2][(*x-2)/3]);
    switch (def_case[*y-2][(*x-2)/3].object) {
        case ConveyorBeltUp:
            *y = def_case[*y-3][(*x-2)/3].y;
            gotoXY(*x, *y);  

                      
            if (def_case[*y-2][(*x-2)/3].object >= ConveyorBeltUp && def_case[*y-2][(*x-2)/3].object <= ConveyorBeltRight) {
                afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
                onConvoyer(x, y, def_case);

            } else {
                afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
                drawCase(def_case[*y-1][(*x-2)/3]);
                return;
            }
            break;
        case ConveyorBeltDown:
            *y = def_case[*y-1][(*x-2)/3].y;

            gotoXY(*x, *y);
 
            if (def_case[*y-2][(*x-2)/3].object >= ConveyorBeltUp && def_case[*y-2][(*x-2)/3].object <= ConveyorBeltRight) {
                onConvoyer(x, y, def_case);
            } else {
                afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
                drawCase(def_case[*y-3][(*x-2)/3]);
                return;
            }
            break;
        case ConveyorBeltLeft:
            *x = def_case[*y-2][(*x-2)/3 + 1].x;
            
            gotoXY(*x, *y);
 
            if (def_case[*y-2][(*x-2)/3].object >= ConveyorBeltUp && def_case[*y-2][(*x-2)/3].object <= ConveyorBeltRight) {
                onConvoyer(x, y, def_case);
            } else {
                afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
                drawCase(def_case[*y-2][(*x-2)/3 - 1]);
                return;
                
            }
            break;
        case ConveyorBeltRight:
 
            *x = def_case[*y-2][(*x-2)/3 - 1].x;

            gotoXY(*x, *y);
 
            if (def_case[*y-2][(*x-2)/3].object >= ConveyorBeltUp && def_case[*y-2][(*x-2)/3].object <= ConveyorBeltRight) {
                afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
                onConvoyer(x, y, def_case);
            } else {
                afficherSnoopy(def_case[*y-2][(*x-2)/3].color);
                drawCase(def_case[*y-2][(*x-2)/3 + 1]);
                return;
            }
            break;
        
    }
}

void updateElement(int x, int y, value_case def_case[10][20], int action, int* snoopX, int* snoopY) {
    
    if (action == Punch) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (y+i < 0)    continue;
                if (y+i >= 10)  continue;
                if (x+j < 0)    continue;
                if (x+j >= 20)  continue;

                if (def_case[y+i][x+j].object == BrakableWall) {
                    def_case[y+i][x+j].object = Air;
                    stillDef_case[y+i][x+j].object = Air;

                    drawElement(
                        def_case[y+i][x+j].x,
                        def_case[y+i][x+j].y,
                        Air,
                        def_case[y+i][x+j].color
                    );
                }
            }
            
        }
        
    }

    switch (def_case[y][x].object) {
        case Bird:
            def_case[y][x].object = Air;
            stillDef_case[y][x].object = Air;
            drawCase(def_case[y][x]);

            break;
        case MouvableWall:
            if (action == MoveWallUp && y > 0 && def_case[y-1][x].object >= 5) { 
                def_case[y-1][x].object = Wall;
                stillDef_case[y-1][x].object = Wall;
                drawCase(def_case[y-1][x]);
                def_case[y][x].object = Air;
                stillDef_case[y][x].object = Air;
                drawCase(def_case[y+1][x]);
                gotoXY(def_case[y][x].x, def_case[y][x].y);
                *snoopY = def_case[y][x].y;
                afficherSnoopy(def_case[y][x].color);
            } 
            if (action == MoveWallDown && y < 9 && def_case[y+1][x].object >= 5){ 
                def_case[y+1][x].object = Wall;
                stillDef_case[y+1][x].object = Wall;
                drawCase(def_case[y+1][x]);
                def_case[y][x].object = Air;
                stillDef_case[y][x].object = Air;
                drawCase(def_case[y-1][x]);
                *snoopY = def_case[y][x].y;
                gotoXY(def_case[y][x].x, def_case[y][x].y);
                afficherSnoopy(def_case[y][x].color);
            } 
            if (action == MoveWallRight && x < 19 && def_case[y][x+1].object >= 5) { 
                def_case[y][x+1].object = Wall;
                stillDef_case[y][x+1].object = Air;
                drawCase(def_case[y][x+1]);
                def_case[y][x].object = Air;
                stillDef_case[y][x].object = Air;
                drawCase(def_case[y][x-1]);
                *snoopX = def_case[y][x].x;
                gotoXY(def_case[y][x].x, def_case[y][x].y);
                afficherSnoopy(def_case[y][x].color);
            } 
            if (action == MoveWallLeft && x > 0 && def_case[y][x-1].object >= 5) { 
                def_case[y][x-1].object = Wall;
                stillDef_case[y][x-1].object = Wall;

                drawCase(def_case[y][x-1]);
                def_case[y][x].object = Air;
                stillDef_case[y][x].object = Air;

                drawCase(def_case[y][x+1]);
                *snoopX = def_case[y][x].x;
                gotoXY(def_case[y][x].x, def_case[y][x].y);
                afficherSnoopy(def_case[y][x].color);
            }

            break;
    }


}



void display(value_case grille[10][20]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            drawCase(grille[i][j]);
        }
    }
}