#include <stdio.h>
#include <string.h>

#define TAM_NOME 256
#define QTD_PESSOAS 2
#define TAM_ENDERECO 256

struct Pessoa {
 int idade;
 char endereco[TAM_ENDERECO];
 char nome[TAM_NOME];

};
void ler_pessoas(struct Pessoa pessoas[],int tam); 
void lerStr(char *str, int tam);
void imprimir_pessoas(struct Pessoa pessoas[],int tam);

int main() {
    struct Pessoa pessoas[QTD_PESSOAS];
    ler_pessoas(pessoas, QTD_PESSOAS);
    imprimir_pessoas(pessoas,QTD_PESSOAS);
    return 0;
}

void ler_pessoas(struct Pessoa pessoas[],int tam) {
   for(int i = 0 ; i < tam; ++i)
   {
    printf("DIGITE O NOME DA PESSOA: ");
    lerStr(pessoas[i].nome,TAM_NOME);
    printf("DIGITE O ENDERECO DA PESSOA: ");
    lerStr(pessoas[i].endereco,TAM_ENDERECO);
    printf("DIGITE A IDADE DA PESSOA: ");
    scanf("%d",&pessoas[i].idade);
    getchar();
   }

}

void imprimir_pessoas(struct Pessoa pessoas[],int tam) {
    for(int i = 0; i < tam; ++i)
    {
        printf("\nDADOS DA %d PESSOA\n",i+1);
        printf("IDADE: %d\n",pessoas[i].idade);
        printf("NOME: %s\n",pessoas[i].nome);
        printf("ENDERECO: %s\n",pessoas[i].endereco);
    }
}


void lerStr(char *str, int tam) {
    fgets(str,tam,stdin);
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n')
    {
        str[len-1] = '\0';
    }
}
