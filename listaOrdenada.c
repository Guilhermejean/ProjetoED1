#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listaOrdenada.h"
#include <unistd.h>
// Inicializa a lista ordenada
void inicializaLista(ListaOrdenada* lista){
    lista->inicio = NULL;
}

// Insere nome em ordem alfabética
void insereOrdenado(ListaOrdenada* lista, char nome[]){
    NoLista* novo = malloc(sizeof(NoLista));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (!lista->inicio || strcmp(nome, lista->inicio->nome) < 0){
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return;
    }

    NoLista* atual = lista->inicio;
    while (atual->prox && strcmp(nome, atual->prox->nome) > 0){
        atual = atual->prox;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

// Imprime a lista de nomes
void imprimeLista(ListaOrdenada lista){
    if (estaVazia(&lista)== true)
    {
        printf("\n\nLista vazia\n");
        sleep(3);
        return;
    }
    


    NoLista* atual = lista.inicio;
    
    while (atual){
        printf("Paciente atendido: %s\n", atual->nome);
        atual = atual->prox;
    }
    sleep(3);
}

// Libera memória da lista
void liberaLista(ListaOrdenada* lista){
    NoLista* atual = lista->inicio;
    while (atual) {
        NoLista* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}
bool estaVazia( ListaOrdenada *lista){
    return lista->inicio==0;
}
