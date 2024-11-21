#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 2
#define TAM_NOME_ALUNO 50

struct Aluno{
int matricula;
int nota1;
int nota2;
int nota3;
char nome[TAM_NOME_ALUNO];
};

void ler_alunos(struct Aluno alunos[],int tam);
void maior_nota_1aprova(struct Aluno alunos[],int tam);
void lerStr(char *str, int tam);
void maior_media_geral(struct Aluno alunos[],int tam);
void menor_media_geral(struct Aluno alunos[],int tam);

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    ler_alunos(alunos,QTD_ALUNOS);
    maior_nota_1aprova(alunos,QTD_ALUNOS);
    maior_media_geral(alunos,QTD_ALUNOS);
    menor_media_geral(alunos,QTD_ALUNOS);
    imprimir_alunos(alunos,QTD_ALUNOS);
    return 0;
}


void ler_alunos(struct Aluno alunos[],int tam) {
    for(int i = 0; i< tam; ++i)
    {
        printf("\nDADOS DO %d ALUNO\n",i+1);
        printf("DIGITE O NOME DO ALUNO: ");
        lerStr(alunos[i].nome,TAM_NOME_ALUNO);
        printf("DIGITE A MATRICULA DO ALUNO: ");
        scanf("%d",&alunos[i].matricula);
        getchar();
        printf("DIGITE A PRIMEIRA NOTA DO ALUNO: ");
        scanf("%d",&alunos[i].nota1);
        getchar();
        printf("DIGITE A SEGUNDA NOTA DO ALUNO: ");
        scanf("%d",&alunos[i].nota2);
        getchar();
        printf("DIGITE A TERCEIRA NOTA DO ALUNO: ");
        scanf("%d",&alunos[i].nota3);
        getchar();
    }
}


void maior_nota_1aprova(struct Aluno alunos[],int tam) {
    int maior = alunos[0].nota1;
    int pos = 0;
    for(int i = 0; i < tam; ++i)
    {
        if(alunos[i].nota1 > maior)
        {
            maior = alunos[i].nota1;
            pos = i;
        }
    }
    printf("O ALUNO COM A MAIOR NOTA FOI %s COM %d PONTOS\n",alunos[pos].nome,maior);
}

void maior_media_geral(struct Aluno alunos[],int tam) {
    float maior_media = 0.0;
    int pos = 0;
    for(int i = 0; i < tam; ++i)
    {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;
        
        if(media > maior_media)
        {
            maior_media = media;
            pos = i;
        }
    }
    printf("O ALUNO COM A MAIOR MEDIA GERAL FOi %s COM %f DE MEDIA\n",alunos[pos].nome,maior_media);
}

void menor_media_geral(struct Aluno alunos[],int tam) {
    float menor_media = 10.0;
    int pos = 0;
    for(int i = 0; i < tam; ++i)
    {
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;
        
        if(media < menor_media)
        {
            menor_media = media;
            pos = i;
        }
    }
    printf("O ALUNO COM A MENOR MEDIA GERAL FOi %s COM %f DE MEDIA\n",alunos[pos].nome,menor_media);
}

void imprimir_alunos(struct Aluno alunos[], int tam) {
    float media;
    for(int i = 0; i < tam; ++i)
    {
        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3.0;
        printf("\nDADOS DO %d ALUNO\n", i + 1);
        printf("NOME: %s\n", alunos[i].nome);
        printf("MATRICULA: %d\n", alunos[i].matricula);
        printf("NOTA DA PRIMEIRA PROVA: %d\n", alunos[i].nota1);
        printf("NOTA DA SEGUNDA PROVA: %d\n", alunos[i].nota2);
        printf("NOTA DA TERCEIRA PROVA: %d\n", alunos[i].nota3);
        if(media >= 6.0)
        {
            printf("ALUNO APROVADO COM %f DE MEDIA\n", media);
        } 
        else 
        {
            printf("ALUNO REPROVADO COM %f DE MEDIA\n", media);
        }
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

