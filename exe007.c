#include<stdio.h>
#include<stdlib.h>

int* valores_entre(int *v, int n, int min, int max, int *qtd)
{

    int i, *pv;
    for(i=0;i<n;i++){
        if((v[i]<max) && (v[i]>min)){
            *qtd = *qtd + 1;
        }
    }
    
    if(qtd > 0){
        pv = malloc((*qtd)*sizeof(int));
    }

    if(pv==NULL){
        printf("impossivel alocar memoria.\n");
    }

    for(i=0;i<(*qtd);i++){
        if((v[i]<max) && (v[i]>min)){
            pv[i]=v[i];
        }
    }
    
    for(i=0;i<(*qtd);i++){
        printf("vet[%d]=%d\n", i, pv[i]);
    }

    return pv;
}

int main()
{

    int tam,*vet,i,min,max,qtd=0,*vt;

    printf("tamanho do vetor:\t");
    scanf("%d", &tam);

    vet = malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        vet[i]=rand()%100;
    }

    printf("informe o valor minimo:\t");
    scanf("%d", &min);

    printf("informe o valor maximo:\t");
    scanf("%d", &max);

    vt = (int *)valores_entre(vet, tam, min, max, &qtd);

    printf("acertos(main) = %d\n", qtd);

    free(vt);

    free(vet);

    return 0;
}