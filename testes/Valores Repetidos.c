//Alunos: Lucas Fernandes Nunes Machado RA:00000852836
//Alunos: João Victor Castelo Branco de Sena RA: 00000853774

#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 4

void preencherMatriz(int m[][N], int lin, int col);
void imprimirMatriz(int m[][N], int lin, int col);
void maiorCadaColuna(int m[][N], int lin, int col, int v[]);
void imprimirVetor(int v[], int tam);
void contarRepeticoes(int m[][N], int lin, int col);

int main() {
    int matriz[M][N];
    int opcao;
    do {
        printf("\nMENU\n\n");
        printf("1 - Preencher matriz com aleatórios\n");
        printf("2 - Maior cada coluna\n");
        printf("3 - Linha ou Coluna com mais repetidos\n");
        printf("0 - Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            preencherMatriz(matriz, M, N);
            imprimirMatriz(matriz, M, N);
            break;
        case 2:
            maiorCadaColuna(matriz, M, N, (int[]) {0});
            break;
        case 3:
            contarRepeticoes(matriz, M, N);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void preencherMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorCadaColuna(int m[][N], int lin, int col, int v[]) {
    for (int j = 0; j < col; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < lin; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void contarRepeticoes(int m[][N], int lin, int col) {
    int maxlinrep = 0;
    int maxcolrep = 0;
    int linmaior = -1;
    int colmaior = -1;
    for (int i = 0; i < lin; i++) {
        int repslin = 0;
        for (int j = 0; j < col; j++) {
            int repeticoes = 0;
            for (int k = 0; k < col; k++) {
                if (m[i][j] == m[i][k] && j != k) {
                    repeticoes++;
                }
            }
            if (repeticoes > 0) {
                repslin++;
            }
        }
        if (repslin > maxlinrep) {
            maxlinrep = repslin;
            linmaior = i;
        }
    }
    for (int j = 0; j < col; j++) {
        int repscol = 0;
        for (int i = 0; i < lin; i++) {
            int repeticoes = 0;
            for (int k = 0; k < lin; k++) {
                if (m[i][j] == m[k][j] && i != k) {
                    repeticoes++;
                }
            }
            if (repeticoes > 0) {
                repscol++;
            }
        }
        if (repscol > maxcolrep) {
            maxcolrep = repscol;
            colmaior = j;
        }
    }
    if (maxlinrep > maxcolrep) {
        printf("\no indice da linha com mais repetições eh: %d \n", maxlinrep-1);
    } else if (maxcolrep > maxlinrep) {
        printf("\no indice da coluna com mais repetições eh: %d \n", maxcolrep-1);
    } else if (maxcolrep == 0 && maxlinrep == 0) {
        printf("nenhuma linha e nenhuma coluna possuem repeticoes");
    } else if(maxcolrep == maxlinrep) {
        printf("\na quantidade de repetições na linha de indice: %d e na coluna de indice: %d sao iguais.\n", maxlinrep-1, maxcolrep-1);
    }
}
