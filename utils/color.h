#ifndef colors
#define colors

enum colorEnum {
    red, green, blue, yellow, cyan, magenta, white, black
};

typedef struct windowsTextAttributes{
    int fColors, bColors;
    short fInt, bInt;
    short underscore;
} wTxtAtt;

wTxtAtt newAttr             (int, int);

int     colorPrintf         (wTxtAtt, char*, ...);

#endif