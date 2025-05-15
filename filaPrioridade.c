#include "filaPrioridade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
// Inicializa a fila
void inicializaFila(FilaPrioridade* fila){
    fila->inicio = NULL;
}

// Insere paciente na fila com base na prioridade (menor número = maior prioridade)
void enfileira(FilaPrioridade* fila, Paciente paciente){
    NoFila* novo = malloc(sizeof(NoFila));
    novo->paciente = paciente;
    novo->prox = NULL;

    if (!fila->inicio || paciente.prioridade < fila->inicio->paciente.prioridade) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
        return;
    }

    NoFila* atual = fila->inicio;
    while (atual->prox && atual->prox->paciente.prioridade <= paciente.prioridade) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Remove paciente do início da fila (maior prioridade)
Paciente desenfileira(FilaPrioridade* fila){
    Paciente pacienteVazio = {"", -1};

    if (fila->inicio == NULL) {
        return pacienteVazio;
    }

    NoFila* temp = fila->inicio;
    Paciente p = temp->paciente;
    fila->inicio = temp->prox;
    free(temp);
    return p;
}

// Verifica se a fila está vazia
bool filaVazia(FilaPrioridade* fila){
    return fila->inicio == NULL;
}

// Imprime os pacientes na fila
void imprimeFila(FilaPrioridade fila){
    if (filaVazia(&fila)==true )
    {
        printf("\n\nfila vazia\n");
        sleep(3);
       return;
    }
    
    NoFila* atual = fila.inicio;
    while (atual){
        printf("Paciente: %s | Prioridade: %d\n", atual->paciente.nome, atual->paciente.prioridade);
        sleep(3);
        atual = atual->prox;
    }
}
