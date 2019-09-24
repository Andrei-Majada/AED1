#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int dia,mes,ano;
}Data;

typedef struct lista
{
    char nome[30];
    long int cpf;
    Data nascimento;
}Pessoa;

void preenche(Pessoa temp);

void imprime(Pessoa temp);