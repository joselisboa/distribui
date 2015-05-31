#include <stdio.h>
#include <stdlib.h>
#include "zelib.c"

int main(int argc, char *argv[]){
    _entrelinhas('-', "hello world\n");
    puts("puts");
    putz("putz BLUE", BLUE);
    _printf(MAGENTA, "Hello %d:%s\n", MAGENTA, "MAGENTA");
    pause("press enter to continue");
    die("bye");
    exit(EXIT_SUCCESS);
}
