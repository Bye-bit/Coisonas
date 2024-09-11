#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define qtdlinhas 100
#define qtdcolunas 100

void ler_matriz(int mat[][qtdcolunas], int lin, int col);
void preenchermatriz(int mat[][qtdcolunas],int lin, int col);
void imprimirmatriz(int mat[][qtdcolunas],int lin,int col);
int lerDentroIntervalo(int min, int max);
void quantidade_impar(int mat[][qtdcolunas],int lin, int col);
void procurarnumero(int mat[][qtdcolunas],int lin,int col);
void somadevalores(int mat[][qtdcolunas], int lin, int col);
void mediatodos (int mat[][qtdcolunas],int lin, int col);
void media_linhas(int mat[][qtdcolunas], int lin, int col);

int main () {
    int qtdLinhas, qtdColunas;
    int matriz[qtdlinhas][qtdcolunas];
    printf("digite a quantidade de linhas (1-%d): ",qtdlinhas);
    qtdLinhas = lerDentroIntervalo(1,qtdlinhas);
    printf("digite a quantidade de colunas (1-%d): ",qtdcolunas);
    qtdColunas = lerDentroIntervalo(1, qtdcolunas);
    preenchermatriz(matriz,qtdLinhas,qtdColunas);
    imprimirmatriz(matriz,qtdLinhas,qtdColunas);
    quantidade_impar(matriz,qtdLinhas,qtdColunas);
    printf("\n");
    procurarnumero(matriz,qtdLinhas,qtdColunas);
    printf("A soma de todos os valores da matriz e: ");
    somadevalores(matriz,qtdLinhas,qtdColunas);
    mediatodos(matriz,qtdLinhas,qtdColunas);
    printf("\n");
    media_linhas(matriz,qtdColunas,qtdLinhas);

    return 0;
}

void ler_matriz(int mat[][qtdcolunas], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void preenchermatriz(int mat[][qtdcolunas],int lin, int col) {
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }    
}

void imprimirmatriz(int mat[][qtdcolunas],int lin,int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
}

int lerDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor invalido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}


void quantidade_impar(int mat[][qtdcolunas],int lin, int col) {
    int impares = 0;
    for (int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            if (mat[i][j] % 2 != 0) {
                impares++;
            }
        }
    }

    printf("A quantidade de numeros impares e: %d", impares);
}


void procurarnumero(int mat[][qtdcolunas], int lin, int col) {
    int numero;
    int encontrado = 0;
    printf("Digite o número que deseja procurar: ");
    scanf("%d", &numero);

    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == numero) {
                printf("Número %d encontrado na linha %d, coluna %d\n", numero, i+1, j+1);
                encontrado = 1;
            }
        }
    }
    if(!encontrado) {
    printf("O numero nao foi encontrado");       
    }
}

void somadevalores(int mat[][qtdcolunas], int lin, int col) {
    int soma = 0;
    for(int i = 0; i < lin; ++i) {
        for(int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
    }
    printf("%d \n",soma);
}

void mediatodos (int mat[qtdlinhas][qtdcolunas],int lin, int col) {
    int somatodos = 0;
    int total_elementos = lin * col;
    for(int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            somatodos += mat[i][j];
            
        }
    }
    float mediatodos = (float)somatodos/total_elementos;
    printf("Media total de todos os elementos da matriz e: %.2f",mediatodos);
}

void media_linhas(int mat[][qtdcolunas], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        int soma = 0;
        for (int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
        float media = (float)soma / col;
        printf("Media da linha %d: %.2f\n", i+1, media);
    }
}
