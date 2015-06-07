#ifndef UTIL_H
#define UTIL_H

//------------------
// Menu Utilitários
//------------------
#define UTIL_OPTIONS_N 4
const char * const UTIL_OPTIONS[UTIL_OPTIONS_N] = {
    "Cores", "Caracteres", "Testes", "Voltar"
};

void Util();
void _cores();
void _caracteres();

#endif // UTIL_H
