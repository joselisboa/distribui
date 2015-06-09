#include <stdio.h>
#include "distribui.h"
#include "zelib.h"
#include "testes.h"

void Testes(){
    int opt;
    char *nome = "Testes";
    do {
        // cabeçalho
        zenter_cls(nome);

        switch(opt = optionz(TESTES_OPTIONS, TESTES_OPTIONS_N)){
        case 1: // Cores
            zenter_cls(nome);
            _putz();
            break;
        case 2: // Caracteres
            zenter_cls(nome);
            _printz();
            break;
        case 3:
            zenter_cls(nome);
            _getch();
            break;
        case 4:
        case 0: return;
        default:
            zenter_cls(nome);
            Nimplementado(TESTES_OPTIONS[opt-1]);
        }
    } while(TRUE);
}

void _putz(){
    putz("putz(string, BLUE);", BLUE);
    pause("continuar");
}

void _printz(){
    Pessoa pessoa1 = { ++Id, "Ze", 49 };
    Pessoa pessoa2 = { ++Id, "Maria", 31 };

    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);

    pause("continuar");
}

void _getch(){
    char c;
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
