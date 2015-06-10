#include "distribui.h" 
#include "zelib.h"

#ifndef JOGO_H
#define JOGO_H
#define JOGO_NOME "Jogo"
#define JOGO_N 6

const char * const JOGO_OPTIONS[JOGO_N] = {
    "Jogar", "Recuperar", "Salvar", "Regras", "Ajuda", "Voltar"
};

const char * const JOGO_DESCRIPTIONS[JOGO_N] = {
    "Inicia ou retoma o jogo",
    "Rercupera um jogo guardado"
    "Guarda o presente jogo",
    "Mostra as regras e comandos do jogo",
    "Mostra esta lista",
    "Volta ao menu principal"
};

//----------
// Conjunto
//----------
typedef struct _conjunto {
	int id;
	No *pessoas;
	No *prox;
} Conjunto;

typedef struct _cmd {
    char *cmd;
    struct _cmd *prox;
} CMD;

//---------
// Jogador
//---------
typedef struct _jogador Jogador;
struct _jogador {
    Pessoa jogador;
    // AFAZER dados do jogo
    struct _cmd *cmds;
};

// historico
CMD *cmds;

//
int Jogador_Ativo = 1;
// contador de grupos
int Conjuntos = 0;
// jogadores
Jogador jogadores[2];
// grupos
Conjunto *conjuntos = NULL;

// função principal do jogo
No *Jogo(No *);

void jogo_jogar();
void jogo_recuperar();
void jogo_salvar();
void jogo_ajuda();
void jogo_default(int);

#endif // JOGO_H
