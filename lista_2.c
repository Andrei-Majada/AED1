/*Andrei Schneider Majada*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int dia, mes, ano;
} Data;

typedef struct end{
	char nome[100];
	long int telefone;
	Data consulta;
	int idade,hr,min;
	struct end *prox;
} info;

info *cria_lista(void);
void insereinicio(info *pt);
void apaga(info *pt);
void busca(info *pt);
void imprime(info *pt);
void editar(info *pt);
void arquivo(info *pt);
int menu(void);
int sizelist;

int main(){
	int escolha;
	
	info *p;
	
	p = cria_lista();
	
	for(;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
				insereinicio(p);
			break;
			
			case 2:
				apaga(p);
			break;
			
			case 3:
				editar(p);		
			break;
			
			case 4:
				busca(p);
			break;
			
			case 5:
				imprime(p);
			break;
			
			case 6:
				arquivo(p);
			break;
			
			case 7:
				exit(0);
			break;
		
			default:
				printf("\nOpcao invalida!\n");
		}
	}
	return 0;
}

int menu(){
 	int opcao=0;
 	do{
 		
		printf("\n**************************");
		printf("\n1.Cadastrar uma consulta\n");
		printf("2.Remover uma consulta\n");
		printf("3.Editar uma consulta\n");
		printf("4.Pesquisar consulta por nome do paciente\n");
		printf("5.Lista de consultas do dia\n");
		printf("6.Gerar documento\n");
		printf("7.Sair\n");
		printf("**************************");
			
		printf("\n\nO que deseja?\n");
		scanf("%d", &opcao);
		
		if(opcao<=0 || opcao > 7){
 			printf("\nOpcao invalida!\n");
		}
 	}while (opcao <= 0 || opcao > 7);
	return opcao;
}

info *cria_lista(void){
	info *inicio;
	
	inicio = malloc(sizeof(info));
	
	inicio->prox = NULL;
	
	return inicio;
}

void insereinicio(info *pt){
	
	info *nodo;
	
	nodo = malloc(sizeof(info));
	
	if(nodo==NULL){
		printf("memoria cheia, impossivel alocar!");
		exit(0);
	}
	
	sizelist += 1;
	
	printf("\n-- consulta %d:\n", sizelist);
	
	getchar();
	printf("Nome:\n");
	fgets(nodo->nome,100,stdin);
	printf("Idade:\n");
	scanf("%d", &nodo->idade);
	printf("Telefone para contato(Paciente ou Responsavel):\n");
	scanf("%ld", &nodo->telefone);
	printf("Data da consulta(dd,mm,aaaa)(utilize o espaco entre os valores):\n");
	scanf("%d%d%d", &nodo->consulta.dia,&nodo->consulta.mes, &nodo->consulta.ano);
	printf("Horario(hh,mm)(utilize o espaco entre os valores):\n");
	scanf("%d%d", &nodo->hr,&nodo->min);
	
	nodo->prox = pt->prox;
	pt->prox = nodo;
}

void apaga(info *pt){
	char pos[100];
	
	getchar();
	printf("qual o nome do que deseja apagar?\t");
	fgets(pos,100,stdin);
	
	info *p, *q;
	
	p = pt;
	
	q = pt->prox;
	
	while((q != NULL) && (strcmp(q->nome,pos)!=0)){
		p = q;
		q = q->prox;
	}
	
	if(q != NULL){
		p->prox = q->prox;
		free(q);
	}
}

void imprime(info *pt){
	int flag=0;
	int dia,mes,ano;
	getchar();
	printf("informe a data(dd,mm,aaaa)(utilize o espaco entre os valores):\n");
	scanf("%d%d%d", &dia, &mes, &ano);
	
	int i=1;
		
	info *p;
	
	p = pt;
	
	while(p != NULL){
		if(p->consulta.dia==dia && p->consulta.mes==mes && p->consulta.ano==ano){
		printf("\n\n");
		printf("Nome:...............%s", p->nome);
		printf("Idade:..............%d\n", p->idade);
		printf("Telefone:...........%ld\n", p->telefone);
		printf("Data da consulta:...%d/%d/%d\n", p->consulta.dia, p->consulta.mes, p->consulta.ano);
		printf("Horario:............%d:%d", p->hr,p->min);
		i++;
		flag=1;
		}
	p = p->prox;
	}
	
	printf("\n");
	
	if(flag==0){
		printf("Nao existem consultas neste dia!\n");
	}
}


void busca(info *pt){
	
	char nome[100];
	
	getchar();
	printf("informe o nome do paciente:\n");
	fgets(nome,100,stdin);
	
	info *p;
	
	p = pt;
	
	while(p != NULL){
		if(strcmp(p->nome,nome)==0){
			printf("\n");
			printf("Nome:...............%s", p->nome);
			printf("Idade:..............%d\n", p->idade);
			printf("Telefone:...........%ld\n", p->telefone);
			printf("Data da consulta:...%d/%d/%d\n", p->consulta.dia, p->consulta.mes, p->consulta.ano);
			printf("Horario:............%d:%d\n", p->hr,p->min);
		}
		p = p->prox;
	}
	
}
void editar(info *pt){
	char nome[100];
	
	getchar();
	printf("informe o nome do paciente:\n");
	fgets(nome,100,stdin);
	
	info *p;
	
	p = pt;
	
	while(p != NULL){
		if(strcmp(p->nome,nome)==0){
			printf("Telefone para contato:\n");
			scanf("%ld", &p->telefone);
		
			printf("Data da consulta(dd,mm,aaaa)(utilize o espaco entre os valores):\n");
			scanf("%d%d%d", &p->consulta.dia,&p->consulta.mes, &p->consulta.ano);
		
			printf("Horario(hh,mm)(utilize o espaco entre os valores):\n");	
			scanf("%d%d", &p->hr,&p->min);
		}
		p = p->prox;
	}
		
}

void arquivo(info *pt)
{
	FILE *pf;
	int i=0;
	info *p;

	pf = fopen("ficha_pacientes_do_dr_estranho.txt","w");
	
	if(pf == NULL){
		printf("arquivo nao pode ser aberto!\n");
	}
	  
	fprintf(pf,"*******************************Consultorio Dr. Stephen Vincent Strange*******************************\n\n");
	fprintf(pf,"\t    **************************Relatorio de pacientes:**************************\n\n");
	
	for(p = pt->prox; p != NULL; p = p->prox){
		i++;
		fprintf(pf,"\n\n-- paciente %d:\n", i);
		fprintf(pf,"Nome:...............%s", p->nome);
		fprintf(pf,"Idade:..............%d\n", p->idade);
		fprintf(pf,"Telefone:...........%ld\n", p->telefone);
		fprintf(pf,"Data da consulta:...%d/%d/%d\n", p->consulta.dia, p->consulta.mes, p->consulta.ano);
		fprintf(pf,"Horario:............%d:%d", p->hr,p->min);
		fprintf(pf,"\n\n");
	}
	fclose(pf);
}