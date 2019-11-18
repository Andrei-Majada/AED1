#include<stdio.h>
#include<stdlib.h>

typedef struct Pilha{
    int info;
    struct Pilha *prox;
}pilha;

void *reset()
{
    pilha *head;
    head = malloc(sizeof(pilha));
    head->prox = NULL;
    return head;
}

void push(pilha *pi, int x)
{
    pilha *novo;
    novo = malloc(sizeof(pilha));
    if(novo==NULL){
        printf("impossivel alocar!");
    }

    novo->info = x;
    novo->prox = pi->prox;
    pi->prox = novo;
}

void pop(pilha *pi)
{
    if (pi->prox == NULL){
        printf("\npilha vazia!\n");
    }else{
        pilha *p;
        p = pi->prox;
        pi->prox = p->prox;
        free(p);
    }
}

void listar(pilha *pi)
{
    if (pi->prox == NULL){
        printf("\npilha vazia!\n");
    }else{
        pilha *p;
        for (p = pi->prox; p != NULL; p = p->prox){
            printf("%d\n", p->info);
        }
    }
}

void lista_topo(pilha *pi)
{
    if (pi->prox == NULL){
        printf("\npilha vazia!\n");
    }else{
        pilha *p;
        p = pi->prox;
        printf("%d esta no topo\n", p->info);
    }
}

int menu()
{
    int op;
    printf("***********");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.LISTAR\n");
    printf("4.LISTAR TOPO\n");
    printf("5.SAIR\n");
    printf("entra opcao:");
    scanf("%d", &op);

    return op;
}

int main()
{
    pilha *pi;

    pi = reset();

    int x;

    for(;;)
    {
        switch (menu())
        {
        case 1:
            printf("entra valor:\t");
            scanf("%d", &x);
            push(pi,x);  
            break;
        case 2:
            pop(pi);  
            break;
        case 3:
            listar(pi);  
            break;
        case 4:
            lista_topo(pi);  
            break;
        case 5:
            exit(0);  
            break;
        
        default:
            break;
        }
    }
    system("pause");
    return 0;
}