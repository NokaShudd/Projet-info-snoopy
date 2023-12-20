#include <windows.h>


// from https://stackoverflow.com/a/28827188
// sleep en millisecondes qui supporte unix et windows
void sleep_ms(unsigned long milliseconds){ 
    Sleep(milliseconds);
}