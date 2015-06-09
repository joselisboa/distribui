#include <stdio.h>
#include "distribui.h"
#include "dados.h"
#include "zelib.h"

// função principal
Pessoa *Dados(Pessoa *pessoas){
    int opt, id;
    
    do {
        // cabeçalho
        zenter_cls("Gestao de Dados");
        opt = optionz(DADOS_OPTIONS, DADOS_OPTIONS_N);

        switch(opt){
        case 1: // Listar
            _listar(pessoas);
            break;
        case 2: // Adicionar
            pessoas = _adicionar(pessoas);
            break;
        case 3:// Remover
            
            pessoas = _remover(pessoas);
            break;
        case 4:// Ajuda
            zenter_cls("Gestao de Dados");
            Info(DADOS_OPTIONS, DADOS_DESCRIPTIONS, DADOS_OPTIONS_N);
            break;
        case 5:// voltar
        case 0: return pessoas;
        default:
            zenter_cls("Gestao de Dados");
            Nimplementado(DADOS_OPTIONS[opt-1]);
        }
    } while(TRUE);

    // nunca chega aqui
    return pessoas;
}

// lista as pessoas na lista
void _listar(Pessoa *pessoas){
    Pessoa *aux = pessoas;
    int i = 0;

    zenter_cls("Gestao de Dados");
    putz("[Listar Pessoas]", 11);

    if(pessoas == NULL) putz("[a lista NAO tem pessoas]", 12);

    while(aux != NULL){
        printz(15, "%d| #%d: %s, %d\n", ++i, aux->id, aux->nome, aux->idade);
        aux = aux->prox;
    }

    pausa();
}

// Adicionar pessoa
Pessoa *_adicionar(Pessoa *pessoas){
    int id = Id;
    
    zenter_cls("Gestao de Dados");
    printz(11, "[%s Pessoa]\n", DADOS_OPTIONS[opt-1]);
    
    pessoas = dados_adicionar(pessoas);
    if(Id > id) {
        putz("[pessoa adicionada]", 2);
        if(_guardar(pessoas) > 0) putz("[lista atualizada]", 2);
        else putz("[lista NAO atualizada]", 12);
    }
    pausa();
    return pessoas;
}

// Remover pessoa
Pessoa *_remover(Pessoa *pessoas){
    int id, n = Pessoas_N;
    
    zenter_cls("Gestao de Dados");
    putz("[Remover Pessoa]", 11);
    
    printf("Id: ");
    scanf("%d", &id);
    if(id > 0) {
        pessoas = dados_remover(id, pessoas);
        if(Pessoas_N < n) {
            printz(2, "[pessoa com id %d removida]\n", id);
            if(_guardar(pessoas) > 0) putz("[lista atualizada]", 2);
            else putz("[lista NAO atualizada]", 12);
        }
        else putz("[pessoa NAO encontrada]", 12);
    }
    else putz("[ID invalido]", 12);
    
    pausa();
    return pessoas;
}

// guarda a lista de pessoas no ficheiro
int dados_guardar(Pessoa *lista){
    FILE *fd = fopen(PESSOAS_DAT, "wb");

    if(fd == NULL){
        printf("[Erro de acesso ao ficheiro '%s']\n", PESSOAS_DAT);
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
Pessoa *dados_adicionar(Pessoa *pessoas){
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

    // primeira pessoa na lista
    if(pessoas == NULL) pessoas = novo;
    else {
        aux = pessoas;
        // avançar até à última pessoa na lista
        while(aux->prox != NULL) aux = aux->prox;
        // adicionar a pessoa no fim
        aux->prox = novo;
    }

    // incrementar o contador de pessoas
    Pessoas_N++;

    return pessoas;
}

// remove pessoa pelo id (permite haver mais que uma pessoa com o mesmo nome)
Pessoa *dados_remover(int id, Pessoa *lista){
    Pessoa *aux, *pessoa = lista;

    // lista vazia
    if(lista == NULL) return NULL;

    // é a primeira pessoa
    if(pessoa->id == id) {
        aux = pessoa;
        lista = pessoa->prox;
        zeFree(aux);
        Pessoas_N--;
        return lista;
    }

    // pessoas seguintes
    while(pessoa->prox != NULL){
        if(pessoa->prox->id == id){
            aux = pessoa->prox;
            pessoa->prox = aux->prox;
            zeFree(aux);
            Pessoas_N--;
            return lista;
        }
        pessoa = pessoa->prox;
    }

    return lista;
}
