#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define QTD_PESSOAS 3


struct Pessoa{
    int idade;
    char nome[TAM_NOME];
};

void imprimir_pessoas(struct Pessoa pessoas[], int tam);
void lerStr(char *str, int tam);
void ler_pessoa(struct Pessoa pessoas[],int tam);
void bubblesort(struct Pessoa pessoas[], int tam);


int main() {
    struct Pessoa pessoas[QTD_PESSOAS];
    ler_pessoa(pessoas,QTD_PESSOAS);
    imprimir_pessoas(pessoas,QTD_PESSOAS);
    bubblesort(pessoas,QTD_PESSOAS);
    printf("PESSOAS ORDENADAS EM ORDEM ALFABETICA: \n");
    imprimir_pessoas(pessoas,QTD_PESSOAS);
    return 0;
}


void lerStr(char *str, int tam) {
    fgets(str,tam,stdin);
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n')
    {
        str[len-1] = '\0';
    }
}


void ler_pessoa(struct Pessoa pessoas[],int tam) {
    for(int i = 0; i < tam; ++i)
    {
        printf("\nDADOS DA %d PESSOA\n",i+1);
        printf("DIGITE O NOME DA PESSOA: ");
        lerStr(pessoas[i].nome,TAM_NOME);
        printf("DIGITE A IDADE DA PESSOA: ");
        scanf("%d",&pessoas[i].idade);
        getchar();

    }
}


void imprimir_pessoas(struct Pessoa pessoas[], int tam) {
    for(int i = 0; i < tam;++i)
    {
        printf("\nDADOS DA %d PESSOA\n",i+1);
        printf("NOME DA PESSOA: %s\n",pessoas[i].nome);
        printf("IDADE DA PESSOA: %d\n",pessoas[i].idade);
    }
}


void bubblesort(struct Pessoa pessoas[], int tam) {
    struct Pessoa aux;
    int troca = 1;
    while(troca) {
        troca = 0;
        for(int i = 0; i < tam-1;++i)
        {
            if(strcmp(pessoas[i].nome, pessoas[i+1].nome) > 0 )
            {
                aux = pessoas[i];
                pessoas[i] = pessoas[i+1];
                pessoas[i+1] = aux;
                troca = 1;
            }
        }
        tam--;
    }
}