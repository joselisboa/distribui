#include <stdio.h>
#include "zelib.h"
#include "util.h"

#include "testes.c"

void Util(){
    int opt;
    do {
        // cabeçalho
        zenter_cls(TESTES_NOME);
        opt = optionz(UTIL_OPTIONS, UTIL_N);
        switch(opt){
        case 1: util_cores();
        break;
        case 2: util_caracteres();
        break;
        case 3: util_getch();
        break;
        case 4: Testes();
        break;
        case 5: util_ajuda();
        break;
        case 6: // Voltar
        case 0: return;
        default:
            util_default(opt);
        }
    } while(TRUE);
}

void util_cores(){
    int i;
    zenter_cls(UTIL_NOME);
    for (i=0; i< 32; i++){
        printz(i, "%02d| amostra de texto na cor %04x\n", i, i);
    }
    pause("continuar");
}

void util_caracteres(){
    int i;
    zenter_cls(UTIL_NOME);
    for (i=0; i< 256; i++){
        printf("%03d| caractere '%c'\n", i, i);
    }
    pause("continuar");
}

void util_getch(){
    char c;
    zenter_cls(UTIL_NOME);
    putz("['X' ou 'x' para sair]", 11);
    do{
        switch(c = getch()){
        case 10:
            putz("10: []", 12);
            break;
        case 13://enter
            putz("13: [ENTER]", 12);
            break;
        case 27://escape
            putz("27: [ESCAPE]", 12);
            break;
        case 32://enter
            putz("32: [SPACE]", 12);
            break;
        case -32:// setas
            switch(c = getch()){
                case 72:
                    putz("72: [CIMA]", 13);
                    break;
                case 80:
                    putz("80: [BAIXO]", 13);
                    break;
                case 75:
                    putz("75: [ESQUERDA]", 13);
                    break;
                case 77:
                    putz("77: [DIREITA]", 13);
                    break;

                default:
                    printz(13, "%d: %c\n", c, c);
            }
            break;

        default:
            printz(12, "%d: %c\n", c, c);
        }

        if(c == 'X' || c == 'x') break;
    } while(TRUE);
}

void util_ajuda() {
    zenter_cls(UTIL_NOME);
    Info(UTIL_OPTIONS, UTIL_DESCRIPTIONS, UTIL_N);
}

void util_default(int opt){
    zenter_cls(UTIL_NOME);
    Nimplementado(UTIL_OPTIONS[opt-1]);
}
