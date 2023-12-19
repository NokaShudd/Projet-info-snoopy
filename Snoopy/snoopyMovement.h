//
// Created by herod on 27/11/2023.
//
#include "..\\score\\score.h"

#ifndef PROJET_INFO_SNOOPY_SNOOPYMOVEMENT_H
#define PROJET_INFO_SNOOPY_SNOOPYMOVEMENT_H

typedef struct value_case{
    int x;
    int y;
    int color;
    int object;
} value_case;

void afficherSnoopy(int);
void Movement(value_case[10][20], char k, int*, int*,int *,int *,tmStruct *, int *);
void grille(value_case[10][20]);


#endif //PROJET_INFO_SNOOPY_SNOOPYMOVEMENT_H
