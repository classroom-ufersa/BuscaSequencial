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
int vetorDeString(char *arquivo)
{

}