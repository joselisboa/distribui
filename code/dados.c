#include <stdio.h>
#include "dados.h"
#include "zelib.h"

Pessoa *dados(Pessoa *pessoas){
    int opt;
    int msg = FALSE;
    char buffer[255] = { '\0' };

    do{
        // cabeçalho
        system("cls");
        zenter("Gestao de Dados");

        if(msg) putz(buffer, 11);
        else msg = TRUE;

        switch(opt = option(DADOS_OPTIONS, DADOS_OPTIONS_N)){
        case 5:// voltar
            return pessoas;
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
            //printf("option=%d\n", opt);
            sprintf(buffer, "opcao '%d'", opt);
        }

        //pause("qualquer tecla para continuar");
    } while(TRUE);

    //return pessoas;
}
