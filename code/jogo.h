#include "distribui.h" 

#ifndef JOGO_H
#define JOGO_H

//-----------
// Menu Jogo
//-----------
#define JOGO_OPTIONS_N 5
const char * const JOGO_OPTIONS[JOGO_OPTIONS_N] = {
    "Jogar", "Recuperar", "Salvar", "Ajuda", "Voltar"
};
const char * const JOGO_DESCRIPTIONS[JOGO_OPTIONS_N] = {
    "Inicia ou retoma o jogo",
    "Rercupera um jogo guardado"
    "Guarda o presente jogo",
    "Mostra as regras e comandos do jogo",
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
int Grupos = 0;
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
Pessoa *Jogo(Pessoa *);

void _jogar();
void _recuperar();
void _salvar();

Jogador criar_jogador(Pessoa);

#endif // JOGO_H
