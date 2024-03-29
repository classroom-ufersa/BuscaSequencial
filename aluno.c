//Implementação das funções do módulo aluno.h.

#include <stdio.h>  //Biblioteca de entrada e saída.
#include <string.h> //Biblioteca de funções para manipular strings.
#include <stdlib.h> //Biblioteca de funções para alocação dinâmica.
#include <time.h>   //Biblioteca de funções para manipular unidades de tempo.
#include "aluno.h"  //Módulo criado.

//Implementação da struct Aluno.
struct aluno
{
    char nome[50];  
    int matricula;
    int documento;
};

//Implementação da função registraAluno.
int registraAluno(char *arquivo)
{
    //Declaração das variáves.
    Aluno aluno;
    FILE *fp;

    //Testa se o arquivo foi encontrado e aberto.
    fp=fopen(arquivo, "a"); 
    if(fp == NULL){
        printf("Erro ao Abrir o Arquivo\n");
        printf("Resultado: Não foi possível Cadastrar o Aluno.\n");
        return 1;
    }

    //Imprime as seguintes menssagens na tela do usuário.
    //Ler as informações digitadas pelo usuário.
    printf("Informe o Nome:");
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe o Número da Matricula:");
    scanf(" %d", &aluno.matricula);
    printf("Informe o Número do Documento:");
    scanf(" %d", &aluno.documento);
    
    //Escreve os dados que o usuário digitou no arquivo.
    fprintf(fp, "%s\n%d\n%d\n", aluno.nome, aluno.matricula, aluno.documento);

    //fecha o arquivo
    fclose(fp);

    //Informa ao usuário que o aluno foi cadastrado.
    printf("\nResultado: Aluno Cadastrado.\n\n");
}

int quantLinhas(char *arquivo)
{
    //Declaração das variáveis.
    char linhaDoArquivo[50];
    int i=0, nlinhas=0;
    FILE *fp;
    fp=fopen(arquivo, "rt");

    //Testa se o arquivo foi encontrado e aberto.
    if(fp == NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }

    //Laço de repetição para contar a quantidade de linhas do arquivo.
    while(fgets(linhaDoArquivo, 50, fp) != NULL){
        nlinhas++;
    }

    //Fecha o arquivo.
    fclose(fp);

    //Retorna a quantidade de linhas do arquivo.
    return nlinhas;
}

//Implementação da função liberaMemoria
void liberaMemoria(char **matriz, int m)
{
    //i é contador para o laço de repetição for.
    int i;
    
    //Estrutura de repetição para liberar a memória alocada pela matriz.
    for(i=0; i<m; i++){
        free(matriz[i]);
    }
    free(matriz);
}

//Implementação da função vetorDeString.
char **vetorDeString(char *arquivo, int nlinhas)
{
    //Declaração das variáveis.
    char linhaDoArquivo[50];
    int i=0;
    FILE *fp;

    //Testa se o arquivo foi encontrado e aberto.
    fp=fopen(arquivo, "rt");
    if(fp == NULL){
        printf("Erro ao abrir!\n");
        printf("Resultado: Não foi possível Buscar o Aluno.\n");
        exit(1);
    }
    
    //Alocação da matriz para armazenar as linhas do arquivo.
    char **matriz=(char **) malloc(nlinhas*sizeof(char *));//Aloca as linhas.
    for(i=0; i<nlinhas; i++) {                              
        matriz[i]=(char *) malloc(50*sizeof(char));//Aloca as colunas.
    }

    //Laço de repetição para ler uma linha do arquivo e copiá-la para a matriz.
    i=0;
    while(fgets(linhaDoArquivo, 50, fp) != NULL){
        strcpy(matriz[i], linhaDoArquivo);
        i++;
    }  

    //Fecha o arquivo
    fclose(fp);

    //Retorna um ponteiro para ponteiro, para o primeiro índice da matriz.
    return matriz;
}

//Implementação da função buscaSequencialNome.
void buscaSequencialNome(char **matriz, int nlinhas, char nome[50])
{
    //Declaração das variáveis.
    double tempo;
    time_t TempoInicial, TempoFinal;
    TempoInicial=clock();
    
    int i; //Executa 1 vez: c1

    //Laço de repetição para encontrar o nome do aluno na matriz.
    for(i=0; i<nlinhas; i++){ //Executa n vezes: c2

        //A função strstr, retorna um ponteiro para o primeiro caractere da ocorrência da substring nome[50] dentro da strig matriz[i].
        //Caso a não ocorra nenhuma ocorrência a função strstr retorna NULL.
        if(strstr(matriz[i], nome) != NULL){ //Executa n vezes: c3

            //Imprime o resultado caso o nome do aluno seja encontrado.
            printf("\nResultado: Aluno Encontrado.\n");
            printf("Índice da Matriz: %d.\n", i);
            printf("Linha do Arquivo: %d.\n\n", i+1);
            
            //Imprime o tempo de execução.
            TempoFinal=clock();
            tempo=((double)(TempoFinal-TempoInicial))/CLOCKS_PER_SEC;
            printf("Tempo de execução: %f.\n", tempo);
            return;
            }
        }

    //Imprime o resultado caso o nome do aluno não seja encontrado.

    //Imprime o tempo de execução.
    printf("\nResultado: Aluno Não Encontrado.\n\n");
    TempoFinal=clock();
    tempo=((double)(TempoFinal-TempoInicial))/CLOCKS_PER_SEC;
    printf("Tempo de execução: %f.\n", tempo);
    /*
    Análise da complexidade da função buscaSequencialNome:
    T(n)=c1+c2*n+c3*n
    T(n)=n*(c2+c3)+c1: Tempo de Execução Linear.
    ----
    Notação big-o:
    T(n)= O(n). 
    */
}

//Implementação da função buscaSequencialMatricula.
void buscaSequencialMatricula(char **matriz, int nlinhas, int matricula)
{
    //Declaração das variáveis para o calculo do tempo de execução.
    double tempo;
    time_t TempoInicial, TempoFinal;
    TempoInicial=clock();
    
    //Declaração de variáveis para a função buscaSequencialMatricula.
    char mat[20]; //Executa 1 vez: c1.
    int i; //Executa 1 vez: c2.

    //A função sprintf paconverte a variável matricula para o tipo char.
    sprintf(mat, "%d", matricula);

    //Laço de repetição para encontrar o número da matricula do aluno na matriz.
    for(i=0; i<nlinhas; i++){ //Executa n vezes: c3.
        
        //A função strstr, retorna um ponteiro para o primeiro caractere da ocorrência da substring nome[50] dentro da strig matriz[i].
        //Caso a não ocorra nenhuma ocorrência a função strstr retorna NULL.
        if(strstr(matriz[i], mat) != NULL){ //Executa n vezes: c4.

            //Imprime o resultado caso o nome do aluno seja encontrado.
            printf("\nResultado: Aluno Encontrado.\n");
            printf("Índice da Matriz: %d.\n", i);
            printf("Linha do Arquivo: %d.\n\n", i+1);
            
            //Imprime o tempo de execução.
            TempoFinal=clock();
            tempo=((double)(TempoFinal-TempoInicial))/CLOCKS_PER_SEC;
            printf("Tempo de execução: %f.\n", tempo);
            return;
            }
        }

    //Imprime o resultado caso o nome do aluno não seja encontrado.
    printf("\nResultado: Aluno Não Encontrado.\n\n");
    
    //Imprime o tempo de execução.
    TempoFinal=clock();
    tempo=((double)(TempoFinal-TempoInicial))/CLOCKS_PER_SEC;
    printf("Tempo de execução: %f.\n", tempo);
    /*
    Análise da complexidade da função buscaSequencialMatricula:
    T(n)=c1+c2+c3*n+c4*n
    T(n)=n*(c3+c4)+c1+c2: Tempo de Execução Linear.
    ----
    Notação big-o:
    T(n)= O(n). 
    */
}