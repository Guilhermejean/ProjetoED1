#include "filaPrioridade.h"  // Cabeçalho da fila de prioridade
#include <stdio.h>           // Biblioteca para entrada/saída padrão
#include <stdlib.h>          // Biblioteca para funções de alocação dinâmica (malloc, free)
#include <string.h>          // Biblioteca para manipulação de strings (strcpy, strcmp, etc.)
#include <unistd.h>          // Biblioteca para funções como sleep()
#include <stdbool.h>         // Biblioteca para tipo booleano (true/false)

// Inicializa a fila, apontando o início para NULL
void inicializaFilaPrioridade(FilaPrioridade* fila) {
    fila->inicio = NULL;
}

// Insere paciente na fila de forma ordenada por prioridade
// Menor número = maior prioridade
void enfileiraFilaPrioridade(FilaPrioridade* fila, PacientePrioridade paciente) {
    // Cria um novo nó com os dados do paciente
    NoFilaPrioridade* novo = malloc(sizeof(NoFilaPrioridade));
    novo->paciente = paciente;
    novo->prox = NULL;

    // Se a fila está vazia ou o paciente tem prioridade maior que o primeiro
    if (!fila->inicio || paciente.prioridade < fila->inicio->paciente.prioridade) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
        return;
    }

    // Busca o local correto para inserir o novo paciente
    NoFilaPrioridade* atual = fila->inicio;
    while (atual->prox && atual->prox->paciente.prioridade <= paciente.prioridade) {
        atual = atual->prox;
    }

    // Insere o novo paciente na posição certa
    novo->prox = atual->prox;
    atual->prox = novo;
}

// Remove o primeiro paciente da fila (com maior prioridade)
PacientePrioridade desenfileiraFilaPrioridade(FilaPrioridade* fila) {
    // Caso a fila esteja vazia, retorna um paciente "vazio"
    PacientePrioridade pacienteVazio = {"", -1};
    if (fila->inicio == NULL) {
        return pacienteVazio;
    }

    // Remove o primeiro paciente da fila
    NoFilaPrioridade* temp = fila->inicio;
    PacientePrioridade p = temp->paciente;
    fila->inicio = temp->prox;
    free(temp);
    return p;
}

// Verifica se a fila está vazia
bool filaPrioridadeVazia(FilaPrioridade* fila) {
    return fila->inicio == NULL;
}

// Imprime todos os pacientes da fila com prioridade
void imprimeFilaPrioridade(FilaPrioridade fila) {
    if (filaPrioridadeVazia(&fila)) {
        printf("\n\nFila vazia\n");
        sleep(3);
        return;
    }

    // Percorre e imprime cada paciente da fila
    NoFilaPrioridade* atual = fila.inicio;
    while (atual) {
        printf("Paciente: %s | Prioridade: %d\n", atual->paciente.nome, atual->paciente.prioridade);
        atual = atual->prox;
    }
}
