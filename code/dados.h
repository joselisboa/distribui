#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

//------------
// Menu Dados
//------------
// n items
#define DADOS_OPTIONS_N 5
// opções
const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Listar", "Adicionar", "Remover", "Ajuda", "voltar"
};
// descritivo das opções
const char * const DADOS_DESCRIPTIONS[DADOS_OPTIONS_N] = {
    "Lista as Pessoas na lista",
    "Adiciona uma Pessoa na lista",
    "Remove uma pessoa da lista pelo seu Id",
    "Mostra esta lista",
    "Volta ao menu anterior"
};

Pessoa *Dados(Pessoa *);
Pessoa *dados_remover(int, Pessoa *);
Pessoa *dados_adicionar(Pessoa *);
int dados_guardar(Pessoa *);
Pessoa *_remover(Pessoa *);
Pessoa *_adicionar(Pessoa *);
void _listar(Pessoa *);

#endif // DADOS_H
