/*2. Lista Encadeada (Histórico de Apostas)

Uso: Armazenar o histórico de todas as apostas feitas pelos clientes.

    Estrutura: Lista encadeada simples ou dupla.

    Funções:

        registrar_aposta(cliente, tipo_jogo, numeros_apostados): Adiciona nova aposta ao final da lista.

        listar_apostas(): Exibe todas as apostas registradas.

        buscar_apostas_por_cliente(nome): Retorna apostas feitas por um cliente específico.

        remover_aposta(id): Remove uma aposta da lista com base em um identificador.

        contar_apostas(): Retorna o total de apostas feitas.*/

#include "listaOrdenada.h"  // Inclui o cabeçalho
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Inicializa a lista (define início como NULL e tamanho como 0)
void inicializaLista(LISTAS_ORDENADA *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

// Verifica se a lista está vazia
bool estaVazia(LISTAS_ORDENADA *lista) {
    return (lista->inicio == NULL);
}

// Retorna o tamanho da lista
int tamanhoLista(LISTAS_ORDENADA *lista) {
    return lista->tamanho;
}

// Insere um novo elemento na lista (ordenado por CPF)
void insereElementoLista(LISTAS_ORDENADA *lista, int cpf, char nome[], int idade) {
    OBJETO *novo = (OBJETO*) malloc(sizeof(OBJETO));
    if (!novo) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    novo->cpf = cpf;
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    // Caso a lista esteja vazia ou o novo CPF seja menor que o primeiro
    if (estaVazia(lista) || cpf < lista->inicio->cpf) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        OBJETO *atual = lista->inicio;
        // Percorre até encontrar a posição correta (ordenado por CPF)
        while (atual->prox != NULL && atual->prox->cpf < cpf) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
    lista->tamanho++;
}

// Remove um elemento com base na idade
void retiraElemento(LISTAS_ORDENADA *lista, int idade) {
    if (estaVazia(lista)) return;

    OBJETO *anterior = NULL;
    OBJETO *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->idade == idade) {
            if (anterior == NULL) {  // Remoção no início
                lista->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            OBJETO *temp = atual;
            atual = atual->prox;
            free(temp);
            lista->tamanho--;
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

// Imprime todos os elementos da lista
void imprimeElemento(LISTAS_ORDENADA *lista) {
    if (estaVazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }

    OBJETO *atual = lista->inicio;
    while (atual != NULL) {
        printf("CPF: %d, Nome: %s, Idade: %d\n", atual->cpf, atual->nome, atual->idade);
        atual = atual->prox;
    }
}

// Libera toda a memória alocada na lista
void destroiLista(LISTAS_ORDENADA *lista) {
    OBJETO *atual = lista->inicio;
    while (atual != NULL) {
        OBJETO *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
}