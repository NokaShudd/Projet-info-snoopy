#ifdef _WIN32

#include <conio.h>
#include <windows.h>

#else

#include <curses.h>
#include <pthread.h>

#endif

#include "keysHandler.h"

// donne la key correspondante au flèches
key handleArrow(){
    switch ( getch() ){
        case 'H': return arrowUp;
        case 'P': return arrowDown;    
        case 'M': return arrowRight;
        case 'K': return arrowLeft;
    }
}

// donne la key correspondant au charactère letter
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
        case '\r':  return enter; 

        default:
            return none;
    }
}


// donne le charactère correspondant à la key
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

#ifdef _WIN32

// récupère le charactère pressé en boucle (Windows)
DWORD WINAPI updateCharPressedW(LPVOID lpParam){
    cpStruct *arguments = (cpStruct *)lpParam;

    while (!arguments->shouldStop){
        arguments->c = (unsigned char) getch();
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return 0;
}

// récupère la touche pressé en boucle (Windows)
DWORD WINAPI updateKeyPressedW(LPVOID lpParam){
    kpStruct *arguments = (kpStruct *)lpParam;

    while (!arguments->shouldStop){
        arguments->k =charToKey(getch());
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return 0;
}

// récupère en boucle et de façon non-bloquante les charactères rentrés
HANDLE getAsyncChar(cpStruct* cps){
    return CreateThread(
        NULL, 0, updateCharPressedW, (void *)cps, 0, NULL
    );
}
// récupère en boucle et de façon non-bloquante les touches pressées
HANDLE getAsyncKey(kpStruct* kps){
    return CreateThread(
        NULL, 0, updateKeyPressedW, (void *)kps, 0, NULL
    );
}


#else

// récupère le charactère pressé en boucle (MacOs)
void *updateCharPressedM(void* lpParam){
    cpStruct *arguments = (cpStruct *)lpParam;

    while (!arguments->shouldStop){
        arguments->c = (unsigned char) getch();
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
    return NULL;
}


// récupère le charactère pressé en boucle (MacOs)
void *updateKeyPressedM(void* lpParam){
    kpStruct *arguments = (kpStruct *)lpParam;

    while (!arguments->shouldStop){
        arguments->k =charToKey(getch());
        // if (arguments->c == 'q') arguments->shouldStop = 1;
    }
    
}


void* getAsyncChar(cpStruct* cps){
    pthread_t tId;
    pthread_create(&tId, NULL, &updateCharPressedM, (void *)cps);
    return NULL;

}

void* getAsyncKey(kpStruct* kps){
    pthread_t tId;
    pthread_create(&tId, NULL, &updateKeyPressedM, (void *)kps);

    return NULL;

}

#endif

// renvoie la touche pressée
key getKey(){
    return charToKey((unsigned char) getch());
}

// renvoie le charactère pressé
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

#ifdef _WIN32

// arrète le thread
void closeThread(void* ht){
    CloseHandle(ht);
}

#else 

void closeThread(void* _){

    /*
        Ne fais rien, 
        existe seulement pour pas faire d'erreurs à la compilation
        Y'a interet que ça marche mtn     
    */

}

#endif