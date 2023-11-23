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

    int size[2];

    getSize(size);

    kpStruct kps = {e, 0};

    getAsyncKey(&kps);

    colorPrintf(Red, "Test pthread\n");

    while (1){

        if (kps.k == q){
            kps.shouldStop = 1;
            break;
        } else {
            printf("Log");
        }


        sleep(1);
    }
    

    return 0;
}