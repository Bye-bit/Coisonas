#include <stdio.h>
#define MAX 6

void inserirvaloresordenados(int v[MAX], int *tamanho);
void printarvetor(int v[MAX], int tamanho);
void substituirvaloremposicao(int v[MAX], int *tamanho);
void somadeposicoes(int v[MAX]);
void mostrarvaloresvetorseparado(int v[MAX]);

int main() {
    int v[MAX] = {0};
    int tamanho = 0;

    for (int i = 0; i < MAX; i++) {
        inserirvaloresordenados(v, &tamanho);
    }

    printf("O vetor agora é: ");
    printarvetor(v, tamanho);

    // Chamada para substituir valor em posição
    substituirvaloremposicao(v, &tamanho);
    printf("Após substituir o valor: ");
    printarvetor(v, tamanho);
    printf("\n");
    somadeposicoes(v);
    mostrarvaloresvetorseparado(v);

    return 0;
}

void inserirvaloresordenados(int v[MAX], int *tamanho) {
    if (*tamanho >= MAX) {
        printf("O vetor já está cheio!\n");
        return;
    }

    int valor;
    printf("Digite um valor para inserir: ");
    scanf("%d", &valor);

    int i = *tamanho - 1;
    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = valor;
    (*tamanho)++;
}

void printarvetor(int v[MAX], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("[%d] ", v[i]);
    }
    printf("\n");
}

void substituirvaloremposicao(int v[MAX], int *tamanho) {
    int posicao, novoValor;

    printf("Digite a posição do valor que você deseja mudar: ");
    scanf("%d", &posicao);
    printf("Digite o valor que você deseja usar para substituir: ");
    scanf("%d", &novoValor);

    if (posicao < 0 || posicao >= *tamanho) {
        printf("Posição inválida!\n");
        return;
    }
    v[posicao] = novoValor;
}

void somadeposicoes(int v[MAX]) {
    int soma;
    soma = v[0] + v[1] + v[5];
    printf("a soma das posicoes [0];[1];[5] e: %d",soma);
    printf("\n");
}

void mostrarvaloresvetorseparado(int v[MAX]) {
    for(int i = 0; i < MAX;++i) {
        printf("%d\n",v[i]);
    }
    printf("\n");
}