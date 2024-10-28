#include <stdio.h>
#include <string.h>
#include <math.h>

#define TAM_NOME_ESTADO 50
#define TEMP_CHAR 256
#define QTD_ESTADOS 26

struct Estado {
  char nome[TAM_NOME_ESTADO];
  int qtd_veiculos;
  int qtd_acidentes;  
};

void lerStr(char *str, int tam);
void cadastrar_estado(struct Estado *estado);
void cadastrar_estados(struct Estado estados[], int tam);
void imprimir_estado(struct Estado estado, float percentual);
void imprimir_estados(struct Estado estados[], int tam);
float percentual_de_acidentes(struct Estado estados[], int i);
float media_acidentes(struct Estado estados[],int tam);
void maior_e_menor(struct Estado estados[],int tam, int *maior, int *menor);
void imprimir_maior_que_media(struct Estado estados[],int tam, float media);


int main() {
    struct Estado estados[QTD_ESTADOS];
    cadastrar_estados(estados, QTD_ESTADOS);
    int maior,menor;
    imprimir_estados(estados, QTD_ESTADOS);
    maior_e_menor(estados,QTD_ESTADOS,&maior,&menor);
    printf("\nEstado com maior número de acidentes: ");
    imprimir_estado(estados[maior],percentual_de_acidentes(estados,maior));
    printf("\nEstado com menor numero de acidentes: \n");
    imprimir_estado(estados[menor],percentual_de_acidentes(estados,menor));
    float media = media_acidentes(estados,QTD_ESTADOS);
    printf("\nA media de acidentes no pais e de: %.2f acidentes",media);
    printf("\nEstados com o numero de acidentes acima da media do pais: \n");
    imprimir_maior_que_media(estados,QTD_ESTADOS,media);


}

void cadastrar_estado(struct Estado *estado) {
    printf("Digite o nome do estado: ");
    lerStr(estado->nome, TAM_NOME_ESTADO);
    printf("Digite a quantidade de veiculos desse estado: ");
    scanf("%d", &estado->qtd_veiculos);
    getchar();
    printf("Digite a quantidade de acidentes nesse estado: ");
    scanf("%d", &estado->qtd_acidentes);
    getchar();
}

void cadastrar_estados(struct Estado estados[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("\nDados do %dº estado\n", i + 1);
        cadastrar_estado(&estados[i]);
    }
}

void imprimir_estado(struct Estado estado, float percentual) {
    printf("Nome do estado: %s\n", estado.nome);
    printf("Quantidade de veiculos desse estado: %d\n", estado.qtd_veiculos);
    printf("Quantidade de acidentes de transito desse estado: %d\n", estado.qtd_acidentes);
    printf("Percentual de acidentes de transito desse estado: %.2f%%\n", percentual);
}

void imprimir_estados(struct Estado estados[], int tam) {
    for (int i = 0; i < tam; ++i) {
        float percentual = percentual_de_acidentes(estados, i);
        printf("\nDados do %dº estado:\n", i + 1);
        imprimir_estado(estados[i], percentual);
    }
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

float percentual_de_acidentes(struct Estado estados[], int i) {
    if (estados[i].qtd_veiculos == 0) {
        return 0.0;
    }
    return ((float)estados[i].qtd_acidentes / estados[i].qtd_veiculos) * 100;
}

float media_acidentes(struct Estado estados[],int tam) {
    int total_acidentes = 0;
    for(int i = 0; i < tam; ++i) {
        total_acidentes += estados[i].qtd_acidentes;
    }
    return (float)total_acidentes / tam;
}

void maior_e_menor(struct Estado estados[],int tam, int *maior, int *menor) {
    *maior = 0;
    *menor = 0;
    for(int i = 0; i < tam; ++i) {
        if(estados[i].qtd_acidentes > estados[*maior].qtd_acidentes) {
            *maior = i;
        }
        if(estados[i].qtd_acidentes < estados[*menor].qtd_acidentes) {
            *menor = i;
        }
    }
}

void imprimir_maior_que_media(struct Estado estados[],int tam, float media) {
    for(int i = 0; i < tam;++i) {
        if(estados[i].qtd_acidentes > media) {
            float percentual = percentual_de_acidentes(estados,i);
            imprimir_estado(estados[i],percentual);
        }
    }
}