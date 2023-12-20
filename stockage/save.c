#include "save.h"
#include <stdio.h>
#include "string.h"
#include <unistd.h>
#include "save.h"

void reading(int *level, value_case def_case[10][20],int*X,int *Y, int* vie, long long * timer, long long *score, int * oiseau) {
    //test partie enregistré sinon lancé sur partie 1
    char info[25];

    if (*level == 0) {
        strncpy(info, "..\\stockage\\data.txt", 25);
    }
    if (*level == 1) {
        strncpy(info, "..\\stockage\\level1.txt", 25);
    }
    if (*level == 2) {
        strncpy(info, "..\\stockage\\level2.txt", 25);
    }

    if (*level == 3) {
        strncpy(info, "..\\stockage\\level3.txt", 25);
    }

    if (*level == 4) {
        strncpy(info, "..\\stockage\\level4.txt", 25);
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

    *score = -1;
    int svie = -1;
    *level = -1;
    *oiseau = -1; 

    while (fgets(text, res, fptr)) {
        ind = 0;
        for (int i = 0; text[i] != '\0'; i++) {
            letter = text[i];
            if (letter < (char) 58 && letter > (char) 47) {
                if (previous >= 0) previous = previous * 10 + (int) letter - 48;
                else previous = (int) letter - 48;
            } else if ((letter == ' '|| letter == '\n') && previous >= 0) {
                if (text[0] == '#') {
                    if (SnoopX < 0) SnoopX = previous;
                    else if (SnoopY < 0) SnoopY = previous;
                    else if (tim < 0) tim = previous; 
                    else if (*score < 0) *score = previous; 
                    else if (svie < 0) svie = previous;
                    else if (*level < 0) *level = previous;
                    else if (*oiseau < 0) *oiseau = previous;
                    previous = -1;
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
    *vie = svie;


    if (*oiseau < 0) *oiseau = 0;

    if (*vie < 0) *vie = 3;

    if (*score == -1) *score = 0;

    *score = *score;



}


void sauve(value_case def_case[10][20], int x, int y, long long timer, long long score,int vie, int level, int oiseau) {
    FILE* fptr = fopen("..\\stockage\\data.txt", "w");
    fprintf(fptr, "# %d ",x);
    fprintf(fptr, "%d ",y);
    fprintf(fptr, "%lld ", timer);
    fprintf(fptr, "%lld ", score);
    fprintf(fptr, "%d ", vie);
    fprintf(fptr, "%d ", level);
    fprintf(fptr, "%d ", oiseau);
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

void inv2llong(long long *var1, long long *var2) {
    *var1 += *var2;
    *var2 = *var1 - *var2;
    *var1 -= *var2;
}

void getScores(long long scores[3]) {
    FILE *fptr = fopen("..\\stockage\\bestScore.txt", "r");

    fseek(fptr, 0L, SEEK_END);
    long int res = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);

    int pos = 0;

    char text[res];
    

    while (fgets(text, res, fptr)) {
        long long number = -1;
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] < (char) 58 && text[i] > (char) 47) {
                if (number != -1) number *= 10;
                else number = 0;
                number += text[i] - 48;
            }
        }


        if (number == -1) number = 0; 
        scores[pos] = number;


        pos++;
    }

    fclose(fptr);


    // Sort

    if (scores[0] < scores[1]) inv2llong(&scores[0], &scores[1]);
    
    if (scores[1] < scores[2]) inv2llong(&scores[1], &scores[2]);

    if (scores[0] < scores[1]) inv2llong(&scores[0], &scores[1]);


}

void saveScore(long long score) {
    long long scores[3];

    getScores(scores);

    int state = 0; // searching
    long long buffer = 0;

    for (int i = 0; i < 3; i++) {
        if (state == 0) {
            if (score > scores[i]) {
                printf(" %lld > %lld\n", score, scores[i]);
                state = 1;
                buffer = score;
                continue;
            }
        }
        if (state) {
            if (i == 2) {
                scores[1] = buffer;
                break;
            } 
            inv2llong(&buffer, &scores[i]);
        }
    }
    

    FILE* fptr = fopen("..\\stockage\\bestScore.txt", "w");
    fprintf(fptr, "%lld\n", scores[0]);
    fprintf(fptr, "%lld\n", scores[1]);
    fprintf(fptr, "%lld", scores[2]);
    fclose(fptr);

}