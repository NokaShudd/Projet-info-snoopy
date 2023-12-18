#include "elements.h"
#include "..\utils\size.h"
#include "..\utils\color.h"
#include "..\Snoopy\snoopyMovement.h"
#include "..\utils\sleep.h"
#include <windows.h>


value_case *geneDef_case[10][20];

int setBallDirection(value_case *grille[10][20], int x, int y){
    if (
        grille[y][x-1]->object < 10 && 
        grille[y][x+1]->object < 10 && 
        grille[y-1][x]->object < 10 && 
        grille[y+1][x]->object < 10 
        ){
        grille[y][x]->object = Ball4;
        return Ball4;
    }
    switch (grille[y][x]->object) {
        case Ball0:
            if (x == 0 || grille[y][x-1]->object < 10) {
                grille[y][x]->object = Ball3;
                return setBallDirection(grille, x, y);
            } 
            if (y == 0 || grille[y-1][x]->object < 10){
                grille[y][x]->object = Ball1;
                return setBallDirection(grille, x, y);
            }
            if (grille[y-1][x-1]->object < 10) {
                grille[y][x]->object = Ball2;
                return Ball2;
            }
        break;
        
        case Ball1:
            if (x == 0 || grille[y][x-1]->object < 10) {
                grille[y][x]->object = Ball2;
                return setBallDirection(grille, x, y);
            } 
            if (y == 9 || grille[y+1][x]->object < 10){
                grille[y][x]->object = Ball0;
                return setBallDirection(grille, x, y);
            }
            if (grille[y+1][x-1]->object < 10) {
                grille[y][x]->object = Ball3;
                return Ball3;
            }
        break;
            
        case Ball2:
            if (x == 19 || grille[y][x+1]->object < 10) {
                grille[y][x]->object = Ball1;
                return setBallDirection(grille, x, y);
            } 
            if (y == 9 || grille[y+1][x]->object < 10){
                grille[y][x]->object = Ball3;
                return setBallDirection(grille, x, y);
            }
            
            if (grille[y+1][x+1]->object < 10) {
                grille[y][x]->object = Ball0;
                return Ball0;
            }
        break;
            
        case Ball3:
            if (x == 19 || grille[y][x+1]->object < 10) {
                grille[y][x]->object = Ball0;
                return setBallDirection(grille, x, y);
            } 
            if (y == 0 || grille[y-1][x]->object < 10){
                grille[y][x]->object = Ball2;
                return setBallDirection(grille, x, y);
            }
            if (grille[y-1][x+1]->object < 10) {
                grille[y][x]->object = Ball1;
                return Ball1;
            }
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
            colorPrintf(newAttr(cyan, color), " %c ", 0x1F);
        return;
        case ConveyorBeltUp:
            colorPrintf(newAttr(cyan, color), " %c ", 0x1E);
        return;
        case ConveyorBeltLeft:
            colorPrintf(newAttr(cyan, color), " %c ", 0x10);
        return;
        case ConveyorBeltRight:
            colorPrintf(newAttr(cyan, color), " %c ", 0x11);
        return;

        case BrakableWall:
            colorPrintf(newAttr(yellow, color), "%c%c%c", 0xB1, 0xB1, 0xB1);
        return;
        
        case Ball0:
        case Ball1:
        case Ball2:
        case Ball3:
        case Ball4:
            colorPrintf(newAttr(red, color), " o ");
        return;
        
        case MouvableWall:
            colorPrintf(newAttr(white, white), " %c ", 0xB1);
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

void moveBall(value_case *grille[10][20]){
    int xBuffer[200];
    int yBuffer[200];
    int numbPair = 0;


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (grille[i][j]->object > 4 && grille[i][j]->object < 10) {
                xBuffer[numbPair]   = j;
                yBuffer[numbPair++] = i;
            }
        }
        
    }


    for (int i = 0; i < numbPair; i++) {
        int a = setBallDirection(grille, xBuffer[i] * 3 + 2, yBuffer[i] + 2);
        printf("%d", a);
        switch (grille[yBuffer[i]][xBuffer[i]]->object) {
            case Ball0:
                grille[yBuffer[i]-1][xBuffer[i]-1]->object = Ball0;
                drawCase(*grille[yBuffer[i]-1][xBuffer[i]-1]);
                break;
            case Ball1:
                grille[yBuffer[i]+1][xBuffer[i]-1]->object = Ball1;
                drawCase(*grille[yBuffer[i]+1][xBuffer[i]-1]);
                break;
            case Ball2:
                grille[yBuffer[i]+1][xBuffer[i]+1]->object = Ball2;
                drawCase(*grille[yBuffer[i]+1][xBuffer[i]+1]);
                break;
            case Ball3:
                grille[yBuffer[i]-1][xBuffer[i]+1]->object = Ball3;
                drawCase(*grille[yBuffer[i]-1][xBuffer[i]+1]);
                break;
        }
        if (grille[yBuffer[i]][xBuffer[i]]->object != Ball4) grille[yBuffer[i]][xBuffer[i]]->object = Air;
        drawCase(*grille[yBuffer[i]][xBuffer[i]]);
    }
    
    
}


void changeBlinkState(value_case *grille[10][20]){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if ((*grille[i][j]).object == BlinkingWall0) {
                (*grille[i][j]).object = BlinkingWall1;
                drawCase(*grille[i][j]);
            }
            else if ((*grille[i][j]).object == BlinkingWall1) {
                (*grille[i][j]).object = BlinkingWall0;
                drawCase(*grille[i][j]);            
            }
        }
    }
}

DWORD WINAPI changeAfterInterval(LPVOID lparam) {
    int numb = 0;

    sleep_ms(14);


    while (1){
        sleep_ms(500);

        moveBall(geneDef_case);

        if (numb == 3) changeBlinkState(geneDef_case);

        numb = ++numb % 4;
    }
    
    return 0;
}


HANDLE startIntervals(value_case def_case[10][20]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            geneDef_case[i][j] = &def_case[i][j]; 
        }
    }
    
    return CreateThread(
        NULL, 0, changeAfterInterval, NULL, 0, NULL
    );
}



void updateElement(int x, int y, value_case def_case[10][20], int action){
    x = (x - 2) / 3;
    y-=2;
    if (action == Punch) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (y+i < 0)    continue;
                if (y+i >= 10)  continue;
                if (x+j < 0)    continue;
                if (x+j >= 20)  continue;

                if (def_case[y+i][x+j].object == BrakableWall) {
                    def_case[y+i][x+j].object = Air;
                }
            }
            
        }
        
        return;
    }
    switch (def_case[y][x].object) {
        case Bird:
            def_case[y][x].object = Air;
            break;
        case MouvableWall:
            if (action == MoveWallUp) {
                drawElement(def_case[y-1][x].x, def_case[y-1][x].y, Wall, def_case[y-1][x].color);
            } else if (action == MoveWallDown){ 
                drawElement(def_case[y+1][x].x, def_case[y+1][x].y, Wall, def_case[y+1][x].color);
            } else if (action == MoveWallRight) {
                drawElement(def_case[y][x+1].x, def_case[y][x+1].y, Wall, def_case[y][x+1].color);
            } else {
                drawElement(def_case[y][x-1].x, def_case[y][x-1].y, Wall, def_case[y][x-1].color);
            }
            def_case[y][x].object = Air;
            break;
    }
};


void display(value_case grille[10][20]){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            drawCase(grille[i][j]);
        }
    }
}