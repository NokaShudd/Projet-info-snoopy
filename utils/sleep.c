#ifdef _WIN32

#include <windows.h>

#else

#include <unistd.h>
#include <stdio.h>

#endif


// from https://stackoverflow.com/a/28827188
// sleep en millisecondes qui supporte unix et windows
void sleep_ms(unsigned long milliseconds){ 
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        fflush(stdout);
        if (milliseconds >= 1000)
        sleep(milliseconds / 1000);
        usleep((milliseconds % 1000) * 1000);
    #endif
}