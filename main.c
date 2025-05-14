#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaPrioridade.h"
#include "listaOrdenada.h"
#include "pilhaDinamica.h"

// Exibe o menu da UPA
void menu() {
    printf("\n--- UPA - Sistema de Atendimento ---\n");
    printf("1. Adicionar paciente\n");
    printf("2. Atender paciente\n");
    printf("3. Ver fila de espera\n");
    printf("4. Ver histórico de atendimentos\n");
    printf("5. Ver log de ações\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

int main() {
    FilaPrioridade fila;
    ListaOrdenada historico;
    Pilha log;

    // Inicialização das estruturas
    inicializaFila(&fila);
    inicializaLista(&historico);
    inicializaPilha(&log);

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Paciente p;
            printf("Nome do paciente: ");
            fgets(p.nome, 100, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;
            printf("Prioridade (1-Alta, 2-Média, 3-Baixa): ");
            scanf("%d", &p.prioridade);
            getchar();

            enfileira(&fila, p);

            char acao[200];
            sprintf(acao, "Paciente %s adicionado com prioridade %d", p.nome, p.prioridade);
            push(&log, acao);

        } else if (opcao == 2) {
            if (!filaVazia(&fila)) {
                Paciente p = desenfileira(&fila);
                printf("Atendendo: %s\n", p.nome);
                insereOrdenado(&historico, p.nome);

                char acao[200];
                sprintf(acao, "Paciente %s foi atendido", p.nome);
                push(&log, acao);
            } else {
                printf("Nenhum paciente na fila.\n");
            }

        } else if (opcao == 3) {
            imprimeFila(fila);

        } else if (opcao == 4) {
            imprimeLista(historico);

        } else if (opcao == 5) {
            imprimePilha(log);
        }

    } while (opcao != 0);

    liberaLista(&historico);
    liberaPilha(&log);
    return 0;
}