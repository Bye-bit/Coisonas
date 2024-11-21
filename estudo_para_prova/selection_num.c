#include <stdio.h>


#define TAM_VET 5


int main() {
    int v[TAM_VET];
}



void preencher_vetor(int v[],int tam) {
    for(int i = 0; i < tam;++i)
    {
        int elemento = 0;
        printf("DIGITE O %d ELEMENTO DO VETOR.",i+1);
        scanf("%d",&elemento);
        v[i] = elemento;
    }
}