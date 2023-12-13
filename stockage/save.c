#include "save.h"
#include <stdio.h>
#include "string.h"
#include <unistd.h>
#include "save.h"

void reading(int level, value_case def_case[10][20],int*X,int *Y) {
    //test partie enregistré sinon lancé sur partie 1
    char info[25];

    if (level == 0) {
        strncpy(info, "..\\stockage\\data.txt", 25);
    }
    if (level == 1) {
        strncpy(info, "..\\stockage\\level1.txt", 25);
    }
    if (level == 2) {
        strncpy(info, "..\\stockage\\level2.txt", 25);
    }

    if (level == 3) {
        strncpy(info, "..\\stockage\\level3.txt", 25);
    }


    FILE *fptr = fopen(info, "r");

    long int res = 100000;

    char text[res];
    char letter;
    int previous = -1;

    int x, y;
    int color, object;

    int ind = 0;

    int pos10 = 0;
    int pos20 = 0;

    int SnoopX = -1;
    int SnoopY = -1;


    while (fgets(text, res, fptr) != NULL) {
        ind = 0;
        for (int i = 0; text[i] != '\0'; i++) {
            letter = text[i];
            if (letter < (char) 58 && letter > (char) 47) {
                if (previous >= 0) previous = previous * 10 + (int) letter - 48;
                else previous = (int) letter - 48;
            } else if (letter == ' ' && previous >= 0) {
                if (text[0] == '#') {
                    if (SnoopX < 0) SnoopX = previous;
                    else SnoopY = previous;
                    previous = -1;
                    if (SnoopY != -1) break;
                    continue;
                }
                if (ind == 0) {
                    x = previous;
                } else if (ind == 1) {
                    y = previous;
                } else if (ind == 2) {
                    color = previous;
                } else if (ind == 3) {
                    object = previous;
                }
                ind = (ind + 1) % 4;
                previous = -1;
            } else if (letter == '|') {
                def_case[pos10][pos20++] = (value_case) {
                        x, y, color, object
                };
                x = 2;
                y = 2;
                color = 0;
                object = 0;
            }
        }
        if (text[0] != '#') {
            pos20 = 0;
            pos10++;
        }
    }


    *X = SnoopX;
    *Y = SnoopY;
}


void sauve(value_case def_case[10][20], int x, int y) {
    FILE* fptr = fopen("..\\stockage\\data.txt", "w");
    fprintf(fptr, "# %d ",x);
    fprintf(fptr, "%d ",y);
    fprintf(fptr, "\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            fprintf(fptr, "%d ", def_case[i][j].x);
            fprintf(fptr, "%d ", def_case[i][j].y);
            fprintf(fptr, "%d ", def_case[i][j].color);
            fprintf(fptr, "%d |", def_case[i][j].object);
        }
        fprintf(fptr, "\n");
    }

    //Close file to save file data
    fclose(fptr);
}
