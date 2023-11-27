#include <conio.h>
#include <windows.h>
#include "keysHandler.h"


key handleArrow(){
    switch ( getch() ){
        case 'H': return arrowUp;
        case 'P': return arrowDown;    
        case 'M': return arrowRight;
        case 'K': return arrowLeft;
    }
}


key charToKey(unsigned char letter){
    switch (letter){
        case 0   :  return handleArrow();
        case 0xE0:  return handleArrow();
        case 'a' :  return a;         
        case 'b' :  return b;         
        case 'c' :  return c;         
        case 'd' :  return d;         
        case 'e' :  return e;         
        case 'f' :  return f;         
        case 'g' :  return g;         
        case 'h' :  return h;         
        case 'i' :  return i;         
        case 'j' :  return j;         
        case 'k' :  return k;         
        case 'l' :  return l;         
        case 'm' :  return m;         
        case 'n' :  return n;         
        case 'o' :  return o;         
        case 'p' :  return p;         
        case 'q' :  return q;         
        case 'r' :  return r;         
        case 's' :  return s;         
        case 't' :  return t;         
        case 'u' :  return u;         
        case 'v' :  return v;         
        case 'w' :  return w;         
        case 'x' :  return x;         
        case 'y' :  return y;         
        case 'z' :  return z;
        case '\n':  return enter;   // FIXME marche pas pour entrer 

        default:
            return none;
    }
}




char keyToChar(key k_){
    switch (k_){
        case arrowLeft  :  return '<';
        case arrowRight :  return '>';
        case arrowUp    :  return '^';
        case arrowDown  :  return 'v';
        case a          :  return 'a';         
        case b          :  return 'b';         
        case c          :  return 'c';         
        case d          :  return 'd';         
        case e          :  return 'e';         
        case f          :  return 'f';         
        case g          :  return 'g';         
        case h          :  return 'h';         
        case i          :  return 'i';         
        case j          :  return 'j';         
        case k          :  return 'k';         
        case l          :  return 'l';         
        case m          :  return 'm';         
        case n          :  return 'n';         
        case o          :  return 'o';         
        case p          :  return 'p';         
        case q          :  return 'q';         
        case r          :  return 'r';         
        case s          :  return 's';         
        case t          :  return 't';         
        case u          :  return 'u';         
        case v          :  return 'v';         
        case w          :  return 'w';         
        case x          :  return 'x';         
        case y          :  return 'y';         
        case z          :  return 'z';
        case enter      :  return '\n';   

        default:
            return ' ';
    }
}

DWORD WINAPI updateCharPressedW(LPVOID lpParam){
    cpStruct *arguments = (cpStruct *)lpParam;

    while (!arguments->shouldStop){
        arguments->c = (unsigned char) getch();
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return 0;
}


void *updateCharPressed(void *args){
    cpStruct *arguments = (cpStruct *)args;

    while (!arguments->shouldStop){
        arguments->c = (unsigned char) getch();
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return NULL;
}

DWORD WINAPI updateKeyPressedW(LPVOID lpParam){
    kpStruct *arguments = (kpStruct *)lpParam;

    while (!arguments->shouldStop){
        arguments->k =charToKey(getch());
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return 0;
}

void *updateKeyPressed(void *args){
    kpStruct *arguments = (kpStruct *)args;

    while (!arguments->shouldStop){
        arguments->k = charToKey(getch());
        // if (arguments->k == q) arguments->shouldStop = 1;
    }
    
    return NULL;
}


HANDLE getAsyncChar(cpStruct* cps){
    return CreateThread(
        NULL, 0, updateCharPressedW, (void *)cps, 0, NULL
    );
}

HANDLE getAsyncKey(kpStruct* kps){
    return CreateThread(
        NULL, 0, updateKeyPressedW, (void *)kps, 0, NULL
    );
}



key getKey(){
    return charToKey((unsigned char) getch());
}

char getChar(){
    char v = getch();
    if (v == 0 || v == 0xE0){
        switch (getch()){
            case 'H': return '^';
            case 'P': return 'v';
            case 'M': return '>';
            case 'K': return '<';
        }
    }
    return v;
}

void closeThread(void* ht){
    CloseHandle(ht);
}