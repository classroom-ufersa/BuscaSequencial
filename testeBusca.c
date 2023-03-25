#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_ALUNOS 100

typedef struct {
    char nome[MAX_NOME];
    int matricula;
    int num_doc;
} Aluno;

int buscar_aluno(Aluno *alunos, int n, char *nome) {
    for (int i = 0; i < n; i++) {
        if (strcmp(alunos[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Aluno alunos[MAX_ALUNOS];
    int n = 0;

    // Ler os alunos do arquivo
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    char linha[MAX_NOME + 20];
    while (fgets(linha, MAX_NOME + 20, arquivo) != NULL) {
        sscanf(linha, "%[^,],%d,%d", alunos[n].nome, &alunos[n].matricula, &alunos[n].num_doc);
        n++;
    }
    fclose(arquivo);

    // Buscar um aluno pelo nome
    char nome_busca[MAX_NOME];
    printf("Digite o nome do aluno a buscar: ");
    scanf("%s", nome_busca);
    int indice = buscar_aluno(alunos, n, nome_busca);
    if (indice == -1) {
        printf("Aluno nao encontrado.\n");
    } else {
        printf("Aluno encontrado: %s (Matricula: %d, Numero do Documento: %d)\n", alunos[indice].nome, alunos[indice].matricula, alunos[indice].num_doc);
    }

    return 0;
}
