#include <stdio.h>
#include "dados.h"
#include "zelib.h"

int dadosOption(){
    int i, option, escolha = 0;

    for(i=0; i < DADOS_OPTIONS_N; i++) {
        printf(" %d|%s ", i+1, DADOS_OPTIONS[i]);
    }

    do {
        printf("\nEscolha: ");
        scanf("%d", &escolha);
    } while(escolha < 1 || escolha > DADOS_OPTIONS_N);

    return escolha;
}

Pessoa *dados(Pessoa *pessoas){
    //*/
    int option;

    switch(option = dadosOption()){
    case 1:
        //break;
    case 2:
        //break;
    case 3:
        //break;
    case 4:
        //break;
    default:
        printf("option=%d\n", option);
    }
    //*/

    pause("dados(): qualquer tecla para continuar");

    return pessoas;
}
