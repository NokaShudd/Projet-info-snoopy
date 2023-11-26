#ifndef KEYSHANDLER 
#define KEYSHANDLER

typedef enum key{
    a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
    arrowLeft, arrowRight, arrowUp, arrowDown,
    enter, escape, none 
} key;

typedef struct charPressedStruct{
    char c;
    int shouldStop;
} cpStruct;


typedef struct keyPressedStruct{
    key k;
    int shouldStop;
} kpStruct;


key     charToKey       (unsigned char);
char    keyToChar       (key);

key     getKey          ();
char    getChar         ();

void*   getAsyncKey     (kpStruct*);
void*   getAsyncChar    (cpStruct*);

void    closeThread(void *);
#endif 
