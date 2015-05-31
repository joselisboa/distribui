#include <stdio.h>
#include <stdlib.h>
#include "zelib.c"
#include "distribui.h"
#include "distribui.c"

int main(int argc, char *argv[]){
    Pessoa pessoa1 = pessoa("Ze", 49);
    Pessoa pessoa2 = pessoa("Ana", 28);

    _entrelinhas('-', "Pessoa\n");

    //puts(pessoa1.nome);
    putz("putz BLUE", BLUE);
    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);
    pause("press enter to continue");

    die("bye");

    exit(EXIT_SUCCESS);
}
