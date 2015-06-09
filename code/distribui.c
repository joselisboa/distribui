#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "distribui.h"

#include "zelib.c"
#include "jogo.c"
#include "dados.c"
#include "util.c"

// Menu Principal
void Distribui() {
    int opt;
    No *pessoas = Lista();

    do {
        // cabeçalho
        zenter_cls(DISTRIBUI_NOME);
        opt = optionz(DISTRIBUI_OPTIONS, DISTRIBUI_N);
        switch(opt){
            case 1: pessoas = Jogo(pessoas);
            break;
            case 2: pessoas = Dados(pessoas);
            break;
            case 3: Util();
            break;
            case 4: distribui_ajuda();
            break;
            case 5:// Sair
            case 0: return;
            default: distribui_default(opt);
        }
    } while(TRUE);
}

void distribui_ajuda() {
    zenter_cls(DISTRIBUI_NOME);
    Info(DISTRIBUI_OPTIONS, DISTRIBUI_DESCRIPTIONS, DISTRIBUI_N);
}

void distribui_default(int opt) {
    zenter_cls(DISTRIBUI_NOME);
    Nimplementado(DISTRIBUI_OPTIONS[opt-1]);
}

// informação inicial na consola
void splash(){
    char linha[81] = { '\0' };
    sprintf(linha, "\"Distribui%cao de Pessoas por Grupos\"", 135);//, 132);
    system("cls");
    zenter("TRABALHO PRATICO PROGRAMACAO 2014/15");
    zenterK(linha, 3);
    zenter("21230536 | Jose Daniel dos Reis Vieira Lisboa");
    pausa();
    system("cls");
}

// termina a aplicação
void terminar(){
    // AFAZER: cleanup
    //halt("adeus");
    //splash();
    //system("cls");
    die("Adeus");
}

//---------------------------------
// Lista de nós com estrura Pessoa
//---------------------------------
// adiciona um nó (com Pessoa) numa lista de nós
No *adicionaNo(Pessoa pessoa, No *lista){
    No *no = (No*) malloc(sizeof(No));
    if(no == NULL) {
        puts("ERRO a alocar memoria para No\n");
        return lista;
    }
    no->prox = NULL;
    no->pessoa = (Pessoa*) malloc(sizeof(Pessoa));
    if(no->pessoa == NULL) {
        free(no);
        puts("ERRO a alocar memoria para Pessoa\n");
        return lista;
    }

    // copiar os dados...
    no->pessoa->id = ++Id;
    no->pessoa->idade = pessoa.idade;
    strcpy(no->pessoa->nome, pessoa.nome);

    // lista vazia?
    if(lista == NULL) lista = no;
    else {
        // deslocar até ao último nó...
        No *aux = lista;
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = no;
    }

    return lista;
}
// remove um nó (com Pessoa) duma lista de nós
No *removeNo(int *id, No *lista){
    // lista vazia
    if(lista == NULL) return NULL;

    No *aux, *pno = lista;

    // é o primeiro nó
    if(pno->pessoa->id == *id) {
        lista = pno->prox;
        libertaNo(pno);
        *id = 0;
    }
    // verificar os nós seguintes
    else while(pno->prox != NULL) {
        aux = pno;
        pno = pno->prox;
        if(pno->pessoa->id == *id){
            aux->prox = pno->prox;
            libertaNo(pno);
            *id = 0;
            break;
        }
    }

    return lista;
}
// liberta a memória ocupada por um nó
No *libertaNo(No *no){
    zeFree(no->pessoa);
    if(no->pessoa == NULL) zeFree(no);
    return no;
}
// obtém uma lista de nós (com Pessoa) a partir de um ficheiro binário
No *Lista(){
    No *lista = NULL;
    // se o ficheiro não existe devolver a lista (vazia)
    if(!file_exists(PESSOAS_DAT)) return lista;
    // Abrir o ficheiro binário para leitura
    FILE *fd = fopen(PESSOAS_DAT, "rb");
    if(fd == NULL)  printz(12, "Erro a abrir o ficheiro '%s'\n", PESSOAS_DAT);
    else {
        Pessoa pessoa;
        // Enquanto obter pessoas (uma a uma)
        while(fread(&pessoa, sizeof(pessoa), 1, fd) == 1)
            lista = adicionaNo(pessoa, lista);
        fclose(fd);
    }

    return lista;
}

//  "não implementado"
void Nimplementado(const char *option){
    printz(11, "[%s]\n", option);
    putz("NAO IMPLEMENTADO", 12);
    pausa();
}
