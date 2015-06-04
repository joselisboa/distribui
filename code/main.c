#include <stdio.h>
#include <stdlib.h>
#include "zelib.c"
#include "distribui.h"
#include "distribui.c"

void intro(){
    system("cls");
    char linha[81] = { '\0' };
    char *s = "21230536|Jose Lisboa";

    sprintf(linha, "%*s\n", 40+strlen(s)/2, s);
    zentrelinhas('-', linha);

    //pause("Qualquer Tecla Para Continuar");
}

void sair(){
    intro();
    die("Adeus");
}

void iniciar() {
    char option, c;
    int msg = FALSE;
    char buffer[255] = { '\0' };
    do {
        system("cls");
        intro();
        puts("1|Jogar  2|Dados  3|Ajuda  4|Sair");

        if(msg) putz(buffer, 11);
        else msg = TRUE;

        //scanf(" %d", &option);
        //fflush(stdin);

        switch(c = getch()){
            case '1':
                strcpy(buffer, "1|Jogar");
                //jogar();
                break;
            case '2':
                strcpy(buffer, "2|Dados");
                //dados();
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

    } while(TRUE);
}

int main(int argc, char *argv[]){
    intro();
    iniciar();
    
    /*
    //puts(pessoa1.nome);
    putz("putz BLUE", BLUE);
    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);
    pause("press enter to continue");
    */

    halt("adeus");
    die("bye");

    // will never get here
    exit(EXIT_SUCCESS);
}
