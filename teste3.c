#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_ARQUIVO 1000

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    int numero_documento;
} Aluno;

int buscar_aluno(FILE *arquivo, int matricula, Aluno *aluno) {
    char linha[MAX_NOME + 20]; // +20 para a matrícula e o documento
    while (fgets(linha, MAX_NOME + 20, arquivo) != NULL) {
        int m, d;
        char n[MAX_NOME];
        sscanf(linha, "%[^,],%d,%d", n, &m, &d);
        if (m == matricula) {
            strcpy(aluno->nome, n);
            aluno->matricula = m;
            aluno->numero_documento = d;
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    Aluno aluno;
    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);

    if (buscar_aluno(arquivo, matricula, &aluno)) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", aluno.nome);
        printf("Matricula: %d\n", aluno.matricula);
        printf("Documento: %d\n", aluno.numero_documento);
    } else {
        printf("Aluno nao encontrado!\n");
    }

    fclose(arquivo);
    return 0;
}