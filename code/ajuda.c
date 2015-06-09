#include <stdio.h>
#include "distribui.h"
#include "zelib.h"

void Ajuda(){
    int opt;
    char *nome = "Ajuda";
    do {
        // cabe?lho
        zenter_cls(nome);

        switch(opt = optionz(AJUDA_OPTIONS, AJUDA_OPTIONS_N)){
        case 1: // Regras
            zenter_cls(nome);
            _regras();
            break;
        case 2: // Comandos
            zenter_cls(nome);
            _comandos();
            break;
        case 3:// Voltar
        case 0: return;
        default:
            zenter_cls(nome);
            Nimplementado(AJUDA_OPTIONS[opt-1]);
        }

    } while(TRUE);
}

void _regras(){
    Nimplementado("Regras");
}

void _comandos(){
    Nimplementado("Comandos");
}
