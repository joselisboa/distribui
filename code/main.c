#include <stdio.h>
#include <stdlib.h>
#include "zelib.c"
#include "distribui.c"
#include "dados.c"

int main(int argc, char *argv[]){

    // splash
    splash();
    
    // iniciar o aplicativo
    iniciar();

    /*
    //puts(pessoa1.nome);
    putz("putz BLUE", BLUE);
    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);
    pause("press enter to continue");
    */
    
    splash();
    halt("adeus");
    die("bye");

    // will never get here
    exit(EXIT_SUCCESS);
}
