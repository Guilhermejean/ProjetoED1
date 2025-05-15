#include <stdio.h>              // Biblioteca padrão de entrada/saída
#include <stdlib.h>             // Biblioteca para alocação dinâmica
#include <stdbool.h>            // Suporte ao tipo booleano (true/false)
#include <string.h>             // Manipulação de strings
#include "listaOrdenada.h"      // Interface da lista ordenada
#include <unistd.h>             // Função sleep()

// Inicializa a lista ordenada (define o ponteiro inicial como NULL)
void inicializaLista(ListaOrdenada* lista){
    lista->inicio = NULL;
}

// Insere um novo paciente na lista em ordem alfabética
void insereOrdenado(ListaOrdenada* lista, char nome[]){
    // Aloca espaço para o novo nó
    NoLista* novo = malloc(sizeof(NoLista));
    strcpy(novo->nome, nome);   // Copia o nome para o novo nó
    novo->prox = NULL;

    // Caso a lista esteja vazia ou o novo nome venha antes do primeiro, insere no início
    if (!lista->inicio || strcmp(nome, lista->inicio->nome) < 0){
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return;
    }

    // Caso contrário, encontra a posição correta na lista para manter a ordenação
    NoLista* atual = lista->inicio;
    while (atual->prox && strcmp(nome, atual->prox->nome) > 0){
        atual = atual->prox;
    }

    // Insere o novo nó na posição encontrada
    novo->prox = atual->prox;
    atual->prox = novo;
}

// Imprime todos os nomes da lista ordenada
void imprimeLista(ListaOrdenada lista){
    // Verifica se a lista está vazia
    if (estaVazia(&lista) == true) {
        printf("\n\nLista vazia\n");
        sleep(3);  // Espera 3 segundos para facilitar leitura
        return;
    }

    // Percorre e imprime os elementos da lista
    NoLista* atual = lista.inicio;
    while (atual){
        printf("Paciente atendido: %s\n", atual->nome);
        atual = atual->prox;
    }

    sleep(3); // Pausa após impressão
}

// Libera toda a memória alocada pela lista
void liberaLista(ListaOrdenada* lista){
    NoLista* atual = lista->inicio;
    while (atual) {
        NoLista* temp = atual;
        atual = atual->prox;
        free(temp); // Libera cada nó individualmente
    }
    lista->inicio = NULL; // Marca a lista como vazia
}

// Retorna true se a lista estiver vazia (início aponta para NULL)
bool estaVazia(ListaOrdenada* lista){
    return lista->inicio == NULL;
}
