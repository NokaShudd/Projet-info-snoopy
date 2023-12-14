#include "save.h"
#include <stdio.h>
#include "string.h"
#include <unistd.h>
#include "save.h"

void reading(int level, value_case def_case[10][20],int*X,int *Y, long long * timer) {
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

    fseek(fptr, 0L, SEEK_END);
    long int res = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);

    char text[res];
    char letter;
    int previous = -1;

    int x = 2, y = 2;
    int color = 3, object = 0;

    int ind = 0;


    int pos10 = 0;
    int pos20 = 0;

    int SnoopX = -1;
    int SnoopY = -1;
    long long tim = -1;

    while (fgets(text, res, fptr)) {
        ind = 0;
        for (int i = 0; text[i] != '\0'; i++) {
            letter = text[i];
            if (letter < (char) 58 && letter > (char) 47) {
                if (previous >= 0) previous = previous * 10 + (int) letter - 48;
                else previous = (int) letter - 48;
            } else if (letter == ' ' && previous >= 0) {
                if (text[0] == '#') {
                    if (SnoopX < 0) SnoopX = previous;
                    else if (SnoopY < 0) SnoopY = previous;
                    else tim = previous; 
                    previous = -1;
                    if (tim != -1) break;
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
                color = 3;
                object = 10;
            }
        }
        if (text[0] != '#') {
            pos20 = 0;
            pos10++;
        }
    }


    *X = SnoopX;
    *Y = SnoopY;
    *timer = tim;



}


void sauve(value_case def_case[10][20], int x, int y, long long timer) {
    FILE* fptr = fopen("..\\stockage\\data.txt", "w");
    fprintf(fptr, "# %d ",x);
    fprintf(fptr, "%d ",y);
    fprintf(fptr, "%lld ", timer);
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
