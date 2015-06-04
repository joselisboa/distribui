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

Pessoa pessoa(char *nome, int idade);

#endif
