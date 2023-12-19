//
// Created by herod on 05/12/2023.
//
#include "..\Snoopy\snoopyMovement.h"

#ifndef PROJET_INFO_SNOOPY_SAVE_H
#define PROJET_INFO_SNOOPY_SAVE_H

void reading(int* level, value_case[10][20], int *, int *, int *, long long *, long long *, int*);
void sauve(value_case[10][20], int x, int y, long long, long long, int, int, int);

void saveScore(long long);
void getScores(long long scores[3]);

#endif //PROJET_INFO_SNOOPY_SAVE_H
