#include <stdio.h>
#include <stdlib.h>
#include "zelib.c"
#include "distribui.c"
#include "dados.c"
#include "util.c"
#include "testes.c"
#include "jogo.c"
#include "ajuda.c"

int main(int argc, char *argv[]){

    splash();

    Iniciar();

    Terminar();

    // a rotina nunca chega aqui
    exit(EXIT_SUCCESS);
}

