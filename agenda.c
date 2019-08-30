/*Andrei Schneider Majada*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tabela{
    char nome[50];
    long int telefone;
    struct tabela *prox;
} agenda;

int menu();

void *cria();

void insereinicio(agenda *pt);

void apaga(agenda *pt);

void busca(agenda *pt);

void lista(agenda *pt);

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
    printf("5.sair:\n\n");
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

    printf("nome: ");
    getchar();
    fgets(novo->nome,50,stdin);

    printf("telefone: ");
    scanf("%ld",&novo->telefone);

    novo->prox = pt->prox;

    pt->prox = novo;
}

void apaga(agenda *pt){

    int i;
    char vaza[50];
    agenda *p,*q;

    printf("informe o nome que deseja apagar:\n");
    getchar();
    fgets(vaza,50,stdin);

    p = pt;
    q = pt->prox;

    while((q != NULL) && (strcmp(q->nome,vaza)!=0)){
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
    char buscado[50];
    agenda *p;

    printf("informe o nome que deseja buscar:\n");
    getchar();
    fgets(buscado,50,stdin);

    p = pt;

    while(p != NULL){
        if(strcmp(p->nome,buscado)==0){
            printf("\nnome:.......%s", p->nome);
            printf("telefone:..%d", p->telefone);
            flag = 1;
        }
        p = p->prox;
    }

    if(flag == 0){
        printf("\nnome nao encontrado!\n");
    }
}

void lista(agenda *pt){

    agenda *p;

    for(p = pt->prox; p != NULL; p = p->prox){
        printf("\nnome:.......%s", p->nome);
        printf("telefone:..%d\n", p->telefone);
    }
}