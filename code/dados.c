#include <stdio.h>
#include "distribui.h"
#include "dados.h"
#include "zelib.h"

// função principal
No *Dados(No *lista){
    int opt;
    do {
        // cabeçalho
        zenter_cls(DADOS_NOME);
        opt = optionz(DADOS_OPTIONS, DADOS_N);
        switch(opt) {
        case 1: dados_listar(lista);
        break;
        case 2: lista = dados_adicionar(lista);
        break;
        case 3: lista = dados_remover(lista);
        break;
        case 4: lista = dados_importar(lista);
        break;
        case 5: dados_exportar(lista);
        break;
        case 6: dados_ajuda();
        break;
        case 7:// voltar
        case 0: return lista;
        default: dados_default(opt);
        }
    } while(TRUE);

    // nunca chega aqui
    return lista;
}

// lista as pessoas na lista
void dados_listar(No *lista){
    No *no = lista;
    int i = 0;

    zenter_cls(DADOS_NOME);
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

    zenter_cls(DADOS_NOME);
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

    zenter_cls(DADOS_NOME);
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

// importa pessoas num ficheiro de texto
// ELIMINA OS DADOS DA LISTA ATUAL! 
No *dados_importar(No *lista){
    FILE *fd = fopen(DADOS_TXT, "r");
    if(fd == NULL) {
        printz(12, "ERRO a abrir o ficheiro '%s'\n", DADOS_TXT);
        pausa();
        return lista;
    }

    lista = libertaLista(lista);
    if(lista != NULL) die("LISTA NAO NULA");

    int i = 0, k = 0;
    char c = '\0';
    Pessoa pessoa;
    //*/
    // nome e idade numa linha separados por uma vírgula
    while((c = fgetc(fd)) != EOF && i < 100) {
        if(c == ',') {
            pessoa.nome[i] = '\0';
            fscanf(fd, " %d ", &pessoa.idade);
            lista = adicionaNo(pessoa, lista);
            printf("%d: %s, %d\n", Id, pessoa.nome, pessoa.idade);
            i = 0;
            k++;
        }
        else pessoa.nome[i++] = c;
    }
    /*/
    // nome numa linha e idade na seguinte linha 
    while(fgets(pessoa.nome, 100, fd) != NULL) {
        pessoa.nome[strlen(pessoa.nome)-1] = '\0';
        fscanf(fd, " %d ", &pessoa.idade);
        lista = adicionaNo(pessoa, lista);
        printf("%d: %s, %d\n", Id, pessoa.nome, pessoa.idade);
        k++;
    }
    //*/
    fclose(fd);

    //--------------------------------------------------------
    zenter_cls(DADOS_NOME);
    printz(11, "[Importar do ficheiro '%s']\n", DADOS_TXT);

    dados_guardar(lista);
    printz(10, "[%d pessoas importadas]\n", k);
    pausa();

    return lista;
}

void dados_exportar(No *lista){
    // abrir ficheiro de texto em modo de escrita
    FILE *fd = fopen(DADOS_TXT, "w");
    if(fd == NULL) {
        printz(12, "ERRO a abrir o ficheiro '%s'\n", DADOS_TXT);
        pausa();
        return;
    }

    // copiar as pessoas na lista para o ficheiro de texto
    No *no = lista;
    while(no != NULL) {
        //fprintf(fd, "%s\n%d\n\n", no->pessoa->nome, no->pessoa->idade);
        fprintf(fd, "%s, %d\n", no->pessoa->nome, no->pessoa->idade);
        no = no->prox;
    }

    fclose(fd);

    //-----------output-----------------
    zenter_cls(DADOS_NOME);
    printz(11, "[Exportar para o ficheiro '%s']\n", DADOS_TXT);

    // verificar se gravou o ficheiro
    if(file_exists(DADOS_TXT)) putz("[dados exportados com sucesso]", 10);
    else putz("[dados NAO exportados]", 12);

    pausa();
}

// guarda a lista de pessoas no ficheiro
int dados_guardar(No *lista){
    FILE *fd = fopen(PESSOAS_DAT, "wb");

    if(fd == NULL){
        printf("[Erro no acesso ao ficheiro '%s']\n", PESSOAS_DAT);
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

void dados_ajuda(){
    zenter_cls(DADOS_NOME);
    Info(DADOS_OPTIONS, DADOS_DESCRIPTIONS, DADOS_N);
}

void dados_default(int opt){
    zenter_cls(DADOS_NOME);
    nao_implementado(DADOS_OPTIONS[opt-1]);
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
