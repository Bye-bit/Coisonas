#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 5
#define TAM_NOME_ALUNO 256
#define TAM_NOME_CURSO_ALUNO 256

struct Aluno {
    int matricula;
    char curso[TAM_NOME_CURSO_ALUNO];
    char nome[TAM_NOME_ALUNO];
};

void ler_alunos(struct Aluno alunos[],int tam);
void imprimir_alunos(struct Aluno alunos[],int tam);
void lerStr(char *str, int tam);

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    ler_alunos(alunos,QTD_ALUNOS);
    imprimir_alunos(alunos,QTD_ALUNOS);
    return 0;
}




 void ler_alunos(struct Aluno alunos[],int tam) {
    for(int i = 0; i < tam; ++i)
    {
        printf("\nDADOS DO %d ALUNO\n",i+1);
        printf("DIGITE O NOME DO ALUNO: ");
        lerStr(alunos[i].nome,TAM_NOME_ALUNO);
        printf("DIGITE A MATRICULA DO ALUNO: ");
        scanf("%d",&alunos[i].matricula);
        getchar();
        printf("DIGITE O CURSO DO ALUNO: ");
        lerStr(alunos[i].curso,TAM_NOME_CURSO_ALUNO);
    }
}


void imprimir_alunos(struct Aluno alunos[],int tam) {
    for(int i = 0; i < tam; ++i)
    {
        printf("\nDADOS DO %d ALUNO\n",i+1);
        printf("NOME: %s\n",alunos[i].nome);
        printf("MATRICULA: %d\n",alunos[i].matricula);
        printf("CURSO: %s\n",alunos[i].curso); 
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