#include <stdio.h>
#include <stdlib.h>

typedef struct _LISTA {
    int valor;
    struct _LISTA *prox;
} LISTA;

int main() {
    LISTA *pt_head = (LISTA *)malloc(sizeof(LISTA));
    if (!pt_head) {
        printf("ERRO!");
        exit(1);
    }

    LISTA *pt_aux = (LISTA *)malloc(sizeof(LISTA));
    if (!pt_aux) {
        printf("ERRO!");
        exit(1);
    }

    pt_aux = pt_head;

    for (int i = 0; i < 5; i++) {  // Lendo valores
        printf("Digite um valor\n");
        scanf("%d", &pt_aux->valor);

        pt_aux->prox = (LISTA *)malloc(sizeof(LISTA));
        pt_aux = pt_aux->prox;
    }

    pt_aux->prox = NULL;

    printf("\n");

    // Bubble Sort
    int tamanho = 5;
    LISTA *pt_atual = NULL;
    LISTA *pt_proximo = NULL;

    for (int i = 0; i < tamanho - 1; i++) {
        pt_atual = pt_head;

        for (int j = 0; j < tamanho - 1 - i ; j++) {
            pt_proximo = pt_atual->prox;

            if (pt_atual->valor > pt_proximo->valor) {
                int tmp = pt_atual->valor;
                pt_atual->valor = pt_proximo->valor;
                pt_proximo->valor = tmp;
            }

            pt_atual = pt_atual->prox;
        }
    }

    printf("\n");

    pt_aux = pt_head;

    while (pt_aux->prox != NULL) {  // Imprimindo valores ordenados
        printf("valor: %d \n", pt_aux->valor);
        pt_aux = pt_aux->prox;
    }

    free(pt_aux);
    free(pt_head);

    return 0;
}
