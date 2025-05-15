// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "filaPrioridade.h"
#include "listaOrdenada.h"
#include "pilhaDinamica.h"
#include "fila.h"

// Função que exibe o menu da UPA
void menu() {
    printf("\n--- UPA - Sistema de Atendimento ---\n");
    printf("1. Adicionar paciente\n");
    printf("2. Atender paciente\n");
    printf("3. Ver fila de espera com prioridade\n");
    printf("4. Ver histórico de atendimentos\n");
    printf("5. Ver log de ações\n");
    printf("6. apagar o ultimo log\n");
    printf("7. apagar todos log\n");
    printf("8. Ver fila de espera\n");
    printf("9. Pesquisar paciente\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

int main() {
    // Estruturas utilizadas
    FilaPrioridade fila;         // Fila com prioridade para triagem
    Fila filaNormal;             // Fila simples usada para pesquisa
    ListaOrdenada historico;    // Lista de pacientes atendidos (ordenada)
    Pilha log;                   // Pilha de ações (log)

    // Inicialização das estruturas
    inicializaFilaPrioridade(&fila);
    inicializaLista(&historico);
    inicializaPilha(&log);
    inicializaFila(&filaNormal);

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            // Adiciona novo paciente
            PacientePrioridade p;
            Paciente pa;
            setbuf(stdin, NULL);
            printf("Nome do paciente: ");
            fgets(p.nome, 100, stdin);
            p.nome[strcspn(p.nome, "\n")] = 0;
         
            printf("Prioridade de atendimento (1-Emergência, 2-Urgência, 3-Pouco Urgente, 4 - Não Urgente): ");
            scanf("%d", &p.prioridade);

            enfileiraFilaPrioridade(&fila, p); // Adiciona na fila com prioridade
            
            // Adiciona na fila normal para fins de busca
            strcpy(pa.nome, p.nome);
            pa.prioridade= p.prioridade;
            enfileira(&filaNormal, pa);

            // Registra log da ação
            char acao[20000];
            sprintf(acao, "Paciente %s, prioridade %d", p.nome, p.prioridade);
            push(&log, acao);
            break;

        case 2:
            // Atende paciente com maior prioridade
            if (!filaPrioridadeVazia(&fila)) {
                PacientePrioridade p = desenfileiraFilaPrioridade(&fila);
                printf("Atendendo: %s\n", p.nome);
                insereOrdenado(&historico, p.nome);

                char acao[200];
                sprintf(acao, "Paciente %s foi atendido", p.nome);
                push(&log, acao);
            } else {
                printf("Nenhum paciente na fila.\n");
            }
            break;

        case 3:
            // Mostra fila com prioridade
            imprimeFilaPrioridade(fila);
            break;

        case 4:
            // Mostra pacientes já atendidos
            imprimeLista(historico);
            break;

        case 5:
            // Exibe log de ações
            imprimePilha(log);
            break;

        case 6:
            // Remove o último log
            pop(&log);
            break;

        case 7:
            // Apaga todos os logs
            Apaga_pilha(&log);
            break;

        case 8:
            // Mostra a fila de espera (normal)
            printf("Fila de espera:\n");
            imprimeFila(&filaNormal);
            break;

        case 9:
            // Pesquisa paciente na fila
            setbuf(stdin, NULL);
            char nome[100];
            printf("Nome do paciente: ");
            setbuf(stdin, NULL);
            fgets(nome, 100, stdin);
            setbuf(stdin, NULL);
            nome[strcspn(nome, "\n")] = 0;

            if (pesquisarPaciente(filaNormal, nome)) {
                printf("Paciente %s encontrado na fila.\n", nome);
            } else {
                printf("Paciente %s não encontrado na fila.\n", nome);
            }
            break;

        case 0:
            // Encerra o sistema
            printf("Saindo do sistema...\n");
            sleep(2);
            break;
        
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

    } while (opcao != 0);

    // Libera memória das estruturas
    liberaLista(&historico);
    liberaPilha(&log);
    return 0;
}
