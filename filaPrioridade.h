#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

// Estrutura que representa um paciente
typedef struct Paciente {
    char nome[100];
    int prioridade; // 1 - Alta, 2 - Média, 3 - Baixa
} Paciente;

// Nó da fila de prioridade
typedef struct NodoFila {
    Paciente paciente;
    struct NodoFila* prox;
} NodoFila;

// Fila com ponteiro para o início
typedef struct {
    NodoFila* inicio;
} FilaPrioridade;

// Funções da fila de prioridade
void inicializaFila(FilaPrioridade* fila);
void enfileira(FilaPrioridade* fila, Paciente paciente);
Paciente desenfileira(FilaPrioridade* fila);
int filaVazia(FilaPrioridade* fila);
void imprimeFila(FilaPrioridade fila);

#endif