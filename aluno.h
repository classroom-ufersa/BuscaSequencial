//Funções do módulo aluno.h

//struct aluno.
//Composta pelo tipos: char nome[50], int matricula e int documento.
typedef struct aluno Aluno;


//Função registraAluno.
//Obejtivo: registra um aluno com os tipos da struct Aluno;
void registraAluno(FILE* arquivo, int quant);

void buscaSequencial(FILE *arquivo);
