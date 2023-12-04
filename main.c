#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>
#include "Snoopy/snoopyMovement.h"
#include "elements/elements.h"

// ne pas supprimer (support macos / linux (j'espère))
#ifndef _WIN32

#include <curses.h>

#endif

#include "menu/mainmenu.h"

int main() {
    // ne pas supprimer non plus
#ifndef _WIN32

    initscr();
    refresh();

#endif


    kpStruct kps = {none, 0};
    getAsyncKey(&kps);

    menu(kps.k);
}