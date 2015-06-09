#include <stdio.h>
#include "distribui.h"
#include "zelib.h"
#include "testes.h"

void Testes(){
    int opt;
    do {
        // cabeçalho
        zenter_cls(TESTES_NOME);
        opt = optionz(TESTES_OPTIONS, TESTES_N);
        switch(opt){
        case 1: testes_putz();
        break;
        case 2: testes_printz();
        break;
        case 3:
        case 0: return;
        default: testes_default(opt);
        }
    } while(TRUE);
}

void testes_putz(){
    zenter_cls(TESTES_NOME);
    putz("putz(string, BLUE);", BLUE);
    pause("continuar");
}

void testes_printz(){
    Pessoa pessoa1 = { ++Id, "Ze", 49 };
    Pessoa pessoa2 = { ++Id, "Maria", 31 };
    zenter_cls(TESTES_NOME);
    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);

    pause("continuar");
}

void testes_default(int opt){
    zenter_cls(TESTES_NOME);
    Nimplementado(TESTES_OPTIONS[opt-1]);
}
