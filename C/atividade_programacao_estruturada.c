#include <stdio.h>

void imprimir_numeros() {
    for (int i = 1; i <= 100; i++) {
        if (i == 100) {
            printf("%d\n", i);
        } else {
            printf("%d, ", i);
        }
    }
}

void somatorio_impares() {
    int soma = 0;
    for (int i = 11; i < 1000; i += 2) {
        soma += i;
    }
    printf("Somatório dos números ímpares entre 10 e 1000: %d\n", soma);
}

void imprimir_multiplos_3() {
    int count = 0;
    for (int i = 1; i <= 200; i++) {
        if (i % 3 == 0 && i % 10 != 3) {
            if (count == 0) {
                printf("%d", i);
                count++;
            } else {
                printf(", %d", i);
            }
        }
    }
    printf("\n");
}

int main() {
    imprimir_numeros();
    somatorio_impares();
    imprimir_multiplos_3();

    return 0;
}
