#include <stdio.h>
#include "utils/color.h"
#include "utils/size.h"
#include "utils/keysHandler.h"
#include <unistd.h>
#include <string.h>

// ne pas supprimer (support macos / linux (j'espère))
#ifndef _WIN32

#include <ncurses.h>

#endif


int main(){
    // ne pas supprimer non plus
    #ifndef _WIN32

    initscr();
    refresh();

    #endif

    kpStruct kps = {none, 0};

    void* th = getAsyncKey(&kps);

    while (!kps.shouldStop){
        printf("key is %c", keyToChar(kps.k));

        if (kps.k == q) kps.shouldStop = 1;

        sleep(1);
    }

    closeThread(th);
    
    


    return 0;
}