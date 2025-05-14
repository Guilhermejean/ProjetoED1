#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

// Nó da lista ordenada
typedef struct NodoLista {
    char nome[100];
    struct NodoLista* prox;
} NodoLista;

// Lista com ponteiro para o início
typedef struct {
    NodoLista* inicio;
} ListaOrdenada;

// Funções da lista ordenada
void inicializaLista(ListaOrdenada* lista);
void insereOrdenado(ListaOrdenada* lista, char nome[]);
void imprimeLista(ListaOrdenada lista);
void liberaLista(ListaOrdenada* lista);

#endif