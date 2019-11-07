#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int n);

int main(){
    int *v, tam, i;

    printf("tam: ");
    scanf("%d", &tam);

    v = malloc(tam*sizeof(int));

    printf("vetor desordenado!\n");
    for(i=0;i<tam;i++){
        v[i]=rand()%100;
    }

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    selectionSort(v,tam);

    printf("\nvetor ordenado!\n");
    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    return 0;
}

void selectionSort(int *v, int n){
    int i, j, menor, aux;
    for (i=0;i<n-1;i++){
        menor = i;
        for (j=i+1;j<n;j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    } 
}
/*int menor, troca, swaps=0, i, j;

    for(i=0;i<n-1;i++){
        menor=i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
            swaps++;
        }
    }*/