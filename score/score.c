#include "score.h"
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "..\utils\sleep.h"
#include "..\utils\size.h"


DWORD WINAPI timer_score (LPVOID timeur) {
    long long * time_left = (long long *)timeur;
    while (*time_left > 0) {
        *time_left = *time_left - 1;
        gotoXY(28,1);
        printf("%lld   ", *time_left *100);
        sleep_ms(1000);
    }
}

HANDLE Start_timer(long long * time_left){
    return CreateThread(
            NULL, 0, timer_score, (void *)time_left, 0, NULL
    );
}