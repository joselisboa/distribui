#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "zelib.h"
#include "distribui.h"
#include "dados.h"
//#include "util.h"
//#include "jogo.h"

// Menu Principal
void Iniciar() {
    int opt;
    No *pessoas = Lista();
    char *nome = "Menu Principal";
    do {
        // cabeçalho
        zenter_cls(nome);
        opt = optionz(MENU_OPTIONS, MENU_OPTIONS_N);
        switch(opt){
            //case 1:// Jogo
            //    pessoas = Jogo(pessoas);
            //    break;
            case 2:
                pessoas = Dados(pessoas);
                break;
            //case 3:// Util
            //    Util();
            //    break;
            case 4:// Info
                zenter_cls(nome);
                Info(MENU_OPTIONS, MENU_DESCRIPTIONS, MENU_OPTIONS_N);
                break;
            case 5:// Sair
            case 0: return;
            default:
                zenter_cls(nome);
                Nimplementado(MENU_OPTIONS[opt-1]);
        }
    } while(TRUE);
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
void Terminar(){
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
