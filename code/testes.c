#include <stdio.h>
#include "distribui.h"
#include "zelib.h"
#include "testes.h"

void Testes(){
    int opt;
    do {
        // cabeçalho
        zenter_cls(TESTES_NOME);
        opt = optionz(TESTES_OPTIONS, TESTES_N);
        switch(opt){
        case 1: testes_putz();
        break;
        case 2: testes_printz();
        break;
        case 3: testes_distribui();
        break;        
        case 4:
        case 0: return;
        default: testes_default(opt);
        }
    } while(TRUE);
}

void testes_putz(){
    zenter_cls(TESTES_NOME);
    putz("putz(string, BLUE);", BLUE);
    pausa();
}

void testes_printz(){
    Pessoa pessoa1 = { ++Id, "Ze", 49 };
    Pessoa pessoa2 = { ++Id, "Maria", 31 };
    zenter_cls(TESTES_NOME);
    printz(MAGENTA, "Pessoa #%d: %s, %d\n", pessoa1.id, pessoa1.nome, pessoa1.idade);
    printz(CYAN, "Pessoa #%d: %s, %d\n", pessoa2.id, pessoa2.nome, pessoa2.idade);
    pausa();
}

void testes_default(int opt){
    zenter_cls(TESTES_NOME);
    nao_implementado(TESTES_OPTIONS[opt-1]);
}


void testes_preenche_fixo(int fixo[], int n_pessoas, int n_conj) {
    int i, x, y, c=0;
    
    for(i=0; i<n_pessoas; i++, c++)
        fixo[i] = c % n_conj;

    for(i=0; i<n_pessoas*n_conj; i++)
    {
        x = randz(0, n_pessoas-1);
        do {
            y = randz(0, n_pessoas-1);
        } while(x==y);
        c = fixo[x];
        fixo[x] = fixo[y];
        fixo[y] = c;
    }
}

// Cria um ficheiro txt com a distribuicao inicial de n_pessoas por conj conjuntos
// Devolve 1 se o ficheiro for criado com sucesso 
int testes_cria_distribuicao(int n_pessoas, int n_conj, char *txt)
{
    int conta[n_pessoas];
    int pertence[n_pessoas];
    int fixo[n_pessoas];
    int i, j, pos, x;
    FILE *f;
        
    
    if(n_pessoas < 6 || n_conj < 3 || n_conj > n_pessoas/2)
    {
        printf("Configuracao errada\n");
        return 0;
    }
    
    memset(conta, 0, sizeof(conta));
    srand((unsigned)time(NULL));

    testes_preenche_fixo(fixo, n_pessoas, n_conj);
        
    f = fopen(txt, "w");
    if(f == NULL)
        return 0;
    
    for(i=0; i < n_conj; i++)
    {
        memset(pertence, 0, sizeof(pertence));
        x = randz(2, 3*n_pessoas/n_conj);
        
        for(j=0; j<n_pessoas; j++)
            if(fixo[j] == i)
            {
                pertence[j] = 1;
                x--;
            }
        
        for(j=0; j<x; j++)
        {
            do{
                pos = randz(0, n_pessoas-1);
            }while(pertence[pos]==1 || conta[pos]==2);
            pertence[pos] = 1;
            conta[pos]++;
        }
        
        for(j=0; j<n_pessoas; j++)
            if(pertence[j] == 1)
                fprintf(f, "%d\t", j+1);
        fprintf(f,"\n");
    }

    fclose(f);
    return 1;
}

void testes_distribui() {
    char *filename = "testes_init.txt";
    int p, c;
    
    zenter_cls(TESTES_NOME);
    printf("Pessoas: ");
    scanf("%d", &p);
    printf("Conjuntos: ");
    scanf("%d", &p);

    if(testes_cria_distribuicao(10, 4, filename) == 1)
        printz(10, "[ficheiro '%s' criado com sucesso]\n", filename);
    else printz(12, "[ERRO ao criar o ficheiro '%s']\n", filename);

    pausa();
}
