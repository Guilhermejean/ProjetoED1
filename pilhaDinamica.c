#include <stdio.h>              // Biblioteca padrão de entrada e saída
#include <stdlib.h>             // Para alocação dinâmica (malloc, free)
#include <string.h>             // Para manipulação de strings (strcpy, etc.)
#include "pilhaDinamica.h"      // Interface da pilha dinâmica
#include <stdbool.h>            // Para uso do tipo booleano
#include <unistd.h>             // Para uso da função sleep()

// Inicializa a pilha (define o topo como NULL)
void inicializaPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

// Insere uma nova ação no topo da pilha
void push(Pilha* pilha, char acao[]) {
    NoPilha* novo = malloc(sizeof(NoPilha));   // Aloca novo nó
    strcpy(novo->acao, acao);                  // Copia o texto da ação
    novo->prox = pilha->topo;                  // Faz o novo nó apontar para o topo atual
    pilha->topo = novo;                        // Atualiza o topo da pilha
}

// Remove e retorna a última ação registrada (topo da pilha)
char* pop(Pilha* pilha) {
    static char acao[200];                     // Buffer estático para retornar o texto

    if (!pilha->topo) return NULL;             // Se a pilha estiver vazia, retorna NULL

    NoPilha* temp = pilha->topo;               // Guarda o nó atual do topo
    strcpy(acao, temp->acao);                  // Copia a ação para o buffer
    pilha->topo = temp->prox;                  // Atualiza o topo para o próximo nó
    free(temp);                                // Libera o nó anterior
    return acao;                               // Retorna a ação removida
}

// Apaga toda a pilha (libera todos os nós)
void Apaga_pilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("nenhum log a ser apagado\n");
        sleep(2);
        return;
    }

    // Libera todos os nós da pilha um por um
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    // Após apagar todos os nós, o topo deve apontar para NULL
    pilha->topo = NULL;
}

// Verifica se a pilha está vazia
bool PilhaVazia(Pilha pilha) {
    return pilha.topo == NULL;
}

// Imprime todas as ações armazenadas na pilha
void imprimePilha(Pilha pilha) {
    if (PilhaVazia(pilha)) {
        printf("pilha vazia\n");
        return;
    }

    // Percorre a pilha do topo até o fim
    NoPilha* atual = pilha.topo;
    while (atual) {
        printf("Ação: %s\n", atual->acao);
        atual = atual->prox;
    }
}

// Libera memória da pilha (usada no encerramento do programa)
void liberaPilha(Pilha* pilha) {
    NoPilha* atual = pilha->topo;
    while (atual) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    pilha->topo = NULL;  // Marca a pilha como vazia
}
