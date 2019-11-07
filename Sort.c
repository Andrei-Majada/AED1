#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[], int n);

void selectionSort(int v[], int n);

void bubbleSort(int v[], int n);

void quick_sort(int v[], int left, int right);

int swaps=0;

int main(){
    int v[9]={2, 3, 4, 2, 3, 6, 8, 4, 5}, tam=9, i, op;

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }
    
    printf("\n1.insertion\n");
    printf("2.selection\n");
    printf("3.bubble\n");
    printf("4.quicksort\n");
    printf("qual maneira ordenar? ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        insertionSort(v,tam);
        break;

    case 2:
        selectionSort(v,tam);
        break;

    case 3:
        bubbleSort(v,tam);
        break;

    case 4:
        quick_sort(v,0,tam-1);
        break;
    
    default:
        break;
    }

    printf("\nnumero de trocas: %d\n", swaps);

    for(i=0;i<tam;i++){
        printf("vet[%d]=%d\n", i, v[i]);
    }

    system("pause");
    return 0;
}

void insertionSort(int v[], int n){
    int i, j, troca;
    for(i=1; i<n; i++){
        troca = v[i];
        for(j=i; (j > 0) && (troca < v[j-1]);j--){
            v[j] = v[j-1];
            swaps++;
        }
        v[j] = troca;
    }
}

void selectionSort(int v[], int n){
    int menor, troca, i, j;

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
    }   
}

void bubbleSort(int v[], int n){
    int i,continua,aux;
    do
    {
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
}

void quick_sort(int v[], int left, int right) {
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
            swaps++;
        }
    }

    if ( i < right){
        quick_sort(v,i,right);
    }
    if( j > left){
        quick_sort(v,left,j);
    }
}