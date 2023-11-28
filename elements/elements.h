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
    ConveyorBeltUp,
    ConveyorBeltLeft,
    ConveyorBeltDown,
    ConveyorBeltRight,
    BlinkingWall1,  // pas tangible
    Bird,
};

void    checkElements   (int[10][20], int, int, char, char, int);

// temporaire, mais necessaire

void    display         (int[10][20]);

#endif