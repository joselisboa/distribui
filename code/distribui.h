#ifndef DISTRIBUI_H
#define DISTRIBUI_H
#define DISTRIBUI_N 5
#define DISTRIBUI_NOME "Menu Principal"

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

const char * const DISTRIBUI_OPTIONS[DISTRIBUI_N] = {
    "Jogo", "Dados", "Util", "Ajuda", "Sair"
};

const char * const DISTRIBUI_DESCRIPTIONS[DISTRIBUI_N] = {
    "Iniciar o jogo",
    "Gerir a lista de pessoas",
    "Utilitarios diversos",
    "Mostra esta lista",
    "Terminar o aplicativo"
};

void Distribui();
void distribui_ajuda();
void distribui_default(int);

void nao_implementado(const char *);
void terminar();
void splash();

No *Lista();
No *libertaNo(No *);
No *adicionaNo(Pessoa, No *);
No *removeNo(int *, No *);

#endif
