#ifndef ZLIB
#define ZLIB

#define TRUE 1
#define true 1
#define FALSE 0
#define false 0

// macro para não ser necessário casting ou referencia do ponteiro
#define zeFree(p) _zeFree((void **)&(p));
void _zeFree(void **);

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

int option(const char * const [], int);
int optionz(const char * const [], int);
void zenter(char *);
void zenterK(char *, int);
void zenter_cls(char *);
void die(char *);
void _linha(char);
void zentrelinhas(char, char *, ...);

void putz(char *, int);
void printz(int, char *, ...);
void _printf(int, char *, ...);
void pausa();
void pause(char *);
void halt(char *);
char *trimstr(char *, int, int);
char *substr(char *, int, int);
char *caps(char []);

int file_exists(char []);

#endif

