#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "zelib.h"
#include "distribui.h"
#include "dados.h"
#include "util.h"

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
    char linha[81] = { '\0' };
    sprintf(linha, "Distribui%c%co de Pessoas", 135, 132);

    system("cls");
    zenter("TRABALHO PRATICO PROGRAMACAO 2014/15");
    putz(linha, 11);
    zenter("21230536|Jose Lisboa");
    pause("Premir Qualquer Tecla Para Continuar");
    system("cls");
}

void Iniciar() {
    Pessoa *pessoas = _pessoas();
    int opt;

    do {
        // cabeçalho
        system("cls");
        zenter("Menu Principal");

        switch(opt = option(MENU_OPTIONS, MENU_OPTIONS_N)){
            case 2:
                pessoas = Dados(pessoas);
                break;
            case 4:
                return;
                //break;
            case 5:// Util
                Util();
                break;
            case 3:
                //Ajuda();
                //break;
            case 1:
                //Jogar(pessoas);
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


void Terminar(){
    // AFAZER: cleanup

    //halt("adeus");

    //splash();

    die("Adeus");
}

// obtém lista de pessoas a partir do ficheiro binário
Pessoa *_pessoas()
{
    Pessoa pessoa, *prev, *aux, *lista = NULL;

    // se o ficheiro não existe devolver lista vazia
    if(!file_exists(PESSOAS_DAT)) return lista;

    // Abrir o ficheiro binário para leitura
    FILE *fd = fopen(PESSOAS_DAT, "rb");
    if(fd == NULL)  _printf(12, "Erro a abrir o ficheiro '%s'\n", PESSOAS_DAT);
    else {
        // Enquanto obter pessoas (uma a uma)
        while(fread(&pessoa, sizeof(pessoa), 1, fd) == 1){
            aux = (Pessoa*) malloc(sizeof(Pessoa));
            if(aux == NULL) {
                puts("ERRO a alocar memoria para Pessoa\n");
                return lista;
            }
            // copiar os dados...
            aux->id = ++Id;
            aux->idade = pessoa.idade;
            strcpy(aux->nome, pessoa.nome);
            aux->prox = NULL;
            // lista vazia?
            if(lista == NULL) lista = aux;
            else prev->prox = aux;
            prev = aux;
        }

        fclose(fd);
    }

    return lista;
}
