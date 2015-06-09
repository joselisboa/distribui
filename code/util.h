#ifndef UTIL_H
#define UTIL_H
#define UTIL_NOME "Utilitarios"
#define UTIL_N 6

const char * const UTIL_OPTIONS[UTIL_N] = {
    "Cores", "Caracteres", "Teclas", "Testes", "Ajuda", "Voltar"
};

const char * const UTIL_DESCRIPTIONS[UTIL_N] = {
    "Mostra os codigos das cores",
    "Mostra os codigos dos caracteres",
    "Mostra os codigos das teclas",
    "Mostra esta lista",
    "Entra no menu Testes",
    "Volta ao menu anterior"
};

void Util();
void util_cores();
void util_caracteres();
void util_getch();
void util_ajuda();
void util_default(int);

#endif // UTIL_H
