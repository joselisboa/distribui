#include <stdio.h>
#include "distribui.h"
#include "zelib.h"
#include "ajuda.h"

Pessoa *Jogo(Pessoa *pessoas){
    int opt;
    char *nome = "Jogo";
    do {
        // cabe?lho
        zenter_cls(nome);

        switch(opt = option(JOGO_OPTIONS, JOGO_OPTIONS_N)){
        case 1: // Jogar
            zenter_cls(nome);
            _jogar();
            break;
        case 2: // Recuperar
            zenter_cls(nome);
            _recuperar();
            break;
        case 3: // Guardar
            zenter_cls(nome);
            _salvar();
            break;
        case 4: // Ajuda
            Ajuda();
            break;
        case 3:// Voltar
            return;
        default:
            zenter_cls(nome);
            Nimplementado(JOGO_OPTIONS[opt-1]);
        }

    } while(TRUE);
}

void _jogar(){
    Nimplementado("Jogar");
}

void _recuperar(){
    Nimplementado("Recuperar");
}

void _salvar(){
    Nimplementado("Salvar");
}