#include <stdio.h>
#include "distribui.h"
#include "dados.h"
#include "zelib.h"

// função principal
Pessoa *Dados(Pessoa *pessoas){
    int opt, id;
    char *nome = "Gestao de Dados";
    do {
        // cabeçalho
        zenter_cls(nome);

        switch(opt = option(DADOS_OPTIONS, DADOS_OPTIONS_N)){
        case 1: // Listar
            zenter_cls(nome);
            _listar(pessoas);
            break;

        case 2: // Adicionar
            // AFAZER: mover para uma função
            zenter_cls(nome);
            printz(11, "[%s Pessoa]\n", DADOS_OPTIONS[opt-1]);
            id = Id;
            pessoas = _adicionar(pessoas);
            if(Id > id) {
                putz("pessoa adicionada com sucesso", 2);
                if(_guardar(pessoas) > 0) putz("lista atualizada", 2);
                else putz("lista nao atualizada", 12);
            }
            pausa();
            break;

        case 3:// Remover
            zenter_cls(nome);

            printz(11, "[%s Pessoa]\n", DADOS_OPTIONS[opt-1]);
            printf("Id: ");
            scanf("%d", &id);
            if(id > 0) {
                pessoas = _remover(id, pessoas);
                if(_guardar(pessoas)) putz("lista atualizada", 2);
                else putz("lista nao atualizada", 12);
            }
            else putz("Id invalido", 12);
            pausa();
            break;

        case 4:
            zenter_cls("Menu Principal");
            //putz("[Info]", 13);
            _info(DADOS_OPTIONS, DADOS_DESCRIPTIONS, DADOS_OPTIONS_N);
            break;

        case 5:// voltar
            return pessoas;

        default:
            zenter_cls(nome);
            Nimplementado(DADOS_OPTIONS[opt-1]);
        }
    } while(TRUE);

    // nunca chega aqui
    return pessoas;
}

// guarda a lista de pessoas no ficheiro
int _guardar(Pessoa *lista){
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

// remove pessoa pelo id (permite haver mais que uma pessoa com o mesmo nome)
Pessoa *_remover(int id, Pessoa *lista){
    Pessoa *aux, *pessoa = lista;

    // lista vazia
    if(lista == NULL) return NULL;

    // é a primeira pessoa
    if(pessoa->id == id) {
        aux = pessoa;
        lista = pessoa->prox;
        zeFree(aux);
        return lista;
    }

    // pessoas seguintes
    while(pessoa->prox != NULL){
        if(pessoa->prox->id == id){
            aux = pessoa->prox;
            pessoa->prox = aux->prox;
            zeFree(aux);
            break;
        }
        pessoa = pessoa->prox;
    }

    return lista;
}

