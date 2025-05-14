/*Uso: Organizar o atendimento de clientes priorizando, por exemplo, idosos, gestantes ou pessoas com deficiência.

    Estrutura: Fila de prioridade (pode ser implementada com heap ou várias filas separadas por prioridade)

    Funções:

        inserir_cliente(nome, idade, prioridade): Adiciona cliente à fila com base na prioridade.

        chamar_proximo(): Remove e retorna o próximo cliente a ser atendido.

        mostrar_fila(): Exibe os clientes na fila por ordem de atendimento.

        fila_vazia(): Verifica se a fila está vazia.*/

#include "filaPrioridade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void inicializaFila(FILA_PRIORIDADE *fila) {
    fila->inicio = NULL;
    fila->tamanho = 0;
}

bool FilaEstaVazia(FILA_PRIORIDADE *fila) {
    return fila->inicio == NULL;
}

int tamanhoFila(FILA_PRIORIDADE *fila) {
    return fila->tamanho;
}

void insereElementoFila(FILA_PRIORIDADE *fila, int prioridade, char nome[]) {
    ELEMENTO *novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    if (!novo) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novo->prioridade = prioridade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (FilaEstaVazia(fila) || prioridade < fila->inicio->prioridade) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
    } else {
        ELEMENTO *atual = fila->inicio;
        while (atual->prox != NULL && atual->prox->prioridade <= prioridade) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }

    fila->tamanho++;
}

void removeElemento(FILA_PRIORIDADE *fila) {
    if (FilaEstaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    ELEMENTO *temp = fila->inicio;
    fila->inicio = fila->inicio->prox;
    printf("Removido: %s (Prioridade: %d)\n", temp->nome, temp->prioridade);
    free(temp);
    fila->tamanho--;
}

void imprimeFila(FILA_PRIORIDADE *fila) {
    if (FilaEstaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    ELEMENTO *atual = fila->inicio;
    while (atual != NULL) {
        printf("Nome: %s | Prioridade: %d\n", atual->nome, atual->prioridade);
        atual = atual->prox;
    }
}

void destroiFila(FILA_PRIORIDADE *fila) {
    ELEMENTO *atual = fila->inicio;
    while (atual != NULL) {
        ELEMENTO *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    fila->inicio = NULL;
    fila->tamanho = 0;
}
