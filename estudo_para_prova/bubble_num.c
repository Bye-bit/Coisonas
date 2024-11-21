#include <stdio.h>


#define VET_TAM 3


int main() {
    int v[VET_TAM];
    preencher_vetor(v,VET_TAM);
    imprimir_vetor(v,VET_TAM);
    bubblesort(v,VET_TAM);
    printf("VETOR ORDENADO: \n");
    imprimir_vetor(v,VET_TAM);







    return 0;
}






bubblesort(int v[], int tam) {
    int i,aux,troca = 1;
    while(troca) {
        troca = 0;
        for(int i = 0; i < tam-1; ++i) {
            if(v[i] > v[i+1]) {
                troca = 1;
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;

            }
        }
        tam--;
    }
}

void preencher_vetor(int v[], int tam) {
    for(int i = 0; i < tam; ++i)
    {
        int elemento = 0;
        printf("DIGITE O %d ELEMENTO DO VETOR: ",i+1);
        scanf("%d",&elemento);
        getchar();
        v[i] = elemento;
    }
}


void imprimir_vetor(int v[],int tam) {
    for(int i = 0; i < tam; ++i)
    {
        printf("[%d] ",v[i]);
    }
    printf("\n");
}