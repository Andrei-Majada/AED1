/*Andrei Schneider Majada*/
#include <stdio.h>
#include <stdlib.h>

void liberamem(int *vet, int *vet2, int *vet3);

int uniao(int *pv1, int v1, int *pv2, int v2);

void imprime(int n, int *vet);

int main(){

    int *pv1, *pv2, v1, v2, *vet;

    printf("informe tamanho vetor v1:\t");
    scanf("%d", &v1);

    printf("informe tamanho vetor v2:\t");
    scanf("%d", &v2);

    vet = (int *)uniao(pv1,v1,pv2,v2);

    imprime((v1+v2),vet);

    liberamem(vet,pv1,pv2);

    return 0;
}

int uniao(int *pv1, int v1, int *pv2, int v2){
    int *pv3, i, j=0;

    pv1 = malloc(v1*sizeof(int));

    pv2 = malloc(v2*sizeof(int)); 

    for(i=0;i<v1;i++){
        scanf("%d", &pv1[i]);
    }

    for(i=0;i<v2;i++){
        scanf("%d", &pv2[i]);
    }

    pv3 = malloc((v1+v2)*sizeof(int));

    for(i=0;i<(v1+v2);i++){
        if(i<v1){
            pv3[i]=pv1[i];
        }
        else{
            pv3[i]=pv2[j];
            j++;
        }
    }
    return pv3;
}

void liberamem(int *vet, int *vet2, int *vet3){
    free(vet);
    free(vet2);
    free(vet3);
}

void imprime(int n, int *vet){
    int i;
    for(i=0;i<n;i++)
        printf("vet[%d]=%d\n",i,vet[i]);
    
}