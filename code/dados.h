#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

#define PESSOAS_DAT "pessoas.dat"
#define DADOS_OPTIONS_N 5

const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Listar", "Adicionar", "Remover", "Guardar", "voltar"
};

Pessoa *dados(Pessoa *);
Pessoa *adicionar_pessoa(Pessoa *);
void listar_pessoas(Pessoa *);

#endif // DADOS_H
