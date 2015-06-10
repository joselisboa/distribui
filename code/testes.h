#ifndef TESTES_H
#define TESTES_H
#define TESTES_NOME "Testes"
#define TESTES_N 4

const char * const TESTES_OPTIONS[TESTES_N] = {
    "Putz", "Printz", "Distribui", "Voltar"
};

const char * const TESTES_DESCRIPTIONS[TESTES_N] = {
    "Testa a funcao putz(char*, int)",
    "Testa a funcao printz(int, char*, ...)",
    "Teste da distribuicao inicial por conjuntos",
    "Volta ao menu anterior"
};

void Testes();
void testes_putz();
void testes_printz();
void testes_default(int);

void testes_distribui();
int testes_cria_distribuicao(int, int, char *);
void testes_preenche_fixo(int [], int, int);

#endif // TESTES_H

