#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_ALUNOS 100

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    int num_documento;
} Aluno;

void cadastrarAluno(Aluno *aluno, FILE *arquivo) {
    // Lê os dados do aluno do usuário
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno->nome);
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno->matricula);
    printf("Digite o numero do documento do aluno: ");
    scanf("%d", &aluno->num_documento);

    // Escreve os dados do aluno no arquivo
    fwrite(aluno, sizeof(Aluno), 1, arquivo);
}

void buscarAluno(FILE *arquivo, int matricula) {
    Aluno aluno;
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (aluno.matricula == matricula) {
            printf("Aluno encontrado:\n");
            printf("Nome: %s\n", aluno.nome);
            printf("Matricula: %d\n", aluno.matricula);
            printf("Numero do documento: %d\n", aluno.num_documento);
            return;
        }
    }
    printf("Aluno nao encontrado.\n");
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int num_alunos = 0;
    int matricula;

    FILE *arquivo = fopen("alunos.dat", "r+b");
    if (arquivo == NULL) {
        arquivo = fopen("alunos.dat", "w+b");
        if (arquivo == NULL) {
            printf("Erro ao abrir arquivo!\n");
            return 1;
        }
    } else {
        // Carrega os alunos do arquivo para o vetor
        while (fread(&alunos[num_alunos], sizeof(Aluno), 1, arquivo) == 1) {
            num_alunos++;
        }
    }

    int opcao;
    do {
        printf("\nSelecione uma opcao:\n");
        printf("1. Cadastrar novo aluno\n");
        printf("2. Buscar aluno por matricula\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (num_alunos < MAX_ALUNOS) {
                    cadastrarAluno(&alunos[num_alunos], arquivo);
                    num_alunos++;
                } else {
                    printf("Limite de alunos cadastrados atingido!\n");
                }
                break;
            case 2:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                buscarAluno(arquivo, matricula);
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    // Grava os alunos do vetor no arquivo
    fseek(arquivo, 0, SEEK_SET);
    fwrite(alunos, sizeof(Aluno), num_alunos, arquivo);

    fclose(arquivo);

    return 0;
}