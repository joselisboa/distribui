#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

#define DADOS_OPTIONS_N 4

const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Listar", "Adicionar", "Remover", "voltar"
};

Pessoa *Dados(Pessoa *);
Pessoa *_adicionar(Pessoa *);
Pessoa *_remover(int, Pessoa *);
int _guardar(Pessoa *);
void _listar(Pessoa *);

#endif // DADOS_H
