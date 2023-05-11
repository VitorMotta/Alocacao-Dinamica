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

    LISTA *pt_aux = pt_head;

    for (int i = 0; i < 5; i++) {  // Lendo valores
        printf("Digite um valor\n");
        scanf("%d", &pt_aux->valor);

        pt_aux->prox = (LISTA *)malloc(sizeof(LISTA));
        pt_aux = pt_aux->prox;
    }

    pt_aux->prox = NULL;

    printf("\n");

    //Remover dados

    LISTA *pt_p2 = NULL;

    pt_aux = pt_head;

    while (pt_aux != NULL){
        if (pt_aux->valor == 1){
            if (pt_aux == pt_head){
                pt_head = pt_aux->prox;
                free(pt_aux);
                pt_aux = pt_head;
            } else {
                pt_p2->prox = pt_aux->prox;
                free(pt_aux);
                pt_aux = pt_p2->prox;
            }
        } else {
            pt_p2 = pt_aux;
            pt_aux = pt_aux->prox;
        }
    }

    printf("\n");

    pt_aux = pt_head;

    
    while (pt_aux->prox != NULL) {  // Imprimindo valores ordenados
        printf("valor: %d \n", pt_aux->valor);
        pt_aux = pt_aux->prox;
    }


    if (pt_head->prox == NULL) {
        puts("Vazio!");
        exit(1);
    } else {
        free(pt_head);
    }

    if (pt_aux->prox == NULL) {
        puts("Vazio!");
        exit(1);
    } else {
        free(pt_aux);
    }

    
    

    return 0;
}
