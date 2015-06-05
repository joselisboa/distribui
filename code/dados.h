#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

#define PESSOAS_DAT "pessoas.dat"
#define DADOS_OPTIONS_N 4

const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Adicionar", "Remover", "Listar", "Guardar"
};

Pessoa *dados(Pessoa *);

#endif // DADOS_H
