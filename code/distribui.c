#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "zelib.h"
#include "distribui.h"
#include "dados.h"
#include "util.h"
#include "jogo.h"

void Iniciar() {
    int opt;
    Pessoa *pessoas = _pessoas();
    char *nome = "Menu Principal";

    do {
        // cabeçalho
        zenter_cls(nome);

        switch(opt = option(MENU_OPTIONS, MENU_OPTIONS_N)){
            case 1:// Jogo
                pessoas = Jogo(pessoas);
                break;
            case 2:// Dados
                zenter_cls(nome);
                pessoas = Dados(pessoas);
                break;
            case 3:// Util
                Util();
                break;
            case 4:// Info
                zenter_cls(nome);
                _info(MENU_OPTIONS, MENU_DESCRIPTIONS, MENU_OPTIONS_N);
                break;
            case 5: return;
            default:
                zenter_cls(nome);
                Nimplementado(MENU_OPTIONS[opt-1]);
        }
    } while(TRUE);
}

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

void Terminar(){
    // AFAZER: cleanup

    //halt("adeus");

    splash();

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

void _info(const char * const *options, const char * const *descriptions, const int n){
    int i;
    for(i=0; i < n; i++) {
        printz(11, "[%-5s] ", options[i]);
        printz(7, "%s\n", descriptions[i]);
    }
    pausa();
}

// não implementado
void Nimplementado(const char *option){
    printz(11, "[%s]\n", option);
    putz("NAO IMPLEMENTADO", 12);
    pausa();
}

