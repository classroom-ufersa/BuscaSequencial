#include <stdio.h>
#include <string.h>

// Definindo a estrutura Aluno
typedef struct {
    char nome[50];
    int matricula;
} Aluno;

int main() {
    // Definindo a lista de alunos matriculados
    Aluno listaAlunos[5] = {
        {"Ana", 123},
        {"Bruno", 456},
        {"Carlos", 789},
        {"Daniel", 101},
        {"Eva", 112}
    };

    // Definindo a matrícula a ser buscada
    int matriculaBuscada = 789;

    // Realizando a busca sequencial
    int i;
    for (i = 0; i < 5; i++) {
        if (listaAlunos[i].matricula == matriculaBuscada) {
            printf("O aluno %s esta matriculado com a matricula %d.\n", listaAlunos[i].nome, listaAlunos[i].matricula);
            break;
        }
    }

    // Se a busca chegou ao final da lista e não encontrou a matrícula buscada, exibe uma mensagem de erro
    if (i == 5) {
        printf("A matricula %d nao foi encontrada na lista de matriculas.\n", matriculaBuscada);
    }

    return 0;
}
