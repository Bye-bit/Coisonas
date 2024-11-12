#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

void selectionsort(int arr[], int tamanho);
void preencherAleatorio(int arr[], int tamanho);
void preencherCrescente(int arr[], int tamanho);
void preencherDecrescente(int arr[], int tamanho);

int main() {
    clock_t inicio, fim;
    double tempo;
    int *dados = (int *) malloc(TAMANHO * sizeof(int));
    srand(22);

    if (dados == NULL) {
        printf("Falha na alocação da memória!\n");
        return 1;
    }

    preencherAleatorio(dados, TAMANHO);
    inicio = clock();
    selectionsort(dados, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR TOTALMENTE DESORDENADO\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherCrescente(dados, TAMANHO);
    inicio = clock();
    selectionsort(dados, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM CRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherDecrescente(dados, TAMANHO);
    inicio = clock();
    selectionsort(dados, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM DECRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    free(dados);
    return 0;
}

void selectionsort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void preencherAleatorio(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; ++i) {
        arr[i] = rand() % 100;
    }
}

void preencherCrescente(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; ++i) {
        arr[i] = i;
    }
}

void preencherDecrescente(int arr[], int tamanho) {
    for(int i = 0; i < tamanho; ++i) {
        arr[i] = tamanho - i - 1;
    }
}
