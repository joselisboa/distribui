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
        case 1: jogo_jogar();
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

void jogo_init(){
    pause("JOGO INIT SIMULADOR");
}

void jogo_jogar(){
    char c, buffer[256] = { '\0' };
    char cmd[64] = {'\0'};
    int n = 0;

    if(conjuntos == NULL) {
        jogo_init();
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
