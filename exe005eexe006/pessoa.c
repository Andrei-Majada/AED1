#include "pessoa.h"

void preenche(Pessoa temp)
{
    printf("informe o nome:\t");
    fgets(temp.nome,30,stdin);

    printf("informe o CPF:\t");
    scanf("%d", temp.cpf);

    printf("informe a data de nascimento:(dia/mes/ano)\t");
    scanf("%d/%d/%d", &temp.nascimento.dia, &temp.nascimento.mes, &temp.nascimento.ano);
}

void imprime(Pessoa temp)
{
    printf("Cadastro:\n");
    printf("nome:............%s", temp.nome);
    printf("CPF:.............%d", temp.cpf);
    printf("Data de Nasc.:...%d/%d/%d", temp.nascimento.dia, temp.nascimento.mes, temp.nascimento.ano);
}