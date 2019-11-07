#include <stdio.h>
#include <stdlib.h>

void quickSort(int *v, int left, int right);

int swaps=0;

int main(){
    int *v, tam, i, ini=0;

    printf("tam: ");
    scanf("%d", &tam);

    v = malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        v[i]=rand()%100;
    }

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    quickSort(v,ini,tam-1);

    printf("\nnumero de trocas: %d\n", swaps);

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    return 0;
}

void quick_sort(int *v, int left, int right) {
    int i, j, pivo, aux;
    i=left;
    j=right;
    pivo = v[(left + right)/2];
    while (i <= j){
        while (v[i] < pivo && i < right){
            i++;
        }
        while (v[j] > pivo && j > left){
            j--;
        }
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if ( i < right){
        quick_sort(v,i,right);
    }
    if( j > left){
        quick_sort(v,left,j);
    }
}












/*int i, j, pivo, aux;
     
    i = left;
    j = right;
    pivo = v[(left + right) / 2];
     
    while(i <= j) {
        while(v[i] < pivo && i < right) {
            i++;
        }
        while(v[j] > pivo && j > left) {
            j--;
        }
        if(i <= j) {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
            swaps++;
        }
    }
     
    if(j > left) {
        quick_sort(v, left, j);
    }
    if(i < right) {
        quick_sort(v, i, right);
    }*/