#include <stdio.h>
#include "distribui.h"
#include "zelib.h"

void Testes(){
    int opt;

    do{
        // cabeçalho
        system("cls");
        zenter("Testes");

        switch(opt = option(TESTES_OPTIONS, TESTES_OPTIONS_N)){
        case 1: // Cores
            _putz();
            break;
        case 2: // Caracteres
            _printz();
            break;
        case 3:
            return;
        default:
            printz(11, "[%s]\n", DADOS_OPTIONS[opt-1]);
            putz("NAO IMPLEMENTADO", 12);
            pause("premir qualquer tecla para continuar");
        }
    } while(TRUE);
}

void _putz(){
    putz("putz(string, BLUE);", BLUE);
    pause("continuar");
}

void _printz(){
    Pessoa pessoa1 = { ++Id, "Ze", 49, NULL };
    Pessoa pessoa2 = { ++Id, "Maria", 31, NULL };

    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);

    pause("continuar");
}
