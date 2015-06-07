#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

#define DADOS_OPTIONS_N 5

const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Listar", "Adicionar", "Remover", "Guardar", "voltar"
};

Pessoa *Dados(Pessoa *);
Pessoa *_adicionar(Pessoa *);
int _guardar(Pessoa *, int);
void _listar(Pessoa *);

#endif // DADOS_H
