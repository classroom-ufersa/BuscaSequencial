#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"aluno.h"

struct aluno
{
    char nome[50];
    int matricula;
    int documento;
};

//Função para registrar os dados dos alunos no arquivo.
int registraAluno(char *arquivo)
{
    //Declaração da variaveis e ponteiro.
    Aluno aluno;
    FILE *fp;
    fp=fopen(arquivo, "a"); 
    if(fp==NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //Imprime na tela do usuário.
    printf("Informe o nome:\n");
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe o número da matricula:\n");
    scanf(" %d", &aluno.matricula);
    printf("Informe o número do documento:\n");
    scanf(" %d", &aluno.documento);
    
    //Escreve os dados que o usuário digitou no arquivo.
    fprintf(fp, "%s %d %d\n", aluno.nome, aluno.matricula, aluno.documento);

    //fecha o arquivo
    fclose(fp);
}

//Função para ler e escrever os dados dos alunos em uma matriz dinâmica.
//Partes da função:
//1. Contar a quantidade de linhas do arquivo
//2. Alocar dinamicamente usando a quantidade de linhas
//3. Ler e preencher a matriz com o conteúdo do arquivo
char vetorDeString(char *arquivo)
{
    //Declaração das variaveis.
    char linhaDoArquivo[50];
    int i=0, nlinhas;
    FILE *fp;
    fp=fopen(arquivo, "rt");
    if(fp==NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    
    //Estrutura para contar a quantidade de linhas do arquivo.
    while(fgets(linhaDoArquivo, 50, fp) != NULL) {
        nlinhas++;
    }
    
    //Alocação da matriz para armazenar as linhas do arquivo.
    char **matriz = (char **) malloc(nlinhas * sizeof(char *)); // aloca as linhas
    for(i=0; i<nlinhas; i++) { // aloca as colunas
        matriz[i] = (char *) malloc(50 * sizeof(char));
    }

    //Volta para o inicio do arquivo
    rewind(fp);

    //Ler e escrever as linhas do arquivo na matriz
    i=0;
    while(fgets(linhaDoArquivo, 50, fp) != NULL) {
        strcpy(matriz[i], linhaDoArquivo);
        i++;
    }  

    //Apenas um teste para ver as linhas lidas
    printf("Strigs lidas:\n");
    for(i=0; i<nlinhas; i++){
        printf("%s", matriz[i]);
    }

    //Fecha o arquivo
    fclose(fp);

    //Libera a memória alocada.
    for(i=0; i<nlinhas; i++){ 
        free(matriz[i]);
    }
    free(matriz); 
}