#include "score.h"
#include <stdio.h>
#include <time.h>

void timer (int* time_left){
    time_t debut = time(NULL);
    time_t maintenant;
    maintenant = time(NULL);
    int temps_ecoule = maintenant - debut;
    *time_left = *time_left - temps_ecoule;
    }