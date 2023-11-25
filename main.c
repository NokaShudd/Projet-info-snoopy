#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>

int main(){

    kpStruct kps = {none, 0};

    getAsyncKey(&kps);

    while (1){
        colorPrintf(newAttr(white, black), "Key pressed is : %c\n", keyToChar(kps.k));

        if (kps.k == q) {kps.shouldStop = 1; break;}


        sleep(1);
    }
    

    return 0;
}