//Implementação das funções.

#include<stdio.h>  //Biblioteca de entrada e saída.
#include<string.h> //Biblioteca de funções para manipulas strings.
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
    //Declaração das seguintes variáves:
    //1. aluno: variável do tipo struct Aluno.
    //2. *fp: ponteiro do tipo FILE, para abrir o arquivo.
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

//Implementação da função vetorDeString.
char vetorDeString(char *arquivo)
{
    //Declaração das seguintes variáves:
    //1. linhaDoArquivo[50]: vetor de caracteres para armazenar uma linha do arquivo.
    //2. i e nlinhas: i é usado como contador e nlinhas armazena a quantidade de linhas do arquivo.
    //3. *fp: ponteiro do tipo FILE, para abrir o arquivo.
    char linhaDoArquivo[50];
    int i=0, nlinhas;
    FILE *fp;

    //Testa se o arquivo foi encontrado e aberto.
    fp=fopen(arquivo, "rt");
    if(fp==NULL){
        printf("Erro ao abrir!\n");
        return 1;
    }
    
    //Laço de repetição para contar a quantidade de linhas do arquivo.
    while(fgets(linhaDoArquivo, 50, fp) != NULL) {
        nlinhas++;
    }
    
    //Alocação da matriz para armazenar as linhas do arquivo.
    char **matriz=(char **) malloc(nlinhas*sizeof(char *));//Aloca as linhas
    for(i=0; i<nlinhas; i++) {                              
        matriz[i]=(char *) malloc(50*sizeof(char));//Aloca as colunas
    }

    //A função int rewind(FILE *fp) faz voltar para o inicio do arquivo.
    rewind(fp);

    //Laço de repetição para ler uma linha do arquivo e copiá-la para a matriz.
    i=0;
    while(fgets(linhaDoArquivo, 50, fp) != NULL) {
        strcpy(matriz[i], linhaDoArquivo);
        i++;
    }  

    //Apenas um teste para imprimir as linhas lidas.
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