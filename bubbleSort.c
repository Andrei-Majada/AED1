#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n);

int main(){
    int *v, tam, i;

    printf("tam: ");
    scanf("%d", &tam);

    v = malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        v[i]=rand()%100;
    }

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    bubbleSort(v,tam);

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    return 0;
}

void bubbleSort(int *v, int n){
    int i,continua,aux, swaps = 0;
    do{
        continua = 0;
        for (i = 0; i < n-1; i++)
        {
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = 1;
                swaps++;
            }
        }
        n--;
    } while (continua != 0);
    
    printf("\nnumero de trocas: %d\n", swaps);
}














/*
int i, j, aux, swaps=0;
    
    for (i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(v[j] < v[i]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                swaps++;
            }
        }
    }
*/