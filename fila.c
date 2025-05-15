#include <stdio.h>              // Biblioteca padrão de entrada e saída
#include <stdlib.h>             // Para uso de malloc() e free()
#include <string.h>             // Para funções de string como strcpy() e strcmp()
#include "fila.h"               // Interface da fila dinâmica

// Inicializa a fila (vazia)
void inicializaFila(Fila* fila) {
    fila->inicio = NULL;  // Ponteiro de início aponta para NULL
    fila->fim = NULL;     // Ponteiro de fim também aponta para NULL
}

// Adiciona um paciente ao final da fila (FIFO)
void enfileira(Fila* fila, Paciente paciente) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila)); // Aloca novo nó
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    novo->paciente = paciente; // Copia os dados do paciente para o novo nó
    novo->prox = NULL;

    if (fila->fim == NULL) {
        // A fila está vazia
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        // A fila tem elementos; adiciona ao final
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

// Remove o paciente do início da fila
Paciente desenfileira(Fila* fila) {
    Paciente vazio;
    strcpy(vazio.nome, ""); // Caso a fila esteja vazia, retorna paciente com nome vazio

    if (fila->inicio == NULL) {
        return vazio;
    }

    NoFila* temp = fila->inicio;
    Paciente p = temp->paciente;
    fila->inicio = temp->prox; // Avança o início para o próximo nó

    if (fila->inicio == NULL) {
        fila->fim = NULL; // Se a fila ficou vazia, zera o fim também
    }

    free(temp); // Libera o nó removido
    return p;   // Retorna o paciente removido
}

// Verifica se a fila está vazia
bool filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Imprime todos os pacientes na fila
void imprimeFila(Fila* fila) {
    NoFila* atual = fila->inicio;
    while (atual != NULL) {
        printf("Paciente: %s\n", atual->paciente.nome);
        atual = atual->prox;
    }
}

// Pesquisa por um paciente na fila pelo nome
bool pesquisarPaciente(Fila fila, char nome[]) {
    NoFila* atual = fila.inicio;
    while (atual != NULL) {
        if (strcmp(atual->paciente.nome, nome) == 0) {
            return true; // Encontrado
        }
        atual = atual->prox;
    }
    return false; // Não encontrado
}
