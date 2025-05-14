#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Objeto {
    int CPF;
    char nome[30];
    int idade;
    struct Objeto *proximo;
} OBJETO;

typedef struct pilha_DINAMICA{
    OBJETO *topo;
    int qnt_elementos;
} PILHA_DINAMICA;

void inicializaPilha(PILHA_DINAMICA *pilha);
bool PilhaEstaVazia(PILHA_DINAMICA *pilha);
int tamanhoPilha(PILHA_DINAMICA *pilha);
void empilha(PILHA_DINAMICA *pilha, int cpf, char nome[30], int idade);
void desempilha(PILHA_DINAMICA *pilha);
void imprimeTopo(PILHA_DINAMICA *pilha);
void destroiPilha(PILHA_DINAMICA *pilha);

#endif