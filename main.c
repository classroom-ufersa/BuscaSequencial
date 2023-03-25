//Algoritmo de Busca Sequencial

#include<stdio.h>  //Biblioteca de  para entrada e saída.
#include<stdlib.h> //Biblioteca de funções para alocação dinâmica.
#include"aluno.h"  //Biblioteca criada.

int main(void)
{
    //Declaração das seguintes variáves:
    //1. opcao1 e opcao2 para armazenarem as opções digitadas pelo usuário.
    //2. nome[50] armazena o nome do aluno que o usuário deseja buscar.
    //3. matricula armazena o número da matricula do aluno que o usuário deseja buscar.
    int opcao1, opcao2;
    char nome[50];
    int matricula;
    int quantL, i=0;
    char **matriz;

    //Pergunta ao usuário o que ele deseja.
    printf("Deseja fazer qual operação:\n");
    printf("Digite 1: para cadastrar um novo aluno\n");
    printf("Digite 2: para buscar por um aluno já cadastrado\n");
    scanf(" %d", &opcao1);
    
    //Estrutura de decição composta por dois switch.
    //Primeiro switch.
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

            //Segundo switch.
            switch(opcao2)
            {
                case 1:
                    printf("Informe o nome do aluno:\n");
                    scanf(" %[^\n]", nome);
                    //A função quantLinhas é chamada e armazenada na variável quantL.
                    quantL=quantLinhas("arquivo.txt");
                    //A função vetorDeString é chamada e armazenada na variável matriz.
                    matriz=vetorDeString("arquivo.txt", quantL);break;
                case 2:
                    printf("Informe o número da matricula do aluno:\n");
                    scanf(" %d", &matricula);
                    //A função quantLinhas é chamada e armazenada na variável quantL.
                    quantL=quantLinhas("arquivo.txt");
                    //A função vetorDeString é chamada e armazenada na variável matriz.
                    matriz=vetorDeString("arquivo.txt", quantL);break;
            }
    }

    //Liberação da memória alocada dinamicamente.
    liberaMemoria(matriz, quantL);
}