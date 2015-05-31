#ifndef DISTRIBUI
#define DISTRIBUI

int Id = 0;

typedef struct _pessoa {
    int id;
    char nome[100];
    unsigned int idade;
} Pessoa;

Pessoa pessoa(char *nome, int idade);

#endif
