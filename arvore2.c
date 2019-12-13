#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq, *dir;
}no;

no *insere(no *pt, int valor)
{
    if (pt == NULL){
        pt = malloc(sizeof(no));
        pt->valor = valor;
        pt->esq = NULL;
        pt->dir = NULL;
    }else if (valor < pt->valor){
        pt->esq = insere(pt->esq,valor);
    }else if (valor > pt->valor){
        pt->dir = insere(pt->dir, valor);
    }   
    return pt;
}

no* retira(no *pt, int valor)
{
    if (pt == NULL){
        return NULL;
    }else if (valor < pt->valor){
        pt->esq = retira(pt->esq, valor);
    }else if (valor > pt->valor){
        pt->dir = retira(pt->dir,valor);
    }else{
        if ((pt->esq == NULL) && (pt->dir == NULL)){
            free(pt);
            pt = NULL;
        }else if (pt->esq == NULL){
            no *aux = pt;
            pt = pt->dir;
            free(aux);
        }else if (pt->dir == NULL){
            no *aux = pt;
            pt = pt->esq;
            free(aux);
        }else{
            //se tiver dois filhos
        }
    }
    return pt;
}

void PreOrdem(no *pt)
{
    if (pt != NULL){
        printf("%d\t", pt->valor);
        PreOrdem(pt->esq);
        PreOrdem(pt->dir);
    }
}

void EmOrdem(no *pt)
{
    if (pt != NULL){
        EmOrdem(pt->esq);
        printf("%d\t", pt->valor);
        EmOrdem(pt->dir);
    }
}

void PosOrdem(no *pt)
{
    if (pt != NULL){
        PosOrdem(pt->esq);
        PosOrdem(pt->dir);
        printf("%d\t", pt->valor);
    }
}

no* buscar(no *pt, int valor)
{
    if (pt == NULL){
        return NULL;
    }else if (pt->valor == valor){
        printf("\nvalor %d encontrado!\n", pt->valor);
    }else if (valor < pt->valor){
        pt->esq = buscar(pt->esq,valor);
    }else if (valor > pt->valor){
        pt->dir = buscar(pt->dir,valor);
    }
}

int main(){
    no *pt = NULL;

    pt = insere(pt,10);
    pt = insere(pt,14);
    pt = insere(pt,7);
    pt = insere(pt,8);
    pt = insere(pt,13);
    pt = insere(pt,25);
    pt = insere(pt,1);
    pt = insere(pt,22);

    PreOrdem(pt);
    EmOrdem(pt);
    PosOrdem(pt);

    pt = retira(pt, 7);

    EmOrdem(pt);

    pt = retira(pt, 22);

    EmOrdem(pt);

    pt = buscar(pt,13);

    return 0;
}