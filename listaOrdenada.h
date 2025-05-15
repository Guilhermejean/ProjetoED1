#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <stdbool.h>

// Nó da lista ordenada
typedef struct NoLista{
    char nome[100];
    struct NoLista* prox;
} NoLista;

// Lista com ponteiro para o início
typedef struct {
    NoLista* inicio;
} ListaOrdenada;

// Funções da lista ordenada
void inicializaLista(ListaOrdenada* lista);
void insereOrdenado(ListaOrdenada* lista, char nome[]);
void imprimeLista(ListaOrdenada lista);
void liberaLista(ListaOrdenada* lista);
bool estaVazia(ListaOrdenada *lista);

#endif