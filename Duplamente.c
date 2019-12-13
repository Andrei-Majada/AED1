#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tabela{
    int num;
    struct tabela *prox;
    struct tabela *ante;
} agenda;

int menu();

void *cria();

void insereinicio(agenda *pt);

void apaga(agenda *pt);

void busca(agenda *pt);

void lista(agenda *pt);

int tamanho(agenda *pt);

int main(){
    agenda *ptr;

    ptr = cria();

    for(;;){

        switch(menu()){
            
            case 1:
                insereinicio(ptr);
            break;

            case 2:
                apaga(ptr);
            break;

            case 3: 
                busca(ptr);
            break;

            case 4:
                lista(ptr);
            break;

            case 5:
                tamanho(ptr);
            break;

            case 6:
                exit(0);
            break;    

            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}

int menu(){

    int escolha;
    printf("\n\n****menu:****\n");
    printf("1.insereinicio:\n");
    printf("2.apaga:\n");
    printf("3.busca:\n");
    printf("4.lista:\n");
    printf("5.tamanho:\n");
    printf("6.sair:\n\n");
    printf("qual deseja?\n");

    scanf("%d", &escolha);
    return escolha;
}

void *cria(void){

    agenda *head;

    head = malloc(sizeof(agenda));

    head->prox = NULL;

    return head;
}

void insereinicio(agenda *pt){
     agenda *novo;

     novo = malloc(sizeof(agenda));

    if(novo == NULL){
        printf("Nao foi possivel alocar!\n");
    }
    printf("numero: ");
    scanf("%ld",&novo->num);
    novo->ante = pt;
    novo->prox = pt->prox;
    pt->prox = novo;
}

void inserefim(agenda *pt){
     agenda *novo, *p = pt;

     novo = malloc(sizeof(agenda));

    if (pt->prox == NULL){
        if(novo == NULL){
        printf("Nao foi possivel alocar!\n");
        }
        printf("numero: ");
        scanf("%ld",&novo->num);
        novo->ante = pt;
        novo->prox = NULL;
    }else{

    if(novo == NULL){
        printf("Nao foi possivel alocar!\n");
    }
    printf("numero: ");
    scanf("%ld",&novo->num);
    while (p->prox != NULL){
        p = p->prox;
    }
    novo->prox = NULL;
    p->prox = novo;
    novo->ante = p;
    }
}

void apaga(agenda *pt){

    int i;
    int x;
    agenda *p,*q;

    printf("informe o numero que deseja apagar:\n");
    scanf("%d", &x);

    p = pt;
    q = pt->prox;

    while((q != NULL) && (q->num!=x)){
        p = q;
        q = q->prox;
    }

    if(q != NULL){
        p->prox = q->prox;
        free(q);
    }
}

void busca(agenda *pt){

    int i, flag=0;
    int buscar;
    agenda *p;

    printf("informe o numero que deseja buscar:\n");
    scanf("%d", &buscar);

    p = pt;

    while(p != NULL){
        if(p->num==busca){
            printf("\nnumero:.......%s", p->num);
            flag = 1;
        }
        p = p->prox;
    }

    if(flag == 0){
        printf("\nnumero nao encontrado!\n");
    }
}

void lista(agenda *pt){

    agenda *p;

    for(p = pt->prox; p != NULL; p = p->prox){
        printf("\nnumero:.......%s", p->num);
    }
}

int tamanho(agenda *pt)
{
    if (pt == NULL){
        return 0;
    }
    int count=0;
    agenda *p;
    while (p != NULL){
        count++;
        p = p->prox;
    }
    return count;
}