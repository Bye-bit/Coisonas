#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 625000

void insertionsort(int arr[], int tamanho);
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
    insertionsort(dados, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR TOTALMENTE DESORDENADO\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherCrescente(dados, TAMANHO);
    inicio = clock();
    insertionsort(dados, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM CRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    preencherDecrescente(dados, TAMANHO);
    inicio = clock();
    insertionsort(dados, TAMANHO);
    fim = clock();
    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("ORDENAÇÃO DE VETOR ORDENADO (ORDEM DECRESCENTE)\n");
    printf("Tempo de execução: %f ms\n\n", tempo);

    free(dados);
    return 0;
}

void insertionsort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;

       
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave; 
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
