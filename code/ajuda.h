#ifndef AJUDA_H
#define AJUDA_H

#define AJUDA_OPTIONS_N 3
const char * const AJUDA_OPTIONS[AJUDA_OPTIONS_N] = {
    "Regras", "Comandos", "voltar"
};
const char * const AJUDA_DESCRIPTIONS[DADOS_OPTIONS_N] = {
    "As Regras do Jogo",
    "Lista de comandos para jogar",
    "Volta ao Menu Principal"
};

void _regras();
void _comandos();

#endif // AJUDA_H

