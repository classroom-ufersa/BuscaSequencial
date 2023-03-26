//Implementação das funções do módulo aluno.h.

#include<stdio.h>  //Biblioteca de entrada e saída.
#include<string.h> //Biblioteca de funções para manipular strings.
#include<stdlib.h> //Biblioteca de funções para alocação dinâmica.
#include"aluno.h"  //Biblioteca criada.

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
    if(fp==NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //Imprime as seguintes menssagens na tela do usuário.
    //Ler as informações digitadas pelo usuário.
    printf("Informe o nome: ");
    scanf(" %[^\n]s", aluno.nome);
    printf("Informe o número da matricula: ");
    scanf(" %d", &aluno.matricula);
    printf("Informe o número do documento: ");
    scanf(" %d", &aluno.documento);
    
    //Escreve os dados que o usuário digitou no arquivo.
    fprintf(fp, "%s\n%d\n%d\n", aluno.nome, aluno.matricula, aluno.documento);

    //fecha o arquivo
    fclose(fp);

    //Informa ao usuário que o aluno foi cadastrado.
    printf("\n--Aluno cadastrado com sucesso!--\n\n");
}

int quantLinhas(char *arquivo)
{
    char linhaDoArquivo[50];
    int i=0, nlinhas=0;
    FILE *fp;
    fp=fopen(arquivo, "rt");
    if(fp==NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    while(fgets(linhaDoArquivo, 50, fp) != NULL){
        nlinhas++;
    }
    fclose(fp);
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
    if(fp==NULL){
        printf("Erro ao abrir!\n");
        exit(1);
    }
    
    //Alocação da matriz para armazenar as linhas do arquivo.
    char **matriz=(char **) malloc(nlinhas*sizeof(char *));//Aloca as linhas
    for(i=0; i<nlinhas; i++) {                              
        matriz[i]=(char *) malloc(50*sizeof(char));//Aloca as colunas
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

//Implementação da função buscaSequencialNome
void buscaSequencialNome(char **matriz, int nlinhas, char nome[50])
{
    int i;
    for (i=0; i<nlinhas; i++){
        if(strstr(matriz[i], nome) != NULL)
        {
            printf("Aluno Encontrado.\n");
            return;
        }
    }
    printf("Aluno Não Encontrado.\n");
}

//Para matricula
void buscaMatricula(char **matriz, int nlinhas, int matricula)
{
    char mat[20];
    sprintf(mat, "%d", matricula);
    int i;
    for (i=0; i<nlinhas; i++) {
        if (strstr(matriz[i], mat) != NULL) {
            printf("Aluno Encontrado.\n");
            return;
        }
    }
    printf("Aluno Não Encontrado.\n");
}