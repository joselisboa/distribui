#include <stdio.h>
#include <string.h>
#include "distribui.h"

Pessoa pessoa(char *nome, int idade){
    Pessoa p;
    p.id = ++Id;
    strcpy(p.nome, nome);
    p.idade = (unsigned int) idade;
    return p;
}
