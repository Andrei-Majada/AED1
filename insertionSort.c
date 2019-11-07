#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[], int n);

int swaps=0;

int main(){
    int *v, tam, i;

    printf("tam: ");
    scanf("%d", &tam);
    
    v = malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        v[i]=rand()%100;
    }

    printf("\nvetor desordenado!\n");
    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    insertionSort(v,tam);

    printf("\nnumero de trocas: %d\n", swaps);


    printf("\nvetor ordenado!\n");
    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    system("pause");
    return 0;
}

void insertionSort(int v[], int n){
    int i, j, troca;
    for (i = 1; i < n; i++){
        troca = v[i];
        for (j=i;(j > 0) && (troca < v[j-1]);j--){
            v[j] = v[j-1];
        }
        v[j] = troca;
    }  
    //printf("\nnumero de trocas: %d\n", swaps);
}

























/*int i, j, troca, swaps=0;
    for(i=1; i<n; i++){
        troca = v[i];
        for(j=i; (j > 0) && (troca < v[j-1]);j--){
            v[j] = v[j-1];
            swaps++;
        }
        v[j] = troca;
    }*/