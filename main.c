//Algoritmo de Busca Sequencial

#include<stdio.h>  //Biblioteca de funções para entrada e saída.
#include<stdlib.h> //Biblioteca de funções para alocação dinâmica.
#include"aluno.h"  //Biblioteca criada.

int main(void)
{
    //Declaração das seguintes variáves:
    int opcao1, opcao2;
    int quantL, i=0;
    char **matriz;

    //Inicio dos laços de repetição
    do{
        //Pergunta ao usuário o que ele deseja.
        printf("------------------------\n");
        printf("---  MENU DE OPÇÕES  ---\n");
        printf("------------------------");
        printf("\n");
        printf("[1] - Cadastrar Aluno\n");
        printf("[2] - Buscar Aluno\n");
        printf("[3] - Sair\n");
        scanf(" %d", &opcao1);

        //Primeiro switch.
        switch(opcao1){
        case 1:
            registraAluno("arquivo.txt");break;
        case 2:
            printf("Deseja Buscar Por Qual Dado:\n");
            printf("[1] - Nome\n");
            printf("[2] - Matricula\n");
            printf("[3] - Voltar\n");
            scanf(" %d", &opcao2);

            switch(opcao2){
            case 1:
                //A função quantLinhas é chamada e armazenada na variável quantL.
                quantL=quantLinhas("arquivo.txt");
                //A função vetorDeString é chamada e armazenada na variável matriz.
                matriz=vetorDeString("arquivo.txt", quantL);
                buscaSequencial(matriz, quantL,opcao2);break;
            case 2:
                //A função quantLinhas é chamada e armazenada na variável quantL.
                quantL=quantLinhas("arquivo.txt");
                //A função vetorDeString é chamada e armazenada na variável matriz.
                matriz=vetorDeString("arquivo.txt", quantL);
                 buscaSequencial(matriz, quantL, opcao2);break;
            default:
                printf("Opção Inválida.\n");
                
            }
        }
    }
    //Condição para sair do laço de repetição
    while (opcao1 != 3);
    
    //Liberação da memória alocada dinamicamente.
    liberaMemoria(matriz, quantL);
    return 0;
}