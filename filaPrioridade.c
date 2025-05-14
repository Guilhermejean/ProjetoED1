#include "filaPrioridade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
// Inicializa a fila
void inicializaFilaPrioridade(FilaPrioridade* fila){
    fila->inicio = NULL;
}

// Insere paciente na fila com base na prioridade (menor número = maior prioridade)
void enfileiraFilaPrioridade(FilaPrioridade* fila, PacientePrioridade paciente){
    NoFilaPrioridade* novo = malloc(sizeof(NoFilaPrioridade));
    novo->paciente = paciente;
    novo->prox = NULL;

    if (!fila->inicio || paciente.prioridade < fila->inicio->paciente.prioridade) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
        return;
    }

    NoFilaPrioridade* atual = fila->inicio;
    while (atual->prox && atual->prox->paciente.prioridade <= paciente.prioridade) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Remove paciente do início da fila (maior prioridade)
PacientePrioridade desenfileiraFilaPrioridade(FilaPrioridade* fila){
    PacientePrioridade pacienteVazio = {"", -1};

    if (fila->inicio == NULL) {
        return pacienteVazio;
    }

    NoFilaPrioridade* temp = fila->inicio;
    PacientePrioridade p = temp->paciente;
    fila->inicio = temp->prox;
    free(temp);
    return p;
}

// Verifica se a fila está vazia
bool filaPrioridadeVazia(FilaPrioridade* fila){
    return fila->inicio == NULL;
}

// Imprime os pacientes na fila
void imprimeFilaPrioridade(FilaPrioridade fila){
    if (filaPrioridadeVazia(&fila)==true )
    {
        printf("\n\nfila vazia\n");
        sleep(3);
       return;
    }
    
    NoFilaPrioridade* atual = fila.inicio;
    while (atual){
        printf("Paciente: %s | Prioridade: %d\n", atual->paciente.nome, atual->paciente.prioridade);
       
        atual = atual->prox;
    }
}
