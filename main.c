#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

        switch (opcao){
        case 1:
            Paciente p;
            setbuf(stdin, NULL);
            printf("Nome do paciente: ");
            fgets(p.nome, 100, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;

            printf("Prioridade de atendimento (1-Emergência, 2-Urgência, 3-Pouco Urgente, 4 - Não Urgente): ");
            scanf("%d", &p.prioridade);

            enfileira(&fila, p);

            char acao[200];
            printf(acao, "Paciente %s adicionado com prioridade %d", p.nome, p.prioridade);
            push(&log, acao);
            break;
        case 2:
            if (!filaVazia(&fila)) {
                Paciente p = desenfileira(&fila);
                printf("Atendendo: %s\n", p.nome);
                insereOrdenado(&historico, p.nome);

                char acao[200];
                printf(acao, "Paciente %s foi atendido", p.nome);
                push(&log, acao);
            } else {
                printf("Nenhum paciente na fila.\n");
            }
            break;
        case 3:
            imprimeFila(fila);
            break;
        case 4:
            imprimeLista(historico);
            break;
        case 5:
            imprimePilha(log);
            break;
        case 0:
            printf("Saindo do sistema...\n");
            sleep(5);
            break;
        
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (opcao != 0);

    liberaLista(&historico);
    liberaPilha(&log);
    return 0;
}