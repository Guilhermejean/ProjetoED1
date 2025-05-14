#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct objeto{
    int cpf;
    int idade;
    char nome [30];
    struct objeto *prox;
}OBJETO;

typedef struct {
    OBJETO *inicio;
    int tamanho;
}LISTAS_ORDENADA;

void inicializaLista(LISTAS_ORDENADA *lista);
bool estaVazia(LISTAS_ORDENADA *lista);
int tamanhoLista(LISTAS_ORDENADA *lista);
void insereElementoLista(LISTAS_ORDENADA *lista, int cpf, char nome[] , int idade);
void destroiLista(LISTAS_ORDENADA *lista);
void imprimeElemento(LISTAS_ORDENADA *lista);
void destroiLista(LISTAS_ORDENADA *lista);
void inicializaLista(LISTAS_ORDENADA *lista);
void retiraElemento(LISTAS_ORDENADA *lista, int idade);

#endif
