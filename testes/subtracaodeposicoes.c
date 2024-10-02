#include <stdio.h>
#define MAX 8

void preenchervetor(int v[MAX]);
void printarvetor(int v[MAX]);
void subtracaodeposicoes(int v[MAX]);
void quantosvalorespares(int v[MAX]);
void vermenoremaiorvalor(int v[MAX], int *maior, int *menor, int *posmaior, int *posmenor);
void invertervetor(int v[MAX]);
void mediavetor(int v[MAX], float *media);  // Mudando para float para calcular a média

int main() {
    int v[MAX];
    int maior, menor;
    int posmaior, posmenor;
    float media;  // Mudando para float

    preenchervetor(v);
    printarvetor(v);
    printf("\n");
    subtracaodeposicoes(v);
    printf("\n");
    quantosvalorespares(v);
    printf("\n");
    vermenoremaiorvalor(v, &maior, &menor, &posmaior, &posmenor);
    printf("\n");
    invertervetor(v);
    printf("\n");
    mediavetor(v, &media);  // Passando para calcular a média
    return 0;
}

void preenchervetor(int v[MAX]) {
    for (int i = 0; i < MAX; ++i) {
        printf("DIGITE UM VALOR PARA O VETOR: ");
        scanf("%d", &v[i]);
    }
    printf("\n");
}

void printarvetor(int v[MAX]) {
    for (int i = 0; i < MAX; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void subtracaodeposicoes(int v[MAX]) {
    int x, y, subtracao;
    printf("Digite uma posição do vetor (0 a %d): ", MAX - 1);
    scanf("%d", &x);
    printf("Digite a outra posição do vetor (0 a %d): ", MAX - 1);
    scanf("%d", &y);

    // Validação de índices
    if (x < 0 || x >= MAX || y < 0 || y >= MAX) {
        printf("Posições inválidas!\n");
        return;
    }

    subtracao = v[x] - v[y];
    printf("A subtração do vetor na posição [%d] - vetor na posição [%d] é: %d\n", x, y, subtracao);
}

void quantosvalorespares(int v[MAX]) {
    int pares = 0;
    for (int i = 0; i < MAX; ++i) {
        if (v[i] % 2 == 0) {  // Mantendo a verificação para números pares
            pares += 1;
        }
    }
    printf("O número de pares dentro desse vetor é: %d\n", pares);
}

void vermenoremaiorvalor(int v[MAX], int *maior, int *menor, int *posmaior, int *posmenor) {
    *maior = v[0];
    *menor = v[0];
    *posmaior = 0;
    *posmenor = 0;

    for (int i = 1; i < MAX; ++i) {
        if (v[i] > *maior) {
            *maior = v[i];
            *posmaior = i;
        }
        if (v[i] < *menor) {
            *menor = v[i];
            *posmenor = i;
        }
    }
    printf("O maior elemento do vetor é: [%d] na posição: [%d], e o menor elemento do vetor é: [%d] na posição: [%d]\n", *maior, *posmaior, *menor, *posmenor);
}

void invertervetor(int v[MAX]) {
    printf("O vetor invertido é: ");
    for (int i = MAX - 1; i >= 0; --i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void mediavetor(int v[MAX], float *media) {
    int soma = 0; 
    for (int i = 0; i < MAX; ++i) {
        soma += v[i];
    }
    *media = (float)soma / MAX;  // Cálculo da média
    printf("A média desse vetor é de: %.2f\n", *media);  // Impressão da média
}
