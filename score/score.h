#ifndef GAME_SCORE_H
#define GAME_SCORE_H

typedef struct timerStruct{
    long long* time_left;
    int shouldStop;
}tmStruct;

void* Start_timer(tmStruct *);
void affichage_vie(int, tmStruct*, int *);
int affichage_oiseau(int);
void setContour();

#endif //GAME_SCORE_H
