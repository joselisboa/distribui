#include <stdio.h>
#include <string.h>
#include "distribui.h"
#include "zelib.h"
#include "jogo.h"
#include "ajuda.c"

No *Jogo(No *lista){
    int opt;
    do {
        // cabeçalho
        zenter_cls(JOGO_NOME);
        opt = optionz(JOGO_OPTIONS, JOGO_N);
        switch(opt){
        case 1: jogo_jogar(lista);
        break;
        case 2: jogo_recuperar();
        break;
        case 3: jogo_salvar();
        break;
        case 4: Ajuda();
        break;
        case 5: jogo_ajuda();
        break;
        case 6:// Voltar
        case 0: return lista;
        default:
            jogo_default(opt);
        }

    } while(TRUE);
}

// inicializa o jogo
void jogo_init(No *lista){
    // tornal a lista acessível...
    if(pessoas == NULL) pessoas = lista;

    // AFAZER distribuir as pessoas por grupos
 
    pause("JOGO INIT SIMULADOR");
}

void jogo_jogar(No *lista) {
    char c, buffer[256] = { '\0' };
    char cmd[64] = {'\0'};
    int n = 0;

    if(conjuntos == NULL) {
        jogo_init(lista);
        sprintf(buffer, "[Novo Jogo]");
    }
    else {
        sprintf(buffer, "[Jogo em curso]");
    }

    zenter_cls(JOGO_NOME);

    while (TRUE) {
        // output para o jogador
        if(buffer[0] != '\0'){
            puts(buffer);
            buffer[0] = '\0';
        }
        //pausa();
        //zenter_cls(JOGO_NOME);

        printz(11, "[Joga o jogador #%d]\n", Jogador_Ativo);
        printf("> ");

        //fscanf(" %[^\n]", cmd);

        // input from user
         while(read(0, &c, 1) >  0){
            if(c != '\n' && n < 63){
                cmd[n++] = c;
            }
            else break;
        }

        cmd[n] = '\0';
        n = 0;

        //jogo_cmds(cmd);
        sprintf(buffer, "%s\n", cmd);

        if(!strncmp("sair", cmd, 3)){
            break;
        }
    }

    // sair do jogo
    pause("prima qualquer tecla para sair do jogo");
    //nao_implementado("Jogar");
}

void jogo_recuperar(){
    zenter_cls(JOGO_NOME);
    nao_implementado("Recuperar");
}

void jogo_salvar(){
    zenter_cls(JOGO_NOME);
    nao_implementado("Salvar");
}

void jogo_ajuda() {
    zenter_cls(JOGO_NOME);
    Info(JOGO_OPTIONS, JOGO_DESCRIPTIONS, JOGO_N);
}

void jogo_default(int opt){
    zenter_cls(JOGO_NOME);
    nao_implementado(JOGO_OPTIONS[opt-1]);
}

//----------
// Comandos
//----------
/*/ INSERIR pessoa num conjunto (com validação)
int jogo_cmd_inserir(int pessoa_id, int conjunto_id) {
    
    // 1. O conjunto existe?
    Conjunto *conjunto = obtemConjunto(conjunto_id);
    if(conjunto == NULL) {
        // msg = "Conjunto <id> não existe"   
        return 0;
    } 

    // 2. A pessoa existe?
    Pessoa *pessoa = distribui_obtemPessoa(pessoa_id);
    if(pessoa == NULL) {
        // msg = "Pessoa <id> não existe"
        return 0;
    }

    // 3. O conjunto já tem a pessoa?
    if(jogo_conjuntoTemPessoa(pessoa_id)) {
        // msg = "Conjunto <id> Já tem pessoa <id>"
        return 0;
    }    

    // 4. A pessoa já está em 3 conjuntos?
    if(jogo_conjuntosComPessoa(int pessoa_id) == 3) {
        // msg = "Pessoa <id> Já está em 3 conjuntos"
        return 0;        
    }

    // OK
    No *no = alocaNo(pessoa);
    if(no == NULL) {
        // msg = "ERRO a alocar No para Pessoa*"
        return 0;
    }

    // inserir nó no inicio da lista
    no->prox = Conjunto->pessoas;
    Conjunto->pessoas = no;

    return 1;
}
// ELIMINAR pessoa dum conjunto (com validação)
int jogo_cmd_eliminar(int pessoa_id, int conjunto_id) {
    
    // 1. O conjunto existe?
    Conjunto *conjunto = obtemConjunto(conjunto_id);
    if(conjunto == NULL) {
        // msg = "Conjunto <id> não existe"   
        return 0;
    } 

    // 2. O Conjunto tem mais que 2 pessoas?
    if(conjunto.n == 2) {
        // msg = "Conjunto <id> so tem 2 pessoa"   
        return 0;
    }

    // 3. A pessoa existe no conjunto?
    if(!jogo_conjuntoTemPessoa(pessoa_id, conjunto)) {
        // msg = "O Conjunto nao tem a Pessoa <id>"
        return 0;
    }    

    // 4. A pessoa está em mais que 1 conjunto?
    if(jogo_conjuntosComPessoa(int pessoa_id) == 1) {
        // msg = "Pessoa <id> so esta nesse conjunto"
        return 0;
    }

    // OK
    No *no = jogo_removePessoa(pessoa_id, conjunto);
    // LIBERTAR O NÓ (mas não a pessoa)
    free(no);

    return 1;
}
// TRANSFERIR passa uma pessoa de um conjunto para outro (com validação)
int jogo_cmd_transferir(int pessoa_id, int conj1_id, int conj2_id){

    // 1. O conjunto 1 existe?
    Conjunto *conj1 = obtemConjunto(conj1_id);
    if(conj1 == NULL) {
        // msg = "Conjunto <id1> não existe"   
        return 0;
    }

    // 2. O conjunto 1 tem mais que 2 pessoas?
    if(conj1.n == 2) {
        // msg = "O Conjunto 1 apenas tem tem 2 pessoas"
        return 0;        
    }

    // 3. A pessoa existe no conjunto 1?
    if(!jogo_conjuntoTemPessoa(pessoa_id, conj1)) {
        // msg = "O Conjunto 1 nao tem a Pessoa <id>"
        return 0;
    }

    // 4. O conjunto 2 existe?
    Conjunto *conj2 = obtemConjunto(conj2_id);
    if(conj2 == NULL) {
        // msg = "Conjunto <id2> não existe"   
        return 0;
    }

    // 5. A pessoa já existe no conjunto 2?
    if(jogo_conjuntoTemPessoa(pessoa_id, conj2)) {
        // msg = "O Conjunto 2 já tem a Pessoa <id>"
        return 0;
    }

    // OK

    // remove nó do conjunto 1
    No *pessoa = jogo_removePessoa(pessoa_id, conj1);
    
    // adiciona nó ao conjunto 2
    jogo_adicionaPessoa(pessoa, conj2);
    
    // msg = "pessoa id nao encontrada"
    return 1;
}
// adiciona pessoa a um conjunto
void jogo_adicionaPessoa(No *no, Conjunto *conjunto) {
    no->prox = conjunto->pessoas;
    conjunto->pessoas = no;
}
// Obtém pessoa de um conjunto (não a remove a pessoa)
No *jogo_obtemPessoa(int pessoa_id, Conjunto *conjunto) {
    No *no = conjunto->pessoas;

    while(no != NULL){
        // pessoa encontrada
        if(no->pessoa->id == pessoa_id) {
            return no;
        }
        // próxima pessoa
        no = no->prox;
    }

    return NULL;
}
// O Conjunto Tem Pessoa?
int jogo_cojuntoTemPessoa(int pessoa_id, Conjunto *conjunto){
    if(jogo_obtemPessoa(pessoa_id, conjunto) != NULL) return 1;
    return 0;
}
// Remove pessoa de um conjunto
No *jogo_removePessoa(int pessoa_id, Conjunto *conjunto){
    No *anterior, *no = conjunto->pessoas;

    // é a primeira pessoa do conjunto
    if(no->pessoa->id == pessoa_id) {
        conjunto->pessoas = no->prox;
        return no;
    }

    // não é o primeira pessoa do conjunto
    while(no->prox != NULL){
        anterior = no;
        no = no->prox;
        // pessoa encontrada?
        if(no->pessoa->id == pessoa_id) {
            anterior->prox = no->prox; 
            return no;
        }
    }

    return NULL;
}
// Obtém numero de conjunto com pessoa
int jogo_conjuntosComPessoa(int pessoa_id) {
    Conjunto *conjunto = conjuntos;
    int n = 0;

    if(conjuntos != NULL) while(conjunto != NULL) {
        if(jogo_conjuntoTemPessoa(pessoa_id, conjunto)) n++;
        if(n == 3) return n;
        // próximo conjunto
        conjunto = conjunto->prox;
    }

    return n;
}
No *jogo_cmds(char *cmd){

    switch(){

    }

}
//*/
