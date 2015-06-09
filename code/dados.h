#include "distribui.h"

#ifndef DADOS_H
#define DADOS_H

//------------
// Menu Dados
//------------
// n items
#define DADOS_OPTIONS_N 7
// opções
const char * const DADOS_OPTIONS[DADOS_OPTIONS_N] = {
    "Listar", "Adicionar", "Remover", "Importar", "Exportar", "Ajuda", "voltar"
};
// descritivo das opções
const char * const DADOS_DESCRIPTIONS[DADOS_OPTIONS_N] = {
    "Lista as Pessoas na lista",
    "Adiciona uma Pessoa na lista",
    "Remove uma pessoa da lista pelo seu Id",
    "Importa pessoas num ficheiro de texto",
    "Exporta as pessoas para um ficheiro de texto",
    "Mostra esta lista",
    "Volta ao menu anterior"
};

No *Dados(No *);

void dados_listar(No *);
No *dados_adicionar(No *);
No *dados_remover(No *);
int dados_guardar(No *);

int guardaLista(No *);

#endif // DADOS_H
