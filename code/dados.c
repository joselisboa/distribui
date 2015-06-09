#include <stdio.h>
#include "distribui.h"
#include "dados.h"
#include "zelib.h"

// função principal
No *Dados(No *lista){
    int opt;
    char *nome = "Gestao de Dados";
    do {
        // cabeçalho
        zenter_cls(nome);
        opt = optionz(DADOS_OPTIONS, DADOS_OPTIONS_N);
        switch(opt){
        case 1:// Listar
            dados_listar(lista);
            break;
        case 2:// Adicionar
            lista = dados_adicionar(lista);
            break;
        case 3:// Remover
            lista = dados_remover(lista);
            break;
        case 6:// Ajuda
            zenter_cls(nome);
            Info(DADOS_OPTIONS, DADOS_DESCRIPTIONS, DADOS_OPTIONS_N);
            break;
        case 7:// voltar
        case 0: return lista;
        default:
            zenter_cls(nome);
            Nimplementado(DADOS_OPTIONS[opt-1]);
        }
    }while(TRUE);

    // nunca chega aqui
    return lista;
}

// lista as pessoas na lista
void dados_listar(No *lista){
    No *no = lista;
    int i = 0;

    zenter_cls("Gestao de Dados");
    putz("[Listar Pessoas]", 11);

    if(lista == NULL) putz("[a lista NAO tem pessoas]", 12);
    else while(no != NULL){
        printz(15, "#%d: %s, %d\n", no->pessoa->id, no->pessoa->nome, no->pessoa->idade);
        no = no->prox;
    }

    pausa();
}

// Adicionar pessoa
No *dados_adicionar(No *lista){
    int id = Id;
    Pessoa pessoa;

    zenter_cls("Gestao de Dados");
    putz("[Adicionar Pessoa]", 11);

    //fflush(stdin);
    printf("Nome: ");
    scanf(" %[^\n]", pessoa.nome);
    printf("Idade: ");
    scanf(" %d", &pessoa.idade);
    fflush(stdin);
    pessoa.id = ++Id;

    lista = adicionaNo(pessoa, lista);

    if(Id > id) {
        Pessoas++;
        putz("[pessoa adicionada]", 2);
        if(guardaLista(lista) > 0) putz("[lista atualizada]", 2);
        else putz("[lista NAO atualizada]", 12);
    }
    pausa();
    return lista;
}

// Remover pessoa
No *dados_remover(No *lista){
    int id;

    zenter_cls("Gestao de Dados");
    putz("[Remover Pessoa]", 11);
    
    printf("Id: ");
    scanf("%d", &id);
    if(id > 0) {
        lista = removeNo(&id, lista);
        if(id == 0) {
            Pessoas--;
            putz("[pessoa removida]", 2);
            if(guardaLista(lista) > 0) putz("[lista atualizada]", 2);
            else putz("[lista NAO atualizada]", 12);
        }
        else putz("[pessoa NAO encontrada]", 12);
    }
    else putz("[ID invalido]", 12);

    pausa();
    return lista;
}

// guarda a lista de pessoas no ficheiro
int dados_guardar(No *lista){
    FILE *fd = fopen(PESSOAS_DAT, "wb");

    if(fd == NULL){
        printf("[Erro de acesso ao ficheiro '%s']\n", PESSOAS_DAT);
        return -1;
    }

    int k = 0;
    No *no = lista;
    while(no != NULL) {
        if(fwrite(no->pessoa, sizeof(Pessoa), 1, fd) == 1) k++;
        no = no->prox;
    }

    fclose(fd);
    return k;
}

int guardaLista(No *lista){
    FILE *fd = fopen(PESSOAS_DAT, "wb");

    if(fd == NULL){
        printf("[Erro de acesso ao ficheiro '%s']\n", PESSOAS_DAT);
        return -1;
    }

    int k = 0;
    No *no = lista;
    Pessoa *pessoa;
    while(no != NULL) {
        pessoa = no->pessoa;
        fwrite(pessoa, sizeof(Pessoa), 1, fd);
        no = no->prox;

        // AFAZER: verificar se fwrite tem sucesso antes de incrementar
        k++;
    }

    fclose(fd);
    return k;
}
