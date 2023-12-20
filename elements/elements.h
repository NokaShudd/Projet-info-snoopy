#include "..\Snoopy\snoopyMovement.h"
#include "..\score\score.h"

#ifndef ELEMENTS
#define ELEMENTS


enum    actions         {
    None,
    MoveWallUp,
    MoveWallLeft,
    MoveWallDown,
    MoveWallRight,
    Punch,
};

enum    elements        {
    Wall, 
    BlinkingWall0,  // tangible
    MouvableWall,
    BrakableWall,
    BombWall,
    Ball0,          // vers Nord-Ouest
    Ball1,          // vers Sud-Ouest
    Ball2,          // vers Sud-Est
    Ball3,          // vers Nord-Est
    Ball4,
    Air,
    ConveyorBeltUp,//11
    ConveyorBeltLeft,//12
    ConveyorBeltDown,//13
    ConveyorBeltRight,//14
    BlinkingWall1,  // pas tangible
    Bird,
};


void    checkElements   (int[10][20], int, int, char, char, int);
void    updateElement   (int, int, value_case[10][20], int, int*, int*);

void    display             (value_case[10][20]);
void*   startIntervals      (int*, int*, int*, value_case[10][20], int*, tmStruct*);

void    onConvoyer          (int* ,int*, value_case[10][20]);
int     realBall            (int y, int x);

#endif