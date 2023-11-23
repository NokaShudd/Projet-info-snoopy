#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"
#include <pthread.h>
#include <unistd.h>


typedef struct resizeEvent{
    int size[2];
    int shouldStop;
} rsEvent;


void *updateSize(void *args){
    rsEvent *arguments = (rsEvent *)args;

    while (!arguments->shouldStop){
        getSize(arguments->size);

        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return NULL;
}



void startResizeLoop(rsEvent* rse){
    pthread_t thread_id; 
    pthread_create(&thread_id, NULL, updateSize, (void *)rse); 
}


int main(){

    int size[2];

    getSize(size);

    colorPrintf(Red, "Hello world\n");
    colorPrintf(BoldBlue, "Taile : %dx%d", size[0], size[1]);

    int oldsize[2];

    getSize(oldsize);

    rsEvent rse = {size, 0};
    startResizeLoop(&rse);

    while (1){
        if (rse.size[0] != oldsize[0] || rse.size[1] != oldsize[1]) {
            printf("changement taille\n");
            oldsize[0] = rse.size[0];
            oldsize[1] = rse.size[1];
        }
        printf("%dx%d\n", rse.size[0], rse.size[1]);


        sleep(1);
    }
    

    return 0;
}