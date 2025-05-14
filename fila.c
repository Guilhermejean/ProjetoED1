#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"





// Inicializa a fila (vazia)
void inicializaFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Adiciona um paciente ao final da fila
void enfileira(Fila* fila, Paciente paciente) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    novo->paciente = paciente;
    if (fila->fim == NULL) {
        // fila está vazia
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

// Remove o paciente do início da fila
Paciente desenfileira(Fila* fila) {
    Paciente vazio;
    strcpy(vazio.nome, "");

    if (fila->inicio == NULL) {
        return vazio;
    }

    NoFila* temp = fila->inicio;
    Paciente p = temp->paciente;
    fila->inicio = temp->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    return p;
}

// Verifica se a fila está vazia
bool filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Imprime todos os pacientes na fila
void imprimeFila(Fila *fila) {
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        printf("Paciente: %s\n", atual->paciente.nome);
        atual = atual->prox;
    }
}

bool pesquisarPaciente(Fila fila, char nome[]) {
    NoFila* atual = fila.inicio;
    while (atual != NULL) {
        
        if (strcmp(atual->paciente.nome, nome) == 0) {
            return true;
        }
        atual = atual->prox;
    }
    return false;
}
