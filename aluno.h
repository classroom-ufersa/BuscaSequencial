//Funções do módulo aluno.h

//struct aluno.
//Composta pelo tipos: char nome[50], int matricula e int documento.
typedef struct aluno Aluno;

//Função registraAluno.
//Objetivo: registra um aluno com os tipos da struct Aluno;
int registraAluno(char* arquivo);


//Função vetorDeString.
//Objetivo: ler e armazenar as strings do arquivo em uma matriz dinâmica.
char vetorDeString(char *arquivo);