#include <stdio.h>
#include "distribui.h"
#include "zelib.h"
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
        case 5: jogo_ajuda();a
        break;
        case 5:// Voltar
        case 0: return lista;
        default:
            jogo_default(opt);
        }

    } while(TRUE);
}

void jogo_jogar(){
    zenter_cls(JOGO_NOME);
    Nimplementado("Jogar");
    pausa();
}

void jogo_recuperar(){
    zenter_cls(JOGO_NOME);
    Nimplementado("Recuperar");
}

void jogo_salvar(){
    zenter_cls(JOGO_NOME);
    Nimplementado("Salvar");
}

void jogo_ajuda() {
    zenter_cls(JOGO_NOME);
    Info(JOGO_OPTIONS, JOGO_DESCRIPTIONS, JOGO_N);
}

void jogo_default(int opt){
    zenter_cls(JOGO_NOME);
    Nimplementado(JOGO_OPTIONS[opt-1]);
}
