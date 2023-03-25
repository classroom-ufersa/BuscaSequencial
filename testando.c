#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    int numero_documento;
} Aluno;

void cadastrar_aluno(FILE *arquivo, Aluno aluno) {
    fprintf(arquivo, "%s,%d,%d\n", aluno.nome, aluno.matricula, aluno.numero_documento);
}

Aluno buscar_aluno(FILE *arquivo, int matricula) {
    Aluno aluno;
    char linha[MAX_NOME + 20]; // +20 para os números e vírgulas

    while (fgets(linha, MAX_NOME + 20, arquivo) != NULL) {
        sscanf(linha, "%[^,],%d,%d", aluno.nome, &aluno.matricula, &aluno.numero_documento);
        if (aluno.matricula == matricula) {
            return aluno;
        }
    }

    aluno.matricula = -1; // indica que não encontrou o aluno
    return aluno;
}

int main() {
    FILE *arquivo = fopen("alunos.txt", "a+");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    int opcao, matricula;
    Aluno aluno;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Buscar aluno\n");
        printf("0. Sair\n");

        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nCadastrar aluno:\n");
                printf("Nome: ");
                scanf("%s", aluno.nome);
                printf("Matricula: ");
                scanf("%d", &aluno.matricula);
                printf("Numero do documento: ");
                scanf("%d", &aluno.numero_documento);

                cadastrar_aluno(arquivo, aluno);
                printf("\nAluno cadastrado com sucesso!\n");
                break;
            case 2:
                printf("\nBuscar aluno:\n");
                printf("Matricula: ");
                scanf("%d", &matricula);

                aluno = buscar_aluno(arquivo, matricula);
                if (aluno.matricula == -1) {
                    printf("\nAluno nao encontrado!\n");
                } else {
                    printf("\nNome: %s\n", aluno.nome);
                    printf("Matricula: %d\n", aluno.matricula);
                    printf("Numero do documento: %d\n", aluno.numero_documento);
                }
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    fclose(arquivo);

    return 0;
}
