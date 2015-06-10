#include <stdio.h>
#include "distribui.h"
#include "zelib.h"
#include "ajuda.h"

// Menu Ajuda
void Ajuda(){
    int opt;
    do {
        // cabeçalho
        zenter_cls(AJUDA_NOME);
        opt = optionz(AJUDA_OPTIONS, AJUDA_N);
        switch(opt) {
        case 1: ajuda_regras();
        break;
        case 2: ajuda_comandos();
        break;
        case 3: ajuda_ajuda();
        break;
        case 4:// Voltar
        case 0: return;
        default: ajuda_default(opt);
        }
    } while(TRUE);
}

// mostra as regras do jogo
void ajuda_regras(){
    char buffer[255] = {'\0'};
    FILE *fd = fopen("regras.txt", "r");
    zenter_cls(AJUDA_NOME);
    putz("[Regras]", 11);
    
    if(fd == NULL) return;
    while(fgets(buffer, 255, fd) != NULL) {
        if(buffer[0] == ' ') printz(7, "%s", buffer);
        else printz(15, "%s", buffer);
    }
    fclose(fd);
    pausa();
}

// mostra os comandos do jogo
void ajuda_comandos(){
    char buffer[255] = {'\0'};
    FILE *fd = fopen("comandos.txt", "r");
    zenter_cls(AJUDA_NOME);
    putz("[Comandos]", 11);
    
    if(fd == NULL) return;
    while(fgets(buffer, 255, fd) != NULL) {
        if(buffer[0] == ' ') printz(7, "%s", buffer);
        else printz(15, "%s", buffer);
    }
    fclose(fd);
    pausa();
 }

void ajuda_ajuda() {
    zenter_cls(AJUDA_NOME);
    Info(AJUDA_OPTIONS, AJUDA_DESCRIPTIONS, AJUDA_N);
}

// trata opçoes desconhecidas
void ajuda_default(int opt){
    zenter_cls(AJUDA_NOME);
    nao_implementado(AJUDA_OPTIONS[opt-1]);
}
