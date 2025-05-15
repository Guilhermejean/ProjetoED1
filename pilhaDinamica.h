#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

// Nó da pilha
typedef struct NoPilha {
    char acao[200];
    struct NodoPilha* prox;
} NoPilha;

// Pilha com ponteiro para o topo
typedef struct {
    NoPilha* topo;
} Pilha;

// Funções da pilha dinâmica
void inicializaPilha(Pilha* pilha);
void push(Pilha* pilha, char acao[]);
char* pop(Pilha* pilha);
void imprimePilha(Pilha pilha);
void liberaPilha(Pilha* pilha);

#endif
