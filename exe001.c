#include<stdio.h>
#include<stdlib.h>

void preenche(int tam,int vet[]);

int main(){

    int i,n,*pv;

    printf("tamanho?\n");
    scanf("%d", &n);

    pv = malloc(n*sizeof(int));

    preenche(n,pv);

    for(i=0;i<n;i++){
        printf("\n%d",pv[i]);
    }

    free(pv);
    return 0;
}

void preenche(int tam,int *ptr){
    int i;

    for(i=0;i<tam;i++){
        printf("\nvalor[%d]=",i);
        scanf("%d", &ptr[i]);
    }
}