#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

#define PESSOAS_DAT "pessoas.dat"
#define DADOS_OPTIONS_N 5

const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Adicionar", "Remover", "Listar", "Guardar", "voltar"
};

Pessoa *dados(Pessoa *);

#endif // DADOS_H
