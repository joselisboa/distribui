#include <stdio.h>
#include "zelib.h"
#include "util.h"

#include "testes.c"

void Util(){
    int opt;
    char *nome = "Utilitarios";

    do{
        // cabeçalho
        zenter_cls(nome);

        switch(opt = optionz(UTIL_OPTIONS, UTIL_OPTIONS_N)){
        case 1: // Cores
            zenter_cls(nome);
            _cores();
            break;
        case 2: // Caracteres
            zenter_cls(nome);
            _caracteres();
            break;
        case 3:
            Testes();
            break;
        case 4:
        case 0: return;
        default:
            zenter_cls(nome);
            Nimplementado(UTIL_OPTIONS[opt-1]);
        }
    } while(TRUE);
}

void _cores(){
    int i;
    for (i=0; i< 32; i++){
        printz(i, "%02d| amostra de texto na cor %04x\n", i, i);
    }
    pause("continuar");
}

void _caracteres(){
    int i;
    for (i=0; i< 256; i++){
        printf("%03d| caractere '%c'\n", i, i);
    }
    pause("continuar");
}

