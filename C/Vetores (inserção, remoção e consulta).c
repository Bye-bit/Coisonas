#include <stdio.h>

#define MAX 50


void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;  // Não encontrado
}


void removerElemento(int vetor[], int *tamanho, int valor) {
    int pos = buscaBinaria(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Elemento não encontrado.\n");
        return;
    }
    for (int i = pos; i < (*tamanho) - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("Elemento removido com sucesso.\n");
}


void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX) {
        printf("Vetor cheio! Não é possível inserir mais elementos.\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
    printf("Elemento inserido com sucesso.\n");
}


void menu(int vetor[], int *tamanho) {
    int opcao, valor;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Imprimir todo o vetor\n");
        printf("2. Consultar posição de um elemento (Busca Binária)\n");
        printf("3. Remover um elemento\n");
        printf("4. Inserir um valor ordenado\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            imprimirVetor(vetor, *tamanho);
        } else if (opcao == 2) {
            printf("Digite o valor para consultar: ");
            scanf("%d", &valor);
            int posicao = buscaBinaria(vetor, *tamanho, valor);
            if (posicao != -1)
                printf("Elemento encontrado na posição %d\n", posicao);
            else
                printf("Elemento não encontrado.\n");
        } else if (opcao == 3) {
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);
            removerElemento(vetor, tamanho, valor);
        } else if (opcao == 4) {
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            inserirOrdenado(vetor, tamanho, valor);
        } else if (opcao == 5) {
            printf("Saindo...\n");
        } else {
            printf("Opção inválida!\n");
        }
    } while (opcao != 5);
}

int main() {
    int vetor[MAX];
    int tamanho;


    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    // Solicita ao usuário para inserir os elementos ordenadamente
    int elementosInseridos = 0;
    while (elementosInseridos < tamanho) {
        int valor;
        printf("Digite o valor %d: ", elementosInseridos + 1);
        scanf("%d", &valor);
        inserirOrdenado(vetor, &elementosInseridos, valor);  // Aqui controlamos o número de elementos inseridos
    }


    menu(vetor, &tamanho);

    return 0;
}
