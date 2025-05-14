#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include <stdbool.h>
// Estrutura que representa um paciente
typedef struct PacientePrioridade{
    char nome[100];
    int prioridade; // 1 - Alta, 2 - Média, 3 - Baixa
} PacientePrioridade;

// Nó da fila de prioridade
typedef struct NoFilaPrioridade{
    PacientePrioridade paciente;
    struct NoFilaPrioridade* prox;
} NoFilaPrioridade;

// Fila com ponteiro para o início
typedef struct{
    NoFilaPrioridade* inicio;
} FilaPrioridade;

// Funções da fila de prioridade
void inicializaFilaPrioridade(FilaPrioridade* fila);
void enfileiraFilaPrioridade(FilaPrioridade* fila, PacientePrioridade paciente);
PacientePrioridade desenfileiraFilaPrioridade(FilaPrioridade* fila);
bool filaPrioridadeVazia(FilaPrioridade* fila);
void imprimeFilaPrioridade(FilaPrioridade fila);

#endif