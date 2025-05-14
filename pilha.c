/*3. Pilha (Histórico de Operações ou Caixa)

Uso: Controlar ações recentes, como desfazer última operação (aposta cancelada) ou movimentações do caixa.

    Estrutura: Pilha (LIFO)

    Funções:

        registrar_operacao(tipo, detalhes): Empilha uma nova operação (ex: "aposta feita", "cancelamento", etc).

        desfazer_ultima_operacao(): Desempilha e desfaz a última ação.

        mostrar_historico_operacoes(): Exibe as últimas operações (topo da pilha para base).

        pilha_vazia(): Verifica se há operações na pilha.*/
        
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"

void inicializaPilha(PILHA_DINAMICA *pilha) {
    pilha->topo = NULL;
    pilha->qnt_elementos = 0;
}

bool PilhaEstaVazia(PILHA_DINAMICA *pilha) {
    return (pilha->qnt_elementos == 0);
}

int tamanhoPilha(PILHA_DINAMICA *pilha) {
    return pilha->qnt_elementos;
}

void empilha(PILHA_DINAMICA *pilha, int cpf, char nome[30], int idade) {
    OBJETO *aux = (OBJETO*) malloc(sizeof(OBJETO));
    if (aux == NULL) {
        printf("\n NÃO FOI POSSIVEL ALOCAR MEMÓRIA\n");
        return;
    }
    aux->CPF = cpf;
    aux->idade = idade;
    strcpy(aux->nome, nome);
    aux->proximo = pilha->topo; // Conecta o novo objeto ao topo atual
    pilha->topo = aux;           // Atualiza o topo para o novo objeto
    pilha->qnt_elementos++;
}

void desempilha(PILHA_DINAMICA *pilha) {
    if (estaVazia(pilha)) {
        printf("pilha vazia\n");
        return;
    }
    OBJETO *aux = pilha->topo;  // Guarda o topo para liberar depois
    pilha->topo = aux->proximo;  // Atualiza o topo para o próximo
    free(aux);                   // Libera a memória do objeto desempilhado
    pilha->qnt_elementos--;
}

void imprimeTopo(PILHA_DINAMICA *pilha) {
    if (estaVazia(pilha)) {
        printf("pilha vazia\n");
        return;
    }
    printf("%s, %i, %i\n", pilha->topo->nome, pilha->topo->CPF, pilha->topo->idade);
}
void destroiPilha(PILHA_DINAMICA *pilha){

while (estaVazia(pilha)==false)
{
    desempilha(pilha);
}

   
return;

}

