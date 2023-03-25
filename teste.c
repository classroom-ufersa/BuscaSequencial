#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    char documento[MAX_NOME];
} Aluno;

int buscar_aluno(FILE *arquivo, char *nome_busca, Aluno *aluno_encontrado) {
    char linha[MAX_NOME * 3]; // Tamanho máximo de uma linha no arquivo
    char nome[MAX_NOME];
    int matricula;
    char documento[MAX_NOME];

    // Lê cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Separa os campos da linha
        sscanf(linha, "%[^,],%d,%[^,\n]", nome, &matricula, documento);

        // Se o nome corresponde à busca, retorna o aluno encontrado
        if (strcmp(nome, nome_busca) == 0) {
            strcpy(aluno_encontrado->nome, nome);
            aluno_encontrado->matricula = matricula;
            strcpy(aluno_encontrado->documento, documento);
            return 1;
        }
    }

    // Se não encontrou nenhum aluno com o nome buscado, retorna 0
    return 0;
}

int main() {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    char nome_busca[MAX_NOME];
    printf("Digite o nome do aluno a ser buscado: ");
    scanf("%s", nome_busca);

    Aluno aluno_encontrado;
    if (buscar_aluno(arquivo, nome_busca, &aluno_encontrado)) {
        printf("Aluno encontrado:\n");
        printf("Nome: %s\n", aluno_encontrado.nome);
        printf("Matrícula: %d\n", aluno_encontrado.matricula);
        printf("Documento: %s\n", aluno_encontrado.documento);
    } else {
        printf("Aluno nao encontrado.\n");
    }

    fclose(arquivo);

    return 0;
}