#include "distribui.h" 

#ifndef JOGO_H
#define JOGO_H
#define JOGO_NOME "Jogo"
#define JOGO_N 5

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

//-------
// Grupo
//-------
typedef struct _grupo {
	int id;
	No *pessoas;
	No *prox;
} Grupo;
// contador de grupos
int Grupos_N = 0;
// grupos
Grupo *grupos = NULL;

//---------
// Jogador
//---------
typedef struct _jogador Jogador;
struct _jogador {
    Pessoa jogador;
    // AFAZER dados do jogo
};
// jogadores
Jogador jogadores[2];

// função principal do jogo
No *Jogo(No *);

void jogo_jogar();
void jogo_recuperar();
void jogo_salvar();
void jogo_ajuda();
void jogo_default(int);

#endif // JOGO_H
