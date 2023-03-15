#include<stdio.h>
#include<string.h>
#include"aluno.h"

struct aluno
{
    char nome[50];
    int matricula;
    int documento;
};

void registraAluno(FILE *arquivo, int quant)
{
    Aluno aluno;
    int i;
    FILE *fp;
    fp=fopen("arquivo", "wt");
    if(fp==NULL){
        printf("Erro ao abrir o arquivo\n");
    }
    for(i=0; i<quant; i++){
    printf("Informe seu nome:\n");
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe sua matricula:\n");
    scanf(" %d", &aluno.matricula);
    printf("Informe seu documento:\n");
    scanf(" %d", &aluno.documento);

    fprintf(fp, "%s\n", aluno.nome);
    fprintf(fp, "%d\n", aluno.matricula);
    fprintf(fp, "%d\n", aluno.documento);
    fprintf(fp, "\n");
    printf("\n");
    }
    
    fclose(fp);

}

void buscaSequencial(FILE *arquivo)
{
    FILE *fp;
    char str[100];
    char vetor_string[4][10];
    int i=0;
    fp=fopen("arquivo", "rt");
    if(fp==NULL){
        printf("Deu errado\n");
    }

     while(fgets(str, 100, fp) != NULL){
        strcpy(vetor_string[i], str);
        i=i+1;
    }
    
    fclose(fp);

    for (int i = 0; i <4; i++) {
        printf("%s\n", vetor_string[i]);
    }
}