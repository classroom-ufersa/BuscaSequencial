//Algoritmo de Busca Sequencial

#include<stdio.h>  //Biblioteca de funções para entrada e saída.
#include<stdlib.h> //Biblioteca de funções para alocação dinâmica.
#include"aluno.h"  //Módulo criado.

int main(void)
{
    //Declaração das seguintes variáves:
    int opcao1, opcao2;
    int quantL, i=0;
    char **matriz;
    char nome[50];
    int matricula;

    do{

        //Pergunta ao usuário o que ele deseja.
        printf("------------------------\n");
        printf("---  MENU DE OPÇÕES  ---\n");
        printf("------------------------");
        printf("\n");
        printf("[1] - Cadastrar Aluno\n");
        printf("[2] - Pesquisar Aluno\n");
        printf("[3] - Sair\n");
        scanf(" %d", &opcao1);

        switch(opcao1){
        case 1:

            //Chamada a função registraAluno.
            registraAluno("arquivo.txt");break;

        case 2:
            //Pergunta ao usuário o que ele deseja.
            printf("Deseja Pesquisar Por Qual Dado:\n");
            printf("[1] - Nome\n");
            printf("[2] - Matricula\n");
            scanf(" %d", &opcao2);
            
            switch(opcao2){
            case 1:

                //Pergunta ao usuário qual o nome do aluno a ser pesquisado.
                printf("Informe o Nome do Aluno:");
                scanf(" %[^\n]", nome);

                //A função quantLinhas é chamada e armazenada na variável quantL.
                quantL=quantLinhas("arquivo.txt");

                //A função vetorDeString é chamada e armazenada na variável matriz.
                matriz=vetorDeString("arquivo.txt", quantL);

                //Chamada da função buscaSequencialNome.
                buscaSequencialNome(matriz, quantL, nome);break;

            case 2:

                //Pergunta ao qual o número da matrícula do alno a ser pesquisado.
                printf("Informe o Número da Matrícula do Aluno:");
                scanf(" %d", &matricula);

                //A função quantLinhas é chamada e armazenada na variável quantL.
                quantL=quantLinhas("arquivo.txt");

                //A função vetorDeString é chamada e armazenada na variável matriz.
                matriz=vetorDeString("arquivo.txt", quantL);

                //Chamada da função buscaSequencialMatricula.
                buscaSequencialMatricula(matriz, quantL, matricula);break;

            default:

                //Informa ao usuário que a opção escolhida é inválida.
                printf("Opção Inválida.\n");
            
            }
        }
    }
    //Condição para sair do laço de repetição
    while(opcao1 != 3);
    
    //Liberação da memória alocada dinamicamente.
    liberaMemoria(matriz, quantL);

    return 0;
}