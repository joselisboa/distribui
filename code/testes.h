#ifndef TESTES_H
#define TESTES_H
#define TESTES_NOME "Testes"
#define TESTES_N 3

const char * const TESTES_OPTIONS[TESTES_N] = {
    "Putz", "Printz", "Voltar"
};

const char * const TESTES_DESCRIPTIONS[TESTES_N] = {
    "Testa a funcao putz(char*, int)",
    "Testa a funcao printz(int, char*, ...)",
    "Volta ao menu anterior"
};

void Testes();
void testes_putz();
void testes_printz();
void testes_default(int);

#endif // TESTES_H

