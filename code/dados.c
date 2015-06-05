#include <stdio.h>
#include "dados.h"
#include "zelib.h"

Pessoa *dados(Pessoa *pessoas){
    //*/
    int opt;

    switch(opt = option(DADOS_OPTIONS, DADOS_OPTIONS_N)){
    case 1:
        //dados_adicionar(pessoas);
        //break;
    case 2:
        //break;
    case 3:
        //break;
    case 4:
        //break;
    default:
        printf("option=%d\n", opt);
    }
    //*/

    pause("dados(): qualquer tecla para continuar");

    return pessoas;
}
