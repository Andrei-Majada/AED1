#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct Pilha{
    int dados[MAX];
    int topo;
}pilha;

void reset(pilha *pi);

int empty(pilha *pi);

int full(pilha *pi);

void push(pilha *pi, int num);

void pop(pilha *pi);

void topo(pilha *pi);

int main()
{
    pilha *pi = (pilha *)malloc(sizeof(pilha));   

    reset(pi);

    int menu, x;

    for(;;){
        printf("\n1.push\n2.pop\n3.ver topo\n4.sair\nescolha:\n");
        scanf("%d", &menu);
        switch(menu)
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
            topo(pi);
            break;

        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
    system("pause");
}

void reset(pilha *pi)
{   
    pi->topo = -1;

}

int empty(pilha *pi)
{
    if(pi->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int full(pilha *pi)
{
    if(pi->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

void push(pilha *pi, int num)
{
    if(full(pi) == 1){
        printf("pilha esta cheia!\n");
    }else{
        pi->topo++;
        pi->dados[pi->topo] = num;
    }
}

void pop(pilha *pi)
{
    int aux;
    if(empty(pi) == 1){
        printf("pilha vazia!\n");
    }else{
        aux = pi->dados[pi->topo];
        pi->topo--;
        printf("\n%d removido da pilha!\n", aux);
    }
}

void topo(pilha *pi)
{
    if(empty(pi)==1){
        printf("pilha vazia!\n");
    }else{
        printf("%d esta no topo!\n", pi->dados[pi->topo]);
    }
}