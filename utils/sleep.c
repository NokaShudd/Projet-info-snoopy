#include "sys/time.h"

long long timeInMilliseconds() {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void Sleep(long millisecond){
    long long oldTimer, currentTimer;
    oldTimer = timeInMilliseconds();
    while (1){
        currentTimer = timeInMilliseconds();
        if ((currentTimer - oldTimer) >= millisecond){
            return;
        };    
    }
}