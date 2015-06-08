#ifndef DISTRIBUI_H
#define DISTRIBUI_H

#define PESSOAS_DAT "pessoas.dat"

int Id = 0;

typedef struct _pessoa {
    int id;
    char nome[100];
    unsigned int idade;
    struct _pessoa *prox;
} Pessoa;

/*/
typedef struct _no No;
typedef No*, pNo;
struct _no {
	Pessoa *pessoa;
	Pessoa *prox;
	Pessoa Pprev;
};
typedef *Pessoa pPessoa;

//*/

typedef struct _jogador Jogador;
struct _jogador {
    Pessoa jogador;

    // AFAZER dados do jogo
};

//----------------
// Menu Principal
//----------------
#define MENU_OPTIONS_N 5
const char * const MENU_OPTIONS[MENU_OPTIONS_N] = {
    "Jogo", "Dados", "Util", "Info", "Sair"
};
const char * const MENU_DESCRIPTIONS[MENU_OPTIONS_N] = {
    "Iniciar o jogo",
    "Gerir a lista de pessoas",
    "Utilitarios diversos",
    "Mostra esta lista",
    "Terminar o aplicativo"
};

void Iniciar();
void Terminar();
void splash();

Pessoa criar_pessoa(char *, int);
Jogador criar_jogador(Pessoa);
Pessoa *_pessoas();
void _info(const char * const *, const char * const *, const int);
void Nimplementado(const char *);

#endif

