#ifndef DISTRIBUI
#define DISTRIBUI

int Id = 0;

typedef struct _pessoa {
    int id;
    char nome[100];
    unsigned int idade;
} Pessoa;

typedef struct _jogador Jogador;
struct _jogador {
    Pessoa jogador;
    // dados do jogo
};

//----------------
// Menu Principal
//----------------
#define MENU_OPTIONS_N 4
const char * const MENU_OPTIONS[MENU_OPTIONS_N] = {
    "Jogar", "Dados", "Ajuda", "Sair"
};

Pessoa criar_pessoa(char *, int);
Jogador criar_jogador(Pessoa);
void iniciar();
void sair();
void splash();

#endif
