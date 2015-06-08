#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

//------------
// Menu Dados
//------------
#define DADOS_OPTIONS_N 5
const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Listar", "Adicionar", "Remover", "Info", "voltar"
};
const char * const DADOS_DESCRIPTIONS[DADOS_OPTIONS_N] = {
    "Lista as Pessoas na lista",
    "Adiciona uma Pessoa na lista",
    "Remove uma pessoa da lista pelo seu Id",
    "Mostra esta lista",
    "Volta ao menu anterior"
};

Pessoa *Dados(Pessoa *);
Pessoa *_adicionar(Pessoa *);
Pessoa *_remover(int, Pessoa *);
int _guardar(Pessoa *);
void _listar(Pessoa *);

#endif // DADOS_H

