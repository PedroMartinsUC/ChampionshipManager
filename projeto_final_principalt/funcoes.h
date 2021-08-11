#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROJETO_FINAL_FUNCOES_H
#define PROJETO_FINAL_FUNCOES_H

#define MAXSIZE 50

//Estruturas de dados:

typedef struct equipa {
    char nome[MAXSIZE];
    int pontos;
}equipa;

//Estruturas das pilhas:

struct pilha {
    equipa equipas;
    struct pilha *pseg;
};

//Pilha 1:

void inicializar_pilha();
int Emptycheck();
int push(struct equipa d);
struct equipa pop();

//Pilha 2:

void inicializar_pilha2();
int Emptycheck2();
int push2(struct equipa e);
struct equipa pop2();

//Pilha 3:

void inicializar_pilha3();
int Emptycheck3();
int push3(struct equipa f);
struct equipa pop3();

//Funções para deteção de erros:

int Extcheck(char nome[MAXSIZE], char extensao[MAXSIZE]);

//Funções do programa:

int readteams(char *inp, int n);
int readresults(char *inp, int n);
void addPoints(char equipa[MAXSIZE], int pontos, int n);
void Organizar();
void Imprimir(int n);

#endif //PROJETO_FINAL_FUNCOES_H