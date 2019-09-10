/*Andrei Schneider Majada*/
#include<stdio.h>
#include<stdlib.h>

int cria(int n){
    int *vet;

    vet = malloc(n*sizeof(int));
    return *vet;
}

void imprime(int n, int *vet){
    int i;
    for(i=0;i<n;i++)
        printf("vet[%d]=%d\n",i,vet[i]);
    
}

void liberamem(int *vet){
    free(vet);
}

int main(){
    int n,i,*pv;

    printf("tamanho do vetor:  ");
    scanf("%d", &n);

    pv = (int *)cria(n);

    for(i=0;i<n;i++){
        pv[i]= rand()%88;
    }

    imprime(n,pv);

    liberamem(pv);

    return 0;
}