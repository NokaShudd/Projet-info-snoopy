#include "save.h"
#include <stdio.h>
#include <unistd.h>
#include "save.h"

int reading(int level, value_case def_case[10][20]){

    char* info[11];

    if (level == 1){
        *info = "level1.txt";
    }
    if (level == 2){
        *info = "level2.txt";
    }
    if (level == 3){
        *info = "level3.txt";
    }

    FILE* fptr = fopen(info, "r");

    if (fptr == NULL) {
        printf("Pas de ficher\n");
        return 0;
    }

    fseek(fptr, 0L, SEEK_END);
    long int res = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);

    char text[res];
    char letter;
    int previous = -1;

    int x, y;
    int color, object;

    int ind = 0;


    int pos10 = 0;
    int pos20 = 0;

    int SnoopX = -1 ;
    int SnoopY = -1;

    while (fgets(text, res, fptr)){
        ind = 0;
        for (int i = 0; text[i] != '\0' ; i++){
        letter = text[i];
        if (letter < (char) 58 && letter > (char) 47){
            if (previous >= 0) previous = previous * 10 + (int) letter - 48;
            else previous = (int) letter - 48;
        }
        else if (letter == ' ' && previous >= 0) {
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
        } else if (ind == 3){
            object = previous;
        }
        ind = (ind + 1) % 4;
        previous = -1;
    }
    else if (letter == '|') {
        def_case[pos10][pos20++] = (value_case) {
        x, y, color, object
        };
        x = 0; y = 0; color = 0; object = 0;
    }
    }
    if (text[0] != '#') {
        pos20 = 0;
        pos10++;
    }
    }

    printf("Pos is %d %d\n", SnoopX, SnoopY);

    for (int i = 0; i < 2; i++) {
        for (int a = 0; a < 3; a++) {
            printf(
            "Struct with %d %d %d %d\n",
            def_case[i][a].x, def_case[i][a].y, def_case[i][a].color, def_case[i][a].object
        );
    }
}
}



int sauvegarde(){

}