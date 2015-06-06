#include <stdio.h>
#include <string.h>
#include "zelib.h"
#include "distribui.h"
#include "dados.h"


Pessoa criar_pessoa(char *nome, int idade){
    Pessoa pessoa;
    pessoa.id = ++Id;
    strcpy(pessoa.nome, nome);
    pessoa.idade = (unsigned int) idade;
    return pessoa;
}

Jogador criar_jogador(Pessoa pessoa){
    Jogador jogador;
    return jogador;
}

void splash(){
    system("cls");
    zenter("21230536|Jose Lisboa");
    pause("Qualquer Tecla Para Continuar");
    system("cls");
}

void iniciar() {
    Pessoa *pessoas = NULL;
    int opt;

    do {

        // cabeçalho
        system("cls");
        zenter("Menu Principal");

        switch(opt = option(MENU_OPTIONS, MENU_OPTIONS_N)){
            case 2:
                //strcpy(buffer, "2|Dados");
                pessoas = dados(pessoas);
                break;
            case 4:
                //sair();
                return;
                //break;
            case 3:
                //ajuda();
                //break;
            case 1:
                //jogar(pessoas);
                //break;
            default:
                pause("nao definido - qualquer tecla para continuar");
        }

        /*/
        char c;
        int msg = FALSE;
        char buffer[255] = { '\0' };
        puts("1|Jogar  2|Dados  3|Ajuda  4|Sair");
        if(msg) putz(buffer, 11);
        else msg = TRUE;
        //scanf(" %d", &option);
        //fflush(stdin);
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
        //*/

    } while(TRUE);
}

void sair(){
    // AFAZER: cleanup

    intro();

    die("Adeus");
}
