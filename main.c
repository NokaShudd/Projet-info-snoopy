#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include "utils\keysHandler.h"
#include <unistd.h>


// typedef struct resizeEvent{
//     int size[2];
//     int shouldStop;
// } rsEvent;


// void *updateSize(void *args){
//     rsEvent *arguments = (rsEvent *)args;

//     while (!arguments->shouldStop){
//         getSize(arguments->size);

//         // if (arguments->c == 'q') arguments->shouldStop = 1;
//     }
    
//     return NULL;
// }



// void startResizeLoop(rsEvent* rse){
//     pthread_t thread_id; 
//     pthread_create(&thread_id, NULL, updateSize, (void *)rse); 
// }


int main(){

    wTxtAtt attr = newAttr(black, white);

    int size[2];

    getSize(size);

    for (int i = 0; i < size[1]/2; i++){
        for (int j = 0; j < size[0]/2; j++){
            if ((j+i%2)%2) {
                attr.bColors = cyan;
            } else {
                attr.bColors = yellow;
            }
            colorPrintf(attr, " ");
        }
        printf("\n");
        
    }
    
    horribleGotoXY(5, 9);

    printf("123");

    getChar();


    return 0;
}