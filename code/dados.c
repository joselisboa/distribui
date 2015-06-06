#include <stdio.h>
#include "distribui.h"
#include "dados.h"
#include "zelib.h"

Pessoa *adicionar_pessoa(Pessoa *pessoas){
    Pessoa *aux = NULL;
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));

    if(novo == NULL) {
        putz("ERRO a alocar memoria para Pessoa", 12);
        return NULL;
    }

    //pno utente = lista;
    putz("[adicionar pessoa]", 15);
    //fflush(stdin);
    
    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);
    printf("Nome: ");
    scanf(" %d", &novo->idade);
    fflush(stdin);
    novo->id = ++Id;
    novo->prox = NULL;

    if(pessoas == NULL) pessoas = novo;
    else {
        aux = pessoas;
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }

    return pessoas;
}

void listar_pessoas(Pessoa *pessoas){
    Pessoa *aux = pessoas;
    int i = 0;
    //pno utente = lista;
    putz("[Listar Pessoas]", 11);

    if(pessoas == NULL) putz("nao tem pessoas", 12);
    
    while(aux != NULL){
        printz(15, "%d| #%d: %s, %d\n", ++i, aux->id, aux->nome, aux->idade);
        aux = aux->prox;
    }
    pause("qualquer tecla para continuas");
}

Pessoa *dados(Pessoa *pessoas){
    int opt;
    int msg = FALSE;
    char buffer[255] = { '\0' };

    do{
        // cabeçalho
        system("cls");
        zenter("Gestao de Dados");

        if(msg) putz(buffer, 11);
        else msg = TRUE;

        switch(opt = option(DADOS_OPTIONS, DADOS_OPTIONS_N)){
        case 1: // Listar
            listar_pessoas(pessoas);
            break;
        case 2: // Adicionar
            pessoas = adicionar_pessoa(pessoas);
            break;
        //case 3: // Remover
        //case 4: // Guardar
        case 5:// voltar
            return pessoas;
        default:
            printz(11, "[%s]\n", DADOS_OPTIONS[opt-1]);
            putz("NAO IMPLEMENTADO", 12);
            //printf("option=%d\n", opt);
            sprintf(buffer, "opcao '%d'", opt);
        }

        //pause("qualquer tecla para continuar");
    } while(TRUE);

    //return pessoas;
}
