#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <windows.h>   // WinApi header
#include "zelib.h"

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

/*/ DEVELOPMENT
int zoption(const char * const options[], int n){
    int i, escolha = 0;
    char c;

    for(i=0; i < n; i++) {
        printz(8, " %d|", i+1 );
        printf("%s ", options[i]);
    }

    do {
        printf("\n> ");

        //scanf("%d", &escolha);

        switch(c = getch()){
            case '1':
                strcpy(buffer, "1|Jogar");
                //jogar(pessoas);
                break;
            case '2':
                //strcpy(buffer, "2|Dados");
                pessoas = dados(pessoas);

                break;
            case '3':
                strcpy(buffer, "3|Ajuda");
                //ajuda();
                break;
            case '4':
                sair();
                break;
            default:
                sprintf(buffer, "opcao '%c' invalida", c);
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
    putz(msg, 8);
    getch();
}

void pausa(){
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

