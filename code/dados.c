#include <stdio.h>
#include "distribui.h"
#include "dados.h"
#include "zelib.h"

// função principal
Pessoa *Dados(Pessoa *pessoas){
    int opt;

    do{
        // cabeçalho
        system("cls");
        zenter("Gestao de Dados");

        switch(opt = option(DADOS_OPTIONS, DADOS_OPTIONS_N)){
        case 1: // Listar
            _listar(pessoas);
            break;
        case 2: // Adicionar
            printz(11, "[%s]\n", DADOS_OPTIONS[opt-1]);
            pessoas = _adicionar(pessoas);
            break;
        case 3:// Remover
        case 4:// Guardar
            printz(11, "[%s]\n", DADOS_OPTIONS[opt-1]);
            if(_guardar(pessoas, Id) > 0) putz("guardado com sucesso", 11);
            pause("continuar");
            break;
        case 5:// voltar
            return pessoas;
        default:
            printz(11, "[%s]\n", DADOS_OPTIONS[opt-1]);
            putz("NAO IMPLEMENTADO", 12);

            pause("continuar");
        }
    } while(TRUE);

    // nunca chega aqui
    return pessoas;
}

// guarda a lista de pessoas no ficheiro
int _guardar(Pessoa *lista, int n)
{
    FILE *fd = fopen(PESSOAS_DAT, "wb");

    if(fd == NULL){
        printf("Erro de acesso ao ficheiro '%s'\n", PESSOAS_DAT);
        return -1;
    }

    int k = 0;
    Pessoa *pessoa = lista;
    while(pessoa != NULL) {
        fwrite(pessoa, sizeof(Pessoa), 1, fd);
        pessoa = pessoa->prox;

        // AFAZER: verificar se fwrite tem sucesso antes de incrementar
        k++;
    }

    fclose(fd);
    return k;
}

// adiciona uma pessoa à lista de pessoas
Pessoa *_adicionar(Pessoa *pessoas){
    Pessoa *aux = NULL;
    Pessoa *novo = (Pessoa*) malloc(sizeof(Pessoa));

    if(novo == NULL) {
        putz("ERRO a alocar memoria para Pessoa", 12);
        return NULL;
    }

    putz("[adicionar pessoa]", 15);
    //fflush(stdin);

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);
    printf("Idade: ");
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

// lista as pessoas na lista
void _listar(Pessoa *pessoas){
    Pessoa *aux = pessoas;
    int i = 0;

    putz("[Listar Pessoas]", 11);

    if(pessoas == NULL) putz("a lista nao tem pessoas", 12);

    while(aux != NULL){
        printz(15, "%d| #%d: %s, %d\n", ++i, aux->id, aux->nome, aux->idade);
        aux = aux->prox;
    }

    pause("premir qualquer tecla para continuas");
}
