#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _BANDA{
    char nomebanda[50];
    char tipo[50];
    int integrantes;
    int rank;
    struct _BANDA *p_banda;
}BANDA;


int main(){

BANDA *pt_head = (BANDA *)malloc(sizeof(BANDA));
    
    if(!pt_head){
        printf("ERRO!");
        exit(1);
    }

BANDA *pt_aux = (BANDA *)malloc(sizeof(BANDA));
    if(!pt_head){
        printf("ERRO!");
        exit(1);
    }     

pt_aux = pt_head;

int qnt_bandas;
puts("Digite a quantidade de bandas que você quer inserir: ");
scanf("%d", &qnt_bandas);


for (int i = 0; i < qnt_bandas; i++){
    printf("Digite o nome de uma banda:\n");
    scanf("%s", pt_aux->nomebanda);
    printf("Digite o tipo de musica:\n");
    scanf("%s", pt_aux->tipo);
    printf("Digite o número de integrantes: \n");
    scanf("%d", &pt_aux->integrantes);
    printf("Digite o rank da banda: \n");
    scanf("%d", &pt_aux->rank);

    pt_aux->p_banda = (BANDA *)malloc(sizeof(BANDA));
    pt_aux = pt_aux->p_banda;
   
}
    printf("\n");

    pt_aux = pt_head;

    while (pt_aux->p_banda != NULL){
        printf("nome: %s \n", pt_aux->nomebanda);
        printf("tipo: %s \n", pt_aux->tipo);
        printf("n integrantes: %d\n", pt_aux->integrantes);
        printf("rank: %d\n\n", pt_aux->rank);
        pt_aux = pt_aux->p_banda;
    }

    char estilo[5];

    printf("Digite o tipo de musica a ser buscado:\n");
    scanf("%s", estilo);
   

    pt_aux = pt_head;

    while (pt_aux->p_banda != NULL){
        if (strcmp(estilo, pt_aux->tipo) == 0){
            printf("Banda com esse tipo musica: %s\n", pt_aux->nomebanda);
            pt_aux = pt_aux->p_banda;
            continue;
        } else {
            pt_aux = pt_aux->p_banda;
        }
    }


    free(pt_aux);
    free(pt_head);



    return 0;
}
