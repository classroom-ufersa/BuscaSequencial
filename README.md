# BuscaSequencial
O algoritmo de busca sequencial ou linear é um algoritmo de busca em que um determinado elemento é pesquisado e comparado acessando índice por índice de um vetor ou uma matriz, seja ele um vetor ou uma matriz, ordenados ou não ordenados, até encontrar o elemento.

## Vantagens:
- A busca é rápida para listas pequenas ou médias.

- Não é necessário ordenar os elesmentos da lista.

- A pesquisa não é afetada se algum elemento for inserido ou excluído.
## Desvantagens:
- O processo de pesquisa é lento para uma matriz grande.

- Se o elemento que é pesquisado estiver no último índice da matriz ou do vetor, teremos que comparar o elemento pesquisando com todos os elementos anteriores.

## Complexidade 
O algoritmo de busca sequencial tem o tempo de execução linear.

A complexida do algoritmo de busca sequencial é O(n).

## Como compilar e executar:
Para compilar e executa este código, digite a seguinte linha de comando no terminal:

Linux/bash: gcc -c aluno.c && gcc -c main.c && gcc -o prog aluno.o main.o && ./prog

Windows/powershell: gcc -c aluno.c; gcc -c main.c; gcc -o prog.exe aluno.o main.o; ./prog