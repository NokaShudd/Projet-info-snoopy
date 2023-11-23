#include <stdio.h>
#include "utils\color.h"
#include "utils\size.h"


int main(){

    int size[2];

    getSize(size);

    colorPrintf(Red, "Hello world\n");
    colorPrintf(BoldBlue, "Taile : %dx%d", size[0], size[1]);

    return 0;
}