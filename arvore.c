#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esq,*dir;
}no;

no* push(no *p, int valor)
{
    if (p == NULL){
        p = malloc(sizeof(no));
        p->valor = valor;
        p->esq = NULL;
        p->dir = NULL;
    }else if (valor < p->valor){
        p->esq =  push(p->esq,valor);
    }else if (valor > p->valor){
        p->dir = push(p->dir,valor);
    }
    return p;
}

no* pop (no *p, int valor)
{
    if (p == NULL){
        return NULL;
    }else if (p->valor > valor){
        p->esq = pop(p->esq, valor);
    }else if (p->valor < valor){
        p->dir = pop(p->dir, valor);
    }else {
            if (p->esq == NULL && p->dir == NULL) {
                free (p);
                p = NULL;
            }
            else if (p->esq == NULL) {
                no* aux = p;
                p = p->dir;
                free (aux);
            }
            else if (p->dir == NULL) {
                no* aux = p;
                p = p->esq;
                free (aux);
            }
            else {
                // SE tiver dois filhos
            }
        }
 return p;
}

void lista_preordem(no *p)
{
    if (p != NULL){
        printf("%d\t", p->valor);
        lista_preordem(p->esq);
        lista_preordem(p->dir);
    }
}

void lista_emordem(no *p)
{
    if (p != NULL){
        lista_emordem(p->esq);
        printf("%d\t", p->valor);
        lista_emordem(p->dir);
    }
}

void lista_posordem(no *p)
{
    if (p != NULL){
        lista_posordem(p->esq);
        lista_posordem(p->dir);
        printf("%d\t", p->valor);
    }
}

no* busca(no *p, int valor)
{
    if (p == NULL){
        return NULL;
    }else if (p->valor == valor){
        printf("valor %d encontrado!\n", p->valor);
        return p;
    }else if (p->valor > valor){
        p->esq = busca(p->esq, valor);
    }else if (p->valor < valor){
        p->dir = busca(p->dir, valor);
    }
}

int main()
{
    no *p = NULL;

    for(;;){
        printf("1.Inserir\n2.Retirar\n3.Pre-ordem\n4.Em-ordem\n5.Pos-ordem\n6.Busca\n7.Sair\nentre opcao:\t");
        int op,x;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("entra valor:\t");
            scanf("%d", &x);
            p = push(p,x);
            break;
        case 2:
            printf("entra valor:\t");
            scanf("%d", &x);
            p = pop(p,x);
            break;
        case 3:
            printf("Pre-Ordem:\t");
            lista_preordem(p);
            printf("\n");    
            break;
        case 4:
            printf("Em-Ordem:\t");
            lista_emordem(p);
            printf("\n");    
            break;
        case 5:
            printf("Pos-Ordem:\t");
            lista_posordem(p);
            printf("\n");    
            break;
        case 6:
            printf("entra valor:\t");
            scanf("%d", &x);
            p = busca(p,x);
            break;
        case 7:
            exit(0);
            system("pause");
            break;
        default:
            break;
        }
    }
    printf("\n");
    system("pause");
    return 0;
}