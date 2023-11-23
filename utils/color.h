#define Black           "\033[0;30m"
#define Red             "\033[0;31m"
#define Green           "\033[0;32m"
#define Yellow          "\033[0;33m"
#define Blue            "\033[0;34m"
#define Purple          "\033[0;35m"
#define Cyan            "\033[0;36m"
#define White           "\033[0;37m"
#define BoldBlack       "\033[1;30m"
#define BoldRed         "\033[1;31m"
#define BoldGreen       "\033[1;32m"
#define BoldYellow      "\033[1;33m"
#define BoldBlue        "\033[1;34m"
#define BoldPurple      "\033[1;35m"
#define BoldCyan        "\033[1;36m"
#define BoldWhite       "\033[1;37m"

#define BgBlack           "\033[0;40m"
#define BgRed             "\033[0;41m"
#define BgGreen           "\033[0;42m"
#define BgYellow          "\033[0;43m"
#define BgBlue            "\033[0;44m"
#define BgPurple          "\033[0;45m"
#define BgCyan            "\033[0;46m"
#define BgWhite           "\033[0;47m"
#define BgBoldBlack       "\033[0;100m"
#define BgBoldRed         "\033[0;101m"
#define BgBoldGreen       "\033[0;102m"
#define BgBoldYellow      "\033[0;103m"
#define BgBoldBlue        "\033[0;104m"
#define BgBoldPurple      "\033[0;105m"
#define BgBoldCyan        "\033[0;106m"
#define BgBoldWhite       "\033[0;107m"

#ifndef colors
#define colors


int     colorPrintf         (char[8], char*, ...);
int     humanColorTest      ();

#endif