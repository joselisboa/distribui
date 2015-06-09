#ifndef UTIL_H
#define UTIL_H
#define UTIL_NOME "Utilitarios"
#define UTIL_N 5

const char * const UTIL_OPTIONS[UTIL_N] = {
    "Cores", "Caracteres", "Teclas", "Testes", "Voltar"
};

const char * const UTIL_DESCRIPTIONS[UTIL_N] = {
    "Mostra os codigos das cores",
    "Mostra os codigos dos caracteres",
    "Mostra os codigos das teclas",
    "Entra no menu Testes",
    "Volta ao menu anterior"
};

void Util();
void util_cores();
void util_caracteres();
void util_getch();
void util_default(int);

#endif // UTIL_H
