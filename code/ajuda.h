#ifndef AJUDA_H
#define AJUDA_H
#define AJUDA_NOME "Ajuda"
#define AJUDA_N 4

const char * const AJUDA_OPTIONS[AJUDA_OPTIONS_N] = {
    "Regras", "Comandos", "Ajuda", "voltar"
};

const char * const AJUDA_DESCRIPTIONS[DADOS_OPTIONS_N] = {
    "As Regras do Jogo",
    "Lista de comandos para jogar",
    "Mostra esta lista",
    "Volta ao Menu Principal"
};

void Ajuda();
void ajuda_regras();
void ajuda_comandos();
void ajuda_ajuda();
void ajuda_default(int);

#endif // AJUDA_H
