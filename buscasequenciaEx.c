#include <stdio.h>

int sequentialSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // retorna o índice em que o elemento foi encontrado
        }
    }
    return -1; // retorna -1 se o elemento não foi encontrado
}

int main() {
    int arr[] = {10, 7, 8, 15, 6};
    int x = 15;
    int n = sizeof(arr)/sizeof(arr[0]); // tamanho do array
    int result = sequentialSearch(arr, n, x);
    if (result == -1) {
        printf("Elemento não encontrado\n");
    } else {
        printf("Elemento encontrado no índice %d\n", result);
    }
    return 0;
}