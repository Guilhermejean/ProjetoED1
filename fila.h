// Estrutura que representa um paciente
#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

// Estrutura que representa um paciente
typedef struct Paciente{
    char nome[100];
    int prioridade;
} Paciente;


// Nó da fila
typedef struct NoFila {
    Paciente paciente;
    struct NoFila* prox;
} NoFila;

//Fila dinâmica com ponteiros para início e fim
typedef struct {
    NoFila* inicio;
    NoFila* fim;
} Fila;

// Funções da fila dinâmica
void inicializaFila(Fila* fila);
void enfileira(Fila* fila, Paciente paciente);
Paciente desenfileira(Fila* fila);
bool filaVazia(Fila* fila);
void imprimeFila(Fila *fila);
bool pesquisarPaciente(Fila fila, char nome[]);

#endif
