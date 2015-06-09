#ifndef DISTRIBUI_H
#define DISTRIBUI_H

#define PESSOAS_DAT "pessoas.dat"
#define PESSOAS_TXT "pessoas.txt"

int Id = 0;
int Pessoas = 0;

typedef struct _pessoa {
    int id;
    char nome[100];
    unsigned int idade;
} Pessoa;

typedef Pessoa* pPessoa;

typedef struct _no No;
//typedef No* pNo;
struct _no {
    Pessoa *pessoa;
    No *prox;
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

void Nimplementado(const char *);

No *Lista();
No *libertaNo(No *);
No *adicionaNo(Pessoa, No *);
No *removeNo(int *, No *);

#endif
