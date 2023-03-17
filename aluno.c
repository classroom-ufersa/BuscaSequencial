#include<stdio.h>
#include<string.h>
#include"aluno.h"

struct aluno
{
    char nome[50];
    int matricula;
    int documento;
};

int registraAluno(char *arquivo)
{
    //Declaração da variaveis e ponteiro.
    Aluno aluno;
    FILE *fp;
    //w(whrite) para criar o arquivo caso não exista.
    fp=fopen(arquivo, "wt"); 
    if(fp==NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //Imprime na tela do usuário.
    printf("Informe seu nome:\n");
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe sua matricula:\n");
    scanf(" %d", &aluno.matricula);
    printf("Informe seu documento:\n");
    scanf(" %d", &aluno.documento);
    
    //Escreve os dados que o usuário digitou no arquivo.
    //Temos aqui o seguinto problema:
    //Como escrever os dados de um aluno sem apagar os dados já escritos de outro aluno no arquivo?
    //Possiveis soluções:
    //1. Saber o fim de cada linha, depois pular uma linha e escrever o novos dados.
    fprintf(fp, "%s %d %d\n", aluno.nome, aluno.matricula, aluno.documento);

    //fecha o arquivo
    fclose(fp);
}

int quantLinhas(char *arquivo)
{
    int c, nlinhas=0;
    FILE *fp;
    fp=fopen(arquivo, "rt");
    //Temos aqui o seguinte problema:
    //Como será a saída do arquivo
    //Exmplos:
    //1. Charlys 890 123 seguido dos dados de outros alunos
    //2. Charlys 890 123
    //   Dados de outros alunos
    //3. Charlys 
    //   890  
    //   123
    //   Dados de outros alunos
    while((c=fgetc(fp)) != EOF){
        if(c=='\n'){
            nlinhas++;
        }
    }
    fclose(fp);
    printf("Quantidades de linhas do arquivo: %d\n", nlinhas);
    return nlinhas;
}