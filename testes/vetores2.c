#include <stdio.h>
#define MAX 6

void preenchervetor(int v[MAX]);
void printvetor(int v[MAX]) ;

int main() {
    int v[MAX];
    preenchervetor(v);
    printvetor(v);
}


void preenchervetor(int v[MAX]) {
    for(int i = 0; i < MAX; ++i) {
        printf("digite um valor para compor o vetor: ");
        scanf("%d",&v[i]);
    }
    printf("\n");
}

void printvetor(int v[MAX]) {
    for(int i = 0; i < MAX; ++i) {
        printf("%d ",v[i]);
    }
    printf("\n");
}