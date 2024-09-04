#include <stdio.h>

int BuscaBinaria(int v[], int tam, int valor) {
    int esq = 0, dir = tam -1, meio;
    while( esq <= dir ) {
        meio = (esq + dir) / 2;
        if (valor < v[meio]) {
            dir = meio - 1;
        } else if ( valor > v[meio]) {
            esq = meio + 1;
        } else {
            return meio;
        }
    }
return -1; 
}