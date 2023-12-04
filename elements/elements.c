#include "elements.h"
#include "..\utils\size.h"
#include "..\utils\color.h"

int setBallDirection(int grille[10][20], int x, int y){
    if (
        grille[y][x-1] < 10 && 
        grille[y][x+1] < 10 && 
        grille[y-1][x] < 10 && 
        grille[y+1][x] < 10 
        ){
        grille[y][x] = Ball4;
        return 0;
    }
    switch (grille[y][x]) {
    case Ball0:
        if (x == 0 || grille[y][x-1] < 10) {
            grille[y][x] = Ball3;
            return setBallDirection(grille, x, y);
        } 
        if (y == 0 || grille[y-1][x] < 10){
            grille[y][x] = Ball1;
            return setBallDirection(grille, x, y);
        }
        if (grille[y-1][x-1] < 10) {
            grille[y][x] = Ball2;
        }
        break;
    case Ball1:
        if (x == 0 || grille[y][x-1] < 10) {
            grille[y][x] = Ball2;
            return setBallDirection(grille, x, y);
        } 
        if (y == 9 || grille[y+1][x] < 10){
            grille[y][x] = Ball0;
            return setBallDirection(grille, x, y);
        }
        if (grille[y+1][x-1] < 10) {
            grille[y][x] = Ball3;
        }
        break;
        
    case Ball2:
        if (x == 19 || grille[y][x+1] < 10) {
            grille[y][x] = Ball1;
            return setBallDirection(grille, x, y);
        } 
        if (y == 9 || grille[y+1][x] < 10){
            grille[y][x] = Ball3;
            return setBallDirection(grille, x, y);
        }
        
        if (grille[y+1][x+1] < 10) {
            grille[y][x] = Ball0;
        }
        break;
        
    case Ball3:
        if (x == 19 || grille[y][x+1] < 10) {
            grille[y][x] = Ball0;
            return setBallDirection(grille, x, y);
        } 
        if (y == 0 || grille[y-1][x] < 10){
            grille[y][x] = Ball2;
            return setBallDirection(grille, x, y);
        }
        if (grille[y-1][x+1] < 10) {
            grille[y][x] = Ball1;
        }
        break;
    
    default:
        break;
    }
}


void checkElements(int grille[10][20], int x, int y, char blinkUpdate, char ticked, int action){
    int bufferBallePositions[200];
    int nbBalles = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            switch (grille[i][j]){
                case BlinkingWall0 :
                    if (blinkUpdate) grille[i][j] = BlinkingWall1;
                    continue;
                case BlinkingWall1:
                    if (blinkUpdate) grille[i][j] = BlinkingWall0;
                    continue;
                case MouvableWall:
                    if (x - i + y - j != 1 && x - i + y - j != -1) continue;
                    switch (action){
                        case MoveWallUp:
                            if (i > 0 && grille[i-1][j] == Air) {
                                grille[i-1][j] = Wall;
                                grille[i][j] = Air;
                            }
                            break;
                        case MoveWallLeft:
                            if (j > 0 && grille[i][j-1] == Air) {
                                grille[i][j-1] = Wall;
                                grille[i][j] = Air;
                            }
                            break;
                        case MoveWallDown:
                            if (i < 9 && grille[i+1][j] == Air) {
                                grille[i+1][j] = Wall;
                                grille[i][j] = Air;
                            }
                            break;
                        case MoveWallRight:
                            if (j < 19 && grille[i][j+1] == Air) {
                                grille[i][j+1] = Wall;
                                grille[i][j] = Air;
                            } 
                            break;
                        default: continue;
                    }
                case Ball0:
                case Ball1:
                case Ball2:
                case Ball3:
                case Ball4:
                    bufferBallePositions[nbBalles*2] = j;
                    bufferBallePositions[nbBalles*2 + 1] = i;
                    nbBalles++;
                    continue;
                default:
                    break;
            }
        }
    }   

    for (int i = 0; i < nbBalles*2; i += 2){
        setBallDirection(grille, bufferBallePositions[i], bufferBallePositions[i+1]);
        switch (grille[bufferBallePositions[i+1]][bufferBallePositions[i]]) {
            case Ball4:
                continue;
            case Ball0:
                grille[bufferBallePositions[i+1]][bufferBallePositions[i]] = Air;
                grille[bufferBallePositions[i+1]-1][bufferBallePositions[i]-1] = Ball0;
                continue;
            case Ball1:
                grille[bufferBallePositions[i+1]][bufferBallePositions[i]] = Air;
                grille[bufferBallePositions[i+1]+1][bufferBallePositions[i]-1] = Ball1;
                continue;
            case Ball2:
                grille[bufferBallePositions[i+1]][bufferBallePositions[i]] = Air;
                grille[bufferBallePositions[i+1]+1][bufferBallePositions[i]+1] = Ball2;
                continue;
            case Ball3:
                grille[bufferBallePositions[i+1]][bufferBallePositions[i]] = Air;
                grille[bufferBallePositions[i+1]-1][bufferBallePositions[i]+1] = Ball3;
                continue;
        }
    }
    
}

/*


    int grille[10][20];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            grille[i][j] = Air;
        }
        
    }
    

    grille[4][9] = Ball1;
    grille[9][5] = Ball0;
    grille[3][8] = Wall;
    grille[3][9] = Wall;
    grille[3][11] = Wall;
    grille[3][12] = Wall;
    
    display(grille);

    for (int i = 0; i < 1000; i++){
        checkElements(grille, 0, 0, 1, 1, 0);
        display(grille);
        // sleep(1);
    }

*/

void display(int grille[10][20]){

    gotoXY(0, 2);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            // colorPrintf(newAttr(green, black), "|");
            switch (grille[i][j]){
                case Air:
                case BlinkingWall1:
                    colorPrintf(newAttr(black, black), " ");

                    continue;
                case Wall:
                    colorPrintf(newAttr(black, white), " ");
                    continue;
                    
                case Ball0:
                case Ball1:
                case Ball2:
                case Ball3:
                case Ball4:
                    colorPrintf(newAttr(red, black), "o");
                    continue;

                default:
                    colorPrintf(newAttr(black, black), " ");
            }
        }
        // colorPrintf(newAttr(green, black), "|");
        // colorPrintf(newAttr(white, white), "\n");
        // for (int i = 0; i < 40; i++) colorPrintf(newAttr(green, black), "=");
        colorPrintf(newAttr(white, white), "\n");

        
    }
    

}