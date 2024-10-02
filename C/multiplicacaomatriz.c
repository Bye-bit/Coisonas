#include <stdio.h>
#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void multiplicarMatrizes(int matrizA[][QTD_COLUNAS], int linA, int colA, int matrizB[][QTD_COLUNAS], int linB, int colB, int matrizMult[][QTD_COLUNAS]) {
    if (colA != linB) {
        printf("Erro: Não é possível multiplicar. O número de colunas de A deve ser igual ao número de linhas de B.\n");
        return;
    }

    
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            matrizMult[i][j] = 0;
        }
    }


    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            for (int k = 0; k < colA; k++) {
                matrizMult[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void printMatriz(int matriz[][QTD_COLUNAS], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linA = 3, colA = 3;
    int linB = 3, colB = 2;


    int matrizA[QTD_LINHAS][QTD_COLUNAS] = {{1, 2, 3}, {4, 5, 6}, {6,7,8}};
    int matrizB[QTD_LINHAS][QTD_COLUNAS] = {{7, 8}, {9, 10}, {11, 12}};
    int matrizMult[QTD_LINHAS][QTD_COLUNAS];


    multiplicarMatrizes(matrizA, linA, colA, matrizB, linB, colB, matrizMult);

    printf("Resultado da multiplicação das matrizes:\n");
    printMatriz(matrizMult, linA, colB);

    return 0;
}
