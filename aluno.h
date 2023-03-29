//Funções do módulo aluno.h

//struct aluno.
//Composta pelo tipos: char nome[50], int matricula e int documento.
typedef struct aluno Aluno;

//Função registraAluno.
//Objetivo: registra um aluno com os tipos da struct Aluno;
int registraAluno(char* arquivo);

//Função quanLinhas.
//Objetivo: contar, armazenar e retonar a quantidade de linhas do arquivo.
int quantLinhas(char *arquivo);

//Função vetorDeString.
//Objetivo: ler e armazenar as strings do arquivo em uma matriz dinâmica.
char **vetorDeString(char *arquivo, int nlinhas);

//Função liberaMemoria.
//Objetivo: libera a memoria alocada dinamicamente pela matriz.
void liberaMemoria(char **matriz, int m);

//Função buscaSequencialNome.
//Objetivo: busca pelo nome de um aluno.
void buscaSequencialNome(char **matriz, int nlinhas, char nome[50]);

//Função buscaSequencialMatricula.
//Objetivo: busca pelo número da matrícula de um aluno.
void buscaSequencialMatricula(char **matriz, int nlinhas, int matricula);