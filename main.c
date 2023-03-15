//Algoritmo de Busca Sequencial

#include<stdio.h>
#include"aluno.h"

int main(void)
{
    int quantidadeAlunos, opcao;
    printf("*****Registrar Aluno*****\n");
    printf("Deseja registrar quantos alunos:");
    scanf(" %d", &quantidadeAlunos);
    FILE *fp;
    registraAluno(fp, quantidadeAlunos);

    printf("Deseja buscar um aluno por qual dado:\n");
    printf("Digite 1 para buscar por: nome\n");
    printf("Digite 2 para buscar por: matricula\n");
    scanf(" %d", &opcao);
    return 0;
}