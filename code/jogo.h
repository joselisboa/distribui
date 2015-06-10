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


/*/
typedef struct _cmd {
    char *cmd;
    struct _cmd *prox;
} CMD;
// comandos
CMD *cmds;
//*/

//----------
// Conjunto
//----------
typedef struct _conjunto {
	int id;
	int n;
    No *pessoas;
	struct _conjunto *prox;
} Conjunto;

//---------
// Jogador
//---------
typedef struct _jogador Jogador;
struct _jogador {
    // AFAZER dados do jogo
    struct _cmd *cmds;
};

//
int Jogador_Ativo = 1;

// contador de grupos
int Conjuntos = 0;

// jogadores
Jogador jogadores[2];

// grupos
Conjunto *conjuntos = NULL;

// Pessoas
No *pessoas = NULL;

// função principal do jogo
No *Jogo(No *);

void jogo_jogar();
void jogo_recuperar();
void jogo_salvar();
void jogo_ajuda();
void jogo_default(int);
void jogo_init(No *);

#endif // JOGO_H
