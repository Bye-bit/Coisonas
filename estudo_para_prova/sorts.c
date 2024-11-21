#include <stdio.h>
#include <string.h>


#define TAM_VET 3
#define QTD_PESSOAS 3
#define TAM_NOME 50


struct Pessoa{
    int idade;
    char nome[TAM_NOME];
};

void lerStr(char *str, int tam);
void ler_vetor(int v[],int tam);
void imprimir_vetor(int v[], int tam);
void ler_struct(struct Pessoa pessoas[], int tam);
void imprimir_struct(struct Pessoa pessoas[],int tam);
void num_bubblesort(int v[], int tam);
void struct_bubblesort(struct Pessoa pessoas[], int tam);
void num_selectionsort(int v[], int tam);
void struct_selectionsort(struct Pessoa pessoas[],int tam);

int main() {
    struct Pessoa pessoas[QTD_PESSOAS];
    int v[TAM_VET];
    int opcao;
    do
    {
      printf("\n");
      printf("1.-Preencher Um vetor.\n");
      printf("2.-Preencher Um struct.\n");
      printf("3.-Imprimir um vetor.\n");
      printf("4.-Imprimir um struct.\n");
      printf("5.-Ordenar Vetor De forma crescente.(bubbleSort)\n");
      printf("6.-Ordenar um struct em ordem alfabetica.(bubbleSort)\n");
      printf("7.-Ordenar Em ordem Crescente(SelecitonSort).\n");
      printf("8.-Ordenar Em ordem Alfabeteica(SelectionSort).\n");
      printf("0.-Sair do programa.\n");
      scanf("%d",&opcao);
      getchar();
      switch (opcao)
      {
        case 1:
        ler_vetor(v,TAM_VET);
        break;
        case 2:
        ler_struct(pessoas,QTD_PESSOAS);
        break;
        case 3:
        imprimir_vetor(v,TAM_VET);
        break;
        case 4:
        imprimir_struct(pessoas,QTD_PESSOAS);
        break;
        case 5:
        num_bubblesort(v,TAM_VET);
        printf("Vetor organizado com bubblesort.");
        break;
        case 6:
        struct_bubblesort(pessoas,QTD_PESSOAS);
        printf("Struct organizado em ordem alfabetica com bubblesort.");
        break;
        case 7: num_selectionsort(v,TAM_VET);
        printf("Vetor organizado com sucesso com selectionsort");
        break;
        case 8: struct_selectionsort(pessoas,QTD_PESSOAS);\
        printf("Struct organizado com sucesso com selectionsort");
        break;
        case 0:
        printf("Saindo do programa...");
        break;
        default:
        break;
      }

    } while (opcao != 0);
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


void ler_vetor(int v[],int tam) {
    for(int i = 0; i < tam; ++i)
    {
        int elemento = 0;
        printf("DIGITE O %d ELEMENTO DO VETOR: \n",i+1);
        scanf("%d",&elemento);
        v[i] = elemento;
    }
    printf("\n");
}


void imprimir_vetor(int v[], int tam) {
    for(int i = 0; i < tam; ++i)
    {
        printf("[%d] ",v[i]);
    }
    printf("\n");
}


void ler_struct(struct Pessoa pessoas[], int tam) {
    for(int i = 0; i < tam; ++i)
    {
    printf("\n DIGITE OS DADOS DA %d PESSOA\n",i+1);
    printf("DIGITE A IDADE DA PESSOA: ");
    scanf("%d",&pessoas[i].idade);
    getchar();
    printf("DIGITE O NOME DA PESSOA: ");
    lerStr(pessoas[i].nome,TAM_NOME);
    }    
}


void imprimir_struct(struct Pessoa pessoas[],int tam) {
    for(int i = 0; i < tam; ++i) {
        printf("\nDADOS DA %d PESSOA\n",i+1);
        printf("NOME: %s\n",pessoas[i].nome);
        printf("IDADE: %d\n",pessoas[i].idade);
    }
}


void num_bubblesort(int v[], int tam) {
    int troca = 1;
    int aux;
    while(troca)
    {
        troca = 0;
        for(int i = 0; i < tam-1;++i)
        {
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = 1;
            }
        }
        tam--;
    }
}


void struct_bubblesort(struct Pessoa pessoas[], int tam) {
    struct Pessoa aux;
    int troca = 1;
    while(troca)
    {
        troca=0;
        for(int i = 0; i < tam-1; ++i)
        {
            if(strcmp(pessoas[i].nome, pessoas[i+1].nome) > 0)
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


void num_selectionsort(int v[], int tam) {
int i,j,menor;
    for(int i = 0; i < tam;++i)
    {
        menor = i;
        for(int j = i+1; j < tam; ++j)
        {
            if(v[j] < v[menor])
            {
                menor = j;
            }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void struct_selectionsort(struct Pessoa pessoas[],int tam) {
    int i, j, menor;
    struct Pessoa aux;
    for(int i = 0; i < tam; ++i)
    {
        menor = i;
        for(int j = i+1; j < tam; ++j)
        {
            if(strcmp(pessoas[j].nome,pessoas[menor].nome) < 0)
            {
                menor = j;
            }
        }
        aux = pessoas[i];
        pessoas[i] = pessoas[menor];
        pessoas[menor] = aux;
    }
}

//void num_insetionsort(int v[], int tam) {
//    int i;
//    for(int i = 1; i < tam; ++i) {
//        int aux, j = i;
//        aux = v[j];
//        while(j>0 && aux < v[j-1])
//        {
//            v[j] = v[j-1];
//            j--;
//        }
//        v[j] = aux;
//    }
//}