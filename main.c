// #include <unistd.h>
// #include "utils\color.h"
// #include "utils\size.h"
// #include "utils\keysHandler.h"
#include "stdio.h"
#include "utils/sleep.h"
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"

// ne pas supprimer (support macos / linux (j'espère))
#ifndef _WIN32

#include <curses.h>

#endif

int main(){
    // ne pas supprimer non plus
    #ifndef _WIN32

    initscr();
    refresh();

    #endif


    printf("test");

    sleep_ms(3500);

    printf("test");
    
    
    
    
    return 0;
}