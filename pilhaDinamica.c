#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaDinamica.h"
#include <stdbool.h>
// Inicializa a pilha
void inicializaPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

// Adiciona uma nova ação ao topo
void push(Pilha* pilha, char acao[]) {
    NoPilha* novo = malloc(sizeof(NoPilha));
    strcpy(novo->acao, acao);
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// Remove e retorna a última ação registrada
char* pop(Pilha* pilha) {
    static char acao[200];
    if (!pilha->topo) return NULL;

    NoPilha* temp = pilha->topo;
    strcpy(acao, temp->acao);
    pilha->topo = temp->prox;
    free(temp);
    return acao;
}
bool PilhaVazia(Pilha pilha){
    return pilha.topo==NULL;
}

// Imprime todas as ações da pilha
void imprimePilha(Pilha pilha) {
    if (PilhaVazia(pilha))
    {
        printf("pilha vazia\n");
        return;
    }
    
    NoPilha* atual = pilha.topo;
    while (atual) {
        printf("Ação: %s\n", atual->acao);
        atual = atual->prox;
    }
}

// Libera memória da pilha
void liberaPilha(Pilha* pilha) {
    NoPilha* atual = pilha->topo;
    while (atual) {
        NoPilha* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    pilha->topo = NULL;
}