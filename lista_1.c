#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	int dia, mes, ano;
} Data;

typedef struct lista
{
	char nome[50], endereco[30], dependentes[5][50];
	long int telefone, matricula;
	int numerodep;
	Data nascimento;
	double salario;
	struct lista *prox;
}Lista;

Lista *cria();

int menu();

void insereinicio(Lista *head);

void imprime(Lista *head);

void remova(long int x,Lista *head);

void busca(long int x,Lista *head);

void aniversario(int dia, int mes, Lista *head);

void reajuste(double reajuste, Lista *head);

void arquivo(Lista *head);

void dependentes(long int x, Lista *head);

int i=0, x=0, j=0, n=0;

int main()
{
	int num, x, y;
	
	long int indice;
	
	double reaj_salario;
	
	Lista *ptr;
 	
	ptr = cria();
	
	for(;;){
		switch (menu()){
			case 1:
				printf("quantos deseja cadastrar?\n");
				scanf("%d", &num);
				for(i=0; i<num;i++){
				insereinicio(ptr);
				}
			break;
			
			case 2:
				printf("numero de matricula para busca:\n");
				scanf("%ld", &indice);
				busca(indice,ptr);		
			break;
			
			case 3:
				imprime(ptr);
			break;
			
			case 4:
				printf("numero de matricula a apagar:\n");
				scanf("%ld", &indice); 
				remova(indice,ptr);
			break;
			
			case 5:
				printf("dia e mes:\n");
				scanf("%d%d", &x, &y); 
				aniversario(x, y, ptr);
			break;
			
			case 6:
				printf("Reajuste salarial\n");
				printf("informe o valor de reajuste:\n(OBS: isto se aplicara a todos os funcionarios.)\n");
				scanf("%lf", &reaj_salario);
				reajuste(reaj_salario,ptr);
			break;
			
			case 7:
				arquivo(ptr);
			break;
			
			case 8:
				printf("numero de busca dos dependentes:\n");
				scanf("%ld", &indice);
				dependentes(indice,ptr);
			break;
			
			case 9:
				exit(0);
			break;
			
			default:
				printf("\nOpcao invalida!\n");
		}
	}
	
	return 0;
}

int menu(){
 	int opcao;
 	
	printf("\n**************************");
	printf("\n1.Inserir na lista\n");
	printf("2.Buscar na lista\n");
	printf("3.Imprimir lista\n");
	printf("4.Remover da lista\n");
	printf("5.Aniversarios\n");
	printf("6.Reajuste salarial\n");
	printf("7.Gerar Documento\n");
	printf("8.Dependentes\n");
	printf("9.Sair\n");
	printf("**************************");
		
	printf("\n\nO que deseja?\n");
	scanf("%d", &opcao);
 
	 return opcao;
}

Lista *cria()
{
	Lista *inicio;
	
	inicio = malloc(sizeof(Lista));
	
	inicio->prox = NULL;
	
	return inicio;
}

void insereinicio(Lista *head)
{
	Lista *nova;
	
	nova = malloc(sizeof(Lista));
	
	x += 1;
	
	printf("\nfuncionario numero %d:", x);
	
	getchar();
	printf("\nNome:\n");
	fgets(nova->nome,50,stdin);
	
	printf("Matricula:\n");
	scanf("%ld", &nova->matricula);
	
	getchar();	
	printf("Endereco:\n");
	fgets(nova->endereco,30,stdin);
		
	printf("Telefone:\n");
	scanf("%ld", &nova->telefone);
		
	printf("Data de nascimento:\n");
	scanf("%d%d%d", &nova->nascimento.dia, &nova->nascimento.mes, &nova->nascimento.ano);
		
	printf("Salario:\n");
	scanf("%lf", &nova->salario);
	
	printf("Numero de dependentes:\n");
	scanf("%d", &n);
	
	if(n>0){
		nova->numerodep = n;
		getchar();
		do{
			printf("informe dependente %d:\n", j+1);
			fgets(nova->dependentes[j],50,stdin);
			j++;
		}while(j<n);
	}
	
	nova->prox = head->prox;
	
	head->prox = nova;
}

void imprime(Lista *head)
{
	Lista *p;
	
	for(p = head->prox; p != NULL; p = p->prox)
	{
		printf("\nNome:\n");
		printf("%s", p->nome);
			
		printf("Matricula:\n");
		printf("%.0ld\n", p->matricula);
			
		printf("Telefone:\n");
		printf("%.0ld\n", p->telefone);
	}
}

void remova(long int x,Lista *head)
{
	Lista *p, *q;
	
	p = head;
	
	q = head->prox;
	
	while((q != NULL) && (q->matricula != x)){
	p = q;
	
	q = q->prox;
	}
	
	if(q != NULL){
		p->prox = q->prox;
		free(q);
	}
}

void busca(long int x,Lista *head)
{
	Lista *p;
	
	p = head->prox;
	
	while((p->prox != NULL) && (p->matricula != x)){
		p = p->prox;
	}
		printf("\nNome:\n");
		printf("%s", p->nome);
		
		printf("Matricula:\n");
		printf("%.0ld", p->matricula);
				
		printf("Endereco:\n");
		printf("%s",p->endereco);
			
		printf("Telefone:\n");
		printf("%.0ld\n", p->telefone);
			
		printf("Data de nascimento:\n");
		printf("%d/%d/%d\n", p->nascimento.dia, p->nascimento.mes, p->nascimento.ano );
			
		printf("Salario:\n");
		printf("%.2lf\n", p->salario);
		
		for(j=0;j<p->numerodep;j++){
			printf("Dependente %d:\n", j+1);
			printf("%s", p->dependentes[j]);
		}
}

void aniversario(int dia, int mes, Lista *head)
{
	Lista *p;
	
	p = head->prox;
	
	while((p->prox != NULL) && (p->nascimento.dia != dia) && (p->nascimento.mes != mes)){
		p = p->prox;
	}
		printf("\nNome:\n");
		printf("%s", p->nome);
		
}

void reajuste(double reajuste, Lista *head)
{
	Lista *p;
	
	double porcentagem;
	
	porcentagem = reajuste/100;
	
	for(p = head->prox; p != NULL; p = p->prox)
	{
		printf("\nNome:\n");
		printf("%s", p->nome);
		p->salario = p->salario + (p->salario*porcentagem);	
		printf("%.2lf\n", p->salario);
	}	
}

void arquivo(Lista *head)
{
	FILE *pf;
	
	Lista *p;

	pf = fopen("ficha_funcionarios.txt","w");
	
	if(p == NULL){
		printf("arquivo nao pode ser aberto!\n");
	}

	fprintf(pf,"Nome /");
	fprintf(pf," Endereco /");
	fprintf(pf," Telefone /");
	fprintf(pf," Data de nascimento /");
	fprintf(pf," Data de admissao /");
	fprintf(pf," Salario /");
	fprintf(pf," Dependentes:\n\n");
	
	for(p = head->prox; p != NULL; p = p->prox)
	{
		
		fprintf(pf,"%s", p->nome);
		fprintf(pf,"%.0ld\n", p->matricula);
		fprintf(pf,"%s", p->endereco);	
		fprintf(pf,"%.0ld\n", p->telefone);
		fprintf(pf,"%d/%d/%d\n", p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
		fprintf(pf,"%.2lf\n", p->salario);
		fprintf(pf,"\n");
	}

	fclose(pf);
}

void dependentes(long int x, Lista *head)
{	
	int flag=1;
	
	Lista *p;
	
	for(p = head->prox; p != NULL;p = p->prox){
		if( p->matricula == x){
			for(j=0;j<p->numerodep;j++){
				printf("Dependente %d:\n", j+1);
				printf("%s", p->dependentes[j]);
				flag=0;
			}
		}
	}
		if(flag==1){
		printf("\nNao consta em nosso sistema.\n");
		}
}