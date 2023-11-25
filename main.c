#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>

int main(){

    // exemple
    colorPrintf(newAttr(red, yellow), "test\n");

    // toute les couleurs
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            colorPrintf(newAttr(i, j), "test");
        }
        printf("\n");
    }
    

    kpStruct kps = {none, 0};

    void* hT = getAsyncKey(&kps);

    while (1){
        colorPrintf(newAttr(white, black), "Key pressed is : %c\n", keyToChar(kps.k));

        if (kps.k == q) {kps.shouldStop = 1; break;}


        sleep(1);
    }
    
    closeThread(hT);

    return 0;
}