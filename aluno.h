//Funções do módulo aluno.h

typedef struct aluno Aluno;
//struct aluno.
//Composta pelo tipos: char nome[50], int matricula e int documento.

int registraAluno(char* arquivo);
//Função registraAluno.
//Obejtivo: registra um aluno com os tipos da struct Aluno;
//O ponteiro arquivo já armazena o nome do arquivo.

char vetorDeString(char *arquivo);