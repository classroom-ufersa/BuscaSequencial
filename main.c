//Algoritmo de Busca Sequencial

#include<stdio.h>
#include"aluno.h"

int main(void)
{
    //Declaração de variaveis.
    int opcao1, opcao2;
    
    //Pergunta ao usuário o que ele deseja.
    printf("Deseja fazer qual operação:\n");
    printf("Digite 1: para cadastrar um novo aluno\n");
    printf("Digite 2: para buscar por um aluno já cadastrado\n");
    scanf(" %d", &opcao1);
    
    switch(opcao1)
    {
        case 1:
            registraAluno("arquivo.txt");
            printf("Aluno cadastrado com sucesso!\n"); break;
        case 2:
            printf("Deseja buscar um aluno por qual dado:\n");
            printf("Digite 1: para buscar pelo nome\n");
            printf("Digite 2: para buscar pelo número da matricula\n");
            scanf(" %d", &opcao2);
            switch(opcao2)
            {
                case 1:printf("opção 1");break;

                case 2:printf("opção 2\n");break;
                        
            }
    }
    return 0;
}