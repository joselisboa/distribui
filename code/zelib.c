#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <windows.h>   // WinApi header
#include "zelib.h"

int randz(int min, int max){
    return min + rand() % (max - min + 1);
}

int option(const char * const options[], int n){
    int i, escolha = 0;

    for(i=0; i < n; i++) {
        printz(8, " %d|", i+1 );
        printf("%s ", options[i]);
    }

    do {
        printf("\n> ");
        scanf("%d", &escolha);

    } while(escolha < 1 || escolha > n);

    return escolha;
}

//*/ EM DESENVOLVIMENTO
int optionz(const char * const options[], int n){
    int i, escolha = 0;
    char c;

    for(i=0; i < n; i++) {
        printz(8, " %d|", i+1 );
        printf("%s ", options[i]);
    }
    putchar('\n');
    do {
        c = getch();
        // 48='0', 57='9'
        if(c > 48 && c < 58) escolha = c - 48;
        else switch(c){
        case 10://putz("10: []", 12);
            break;
        case 13://putz("13: [ENTER]", 12);
            break;
        case 27://putz("27: [ESCAPE]", 12);
            return 0;
        case 32://enter
            //putz("32: [SPACE]", 12);
            break;
        case -32:// setas
            switch(c = getch()){
                case 72:
                    //putz("72: [CIMA]", 13);
                    break;
                case 80:
                    //putz("80: [BAIXO]", 13);
                    break;
                case 75:
                    //putz("75: [ESQUERDA]", 13);
                    break;
                case 77:
                    //putz("77: [DIREITA]", 13);
                    break;
                default:;
                    //printz(13, "%d: %c\n", c, c);
            }
            break;
        default:;
            //printz(12, "%d: %c\n", c, c);
        }

    } while(escolha < 1 || escolha > n);

    return escolha;
}
//*/

void zenter(char *s){
    char linha[81] = { '\0' };
    sprintf(linha, "%*s\n", 40+strlen(s)/2, s);
    zentrelinhas('-', linha);
}

void zenterK(char *s, int k){
    char linha[81] = { '\0' };
    sprintf(linha, "%*s", 40+strlen(s)/2, s);
    putz(linha, k);
}

void zenter_cls(char *s){
    system("cls");
    zenter(s);
}

// um free mais seguro (põe o ponteiro NULO)
void _zeFree(void **pp){
    if(pp != NULL && *pp != NULL){
        free(*pp);
        *pp = NULL;
    }
}

void die(char *msg){
    printf("%s", msg);
    exit(EXIT_FAILURE);
}

void _linha(char c){
    int i;
    char s[81];
    for(i=0; i<80; i++) s[i] = c;
    s[i] = '\0';
    printf("%s", s);
}

void zentrelinhas(char c, char *format, ...){
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
    zenterK(msg, 8);
    getch();
}

void pausa(){
    puts("");
    pause("premir qualquer tecla para continuar");
}

void halt(char *msg){
    putz(msg, 12);
    pause("press Enter to continue");
}


/*
char buff[] = "hello world";
trimstr(buff, 1, -1);// "ello worl"
*/
char *trimstr(char *buff, int a, int b) {
    int i, len = strlen(buff);
    if (a < 0 || b > 0) return buff;
    if (a == 0 && b == 0) return buff;
    if (a > len + b) return buff;

    if (a == 0) {
        buff[len + b] = '\0';
        return buff;
    }

    for (i = 0; a + i < len + b; i++) {
        buff[i] = buff[a + i];
    }

    buff[i] = '\0';

    return buff;
}

/*
char buff[] = "the fast fox";
trimstr(buff, 2, 8);// "e fast f"
*/
char *substr(char *buff, int i, int n) {
    return trimstr(buff, i, i + n - strlen(buff));

    //char subbuff[255];
    //if (i + n > 254 || i+n > strlen(buff)) return buff;
    //memcpy(subbuff, &buff[i], len);
    //subbuff[i+len] = '\0';
    //strcpy_s(buff, strlen(buff) + 1, subbuff);
    //return buff;
}

char *caps(char buff[])
{
    unsigned int i;
    for (i = 0; i < strlen(buff); i++)
        buff[i] = toupper(buff[i]);

    return buff;
}


int file_exists(char fname[]){
    if(access(fname, F_OK) != -1) return 1;
    return 0;
}

void Info(const char * const *keys, const char * const *values, const int n){
    int i;
    for(i=0; i < n; i++) {
        printz(11, "[%-5s] ", keys[i]);
        printz(7, "%s\n", values[i]);
    }
    pausa();
}
