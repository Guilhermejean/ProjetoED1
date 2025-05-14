#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
    int prioridade;
    char nome[30];
    struct elemento *prox;
} ELEMENTO;

typedef struct fila_prioridade{
    ELEMENTO *inicio;
    int tamanho;
} FILA_PRIORIDADE;

void inicializaFila(FILA_PRIORIDADE *fila);
bool FilaEstaVazia(FILA_PRIORIDADE *fila);
int tamanhoFila(FILA_PRIORIDADE *fila);
void insereElementoFila(FILA_PRIORIDADE *fila, int prioridade, char nome[]);
void removeElemento(FILA_PRIORIDADE *fila);
void imprimeFila(FILA_PRIORIDADE *fila);
void destroiFila(FILA_PRIORIDADE *fila);

#endif
