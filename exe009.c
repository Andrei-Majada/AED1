/*Andrei Schneider Majada*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void ler_aposta(int *aposta, int n)
{
    int aux,i;

    printf("informe os valores que deseja apostar:\n");
    printf("\n*somente valores entre 0 e 100*\n");

    for ( i = 0; i < n; i++){
        do{
            printf("n[%d]= ", i);
            scanf("%d", &aux); 
            if (aux<0 || aux>100){
                printf("valor incorreto!\n");
            }
        } while (aux<0 || aux>100);
        
        aposta[i]=aux;
    }
}

void sorteia_valores(int*sorteio, int n)
{
    int i;

    for ( i = 0; i < n; i++){
        sorteio[i]=rand()%100;
    }

}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
    int i,j,*acerto,k=0;
    
    acerto = malloc(sizeof(int));

    for ( i = 0; i < na; i++){
        for ( j = 0; j < ns; j++){
            if (aposta[i]==sorteio[j]){
                *qtdacertos = *qtdacertos + 1;
                acerto = (int *)realloc(acerto,sizeof(int));
                acerto[k]=aposta[i];
                k++;
            }
        }  
    }
    return acerto;
}

void imprime(int n, int *vet){
    int i;
        
    for(i=0;i<n;i++)
        printf("vet[%d]=%d\n",i,vet[i]);
    
}

void liberaMem(int *vet){
    free(vet);
}

int main(){
    int *pa, *ps, qtdAcerto=0, i, na, ns=20, *vetAcerto;

    do{
    printf("quantidade de numeros que deseja apostar:(1 a 20)\t");
    scanf("%d", &na);

    if (na<1 || na>20){
        printf("valor incorreto!\n");
    }
    }while(na<1 || na>20);

    pa = malloc(na*sizeof(int));
    
    ler_aposta(pa, na);

    ps = malloc(ns*sizeof(int));

    sorteia_valores(ps, ns);

    printf("\n****valores sorteados****\n");

    imprime(ns, ps);

    vetAcerto = (int *)compara_aposta(pa, ps, &qtdAcerto, na, ns);

    printf("\n****valores que acertou****\n");

    imprime(qtdAcerto, vetAcerto);

    liberaMem(ps);

    liberaMem(pa);

    liberaMem(vetAcerto);

    return 0;
}