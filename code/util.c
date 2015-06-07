#include <stdio.h>
#include "zelib.h"
#include "util.h"
#include "testes.h"

void Util(){
    int opt;

    do{
        // cabeçalho
        system("cls");
        zenter("Utilitarios");

        switch(opt = option(UTIL_OPTIONS, UTIL_OPTIONS_N)){
        case 1: // Cores
            _cores();
            break;
        case 2: // Caracteres
            _caracteres();
            break;
        case 3:
            Testes();
            break;
        case 4:
            return;
        default:
            printz(11, "[%s]\n", DADOS_OPTIONS[opt-1]);
            putz("NAO IMPLEMENTADO", 12);
            pause("premir qualquer tecla para continuar");
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
