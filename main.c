/*Integração entre Estruturas
    O cliente entra na fila de prioridade.
    Ao ser atendido, ele pode fazer uma aposta, que é 
        registrada na lista de apostas.
    Cada ação (como registrar ou cancelar aposta) é 
        armazenada na pilha para possível desfazer.*/

// #include <stdio.h>
// #include <stdlib.h>
// #include "filaPrioridade.h"

// int main() {
//     FILA_PRIORIDADE fila;
//     inicializar_fila(&fila);

//     enfileirar(&fila, "João", 45);
//     enfileirar(&fila, "Maria", 68);
//     enfileirar(&fila, "Pedro", 30);
//     enfileirar(&fila, "Ana", 70);
//     enfileirar(&fila, "Carlos", 50);

//     printf("Estado da fila:\\n");
//     mostrar_fila(&fila);

//     printf("\\nAtendendo clientes:\\n");
//     for (int i = 0; i < 3; i++) {
//         Cliente* atendido = desenfileirar(&fila);
//         if (atendido) {
//             printf("-> Atendido: %s (%d anos)\\n", atendido->nome, atendido->idade);
//             free(atendido);
//         } else {
//             printf("-> Nenhum cliente na fila.\\n");
//         }
//     }

//     printf("\\nFila após atendimento:\\n");
//     mostrar_fila(&fila);

//     liberar_fila(&fila);
//     return 0;
// }











