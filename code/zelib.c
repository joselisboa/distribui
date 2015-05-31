#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <windows.h>   // WinApi header

#define TRUE 1
#define true 1
#define FALSE 0
#define false 0

typedef enum _cores {
    BLACK = 0,
    BLUE_FADE,// = FOREGROUND_BLUE,
    GREEN_FADE,// = FOREGROUND_GREEN,
    CYAN_FADE,// = FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED_FADE,// = FOREGROUND_RED,
    MAGENTA_FADE,// = FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW_FADE,// = FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE_FADE,// = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY,// = FOREGROUND_INTENSITY,
    BLUE,// = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN,// = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN,// = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED,// = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA,// = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW,// = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE// = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
} Cores;

void die(char *msg){
    puts(msg);
    exit(EXIT_FAILURE);
}

void _linha(char c){
    int i;
    char s[81];
    for(i=0; i<80; i++) s[i] = c;
    s[i] = '\0';
    printf("%s", s);
}

void _entrelinhas(char c, char *format, ...){
    va_list args;
    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 8);
    _linha(c);
    SetConsoleTextAttribute(hConsole, 15);

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    SetConsoleTextAttribute(hConsole, 8);
    _linha(c);
    SetConsoleTextAttribute(hConsole, 7);
}

// colored puts
void putz(char *format, int k){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, k);
    puts(format);
    SetConsoleTextAttribute(hConsole, 7);
}

// colored printf
void printz(int k, char *format, ...){
    va_list args;
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, k);

    // argument list
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    SetConsoleTextAttribute(hConsole, 7);
}

void _printf(int k, char *format, ...){
    va_list args;

    // argument list
    va_start(args, format);
    printz(k, format, args);
    va_end(args);
}

//TODO switch arguments
void pause(char *msg){
    putz(msg, 4);
    getchar();
}

void halt(char *msg){
    putz(msg, 12);
    pause("press Enter to continue");
}
