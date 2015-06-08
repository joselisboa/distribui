#ifndef JOGO_H
#define JOGO_H

//-----------
// Menu Jogo
//-----------
#define JOGO_OPTIONS_N 3
const char * const JOGO_OPTIONS[JOGO_OPTIONS_N] = {
    "Jogar", "Recuperar", "Salvar", "Ajuda", "Voltar"
};
const char * const JOGO_DESCRIPTIONS[DADOS_OPTIONS_N] = {
    "Inicia ou retoma o jogo",
    "Rercupera um jogo guardado"
    "Guarda o presente jogo",
    "Mostra as regras e comandos do jogo",
    "Volta ao menu principal"
};

Pessoa *Jogo(Pessoa *);
void _jogar();
void _recuperar();
void _salvar();

#endif // JOGO_H

