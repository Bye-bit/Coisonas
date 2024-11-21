#include <stdio.h>
#include <string.h>

#define QTD_COMPROMISSOS 2
#define TEMP_CHAR 256
#define TAM_DESC 256

struct Compromisso {
    int hora, minuto, segundo;
    int ano, mes, dia;
    char descricao[TAM_DESC];
};

void lerStr(char *str, int tam);
void ler_compromisso(struct Compromisso *compromisso);
void ler_compromissos(struct Compromisso compromissos[], int tam);
void imprimir_compromisso(struct Compromisso compromisso);
void imprimir_compromissos(struct Compromisso compromissos[], int tam);

int main() {
    struct Compromisso compromissos[QTD_COMPROMISSOS];
    ler_compromissos(compromissos, QTD_COMPROMISSOS);
    imprimir_compromissos(compromissos, QTD_COMPROMISSOS);
    return 0;
}

void ler_compromisso(struct Compromisso *compromisso) {
    printf("DIGITE A DESCRICAO DO SEU COMPROMISSO: \n");
    lerStr(compromisso->descricao, TAM_DESC);
    printf("DIGITE A HORA, MINUTO E SEGUNDO DO COMPROMISSO SEPARADO POR ESPACO: ");
    scanf("%d %d %d", &compromisso->hora, &compromisso->minuto, &compromisso->segundo);
    getchar();
    printf("DIGITE O ANO, O MES E O DIA DO SEU COMPROMISSO SEPARADO POR ESPACO: ");
    scanf("%d %d %d", &compromisso->ano, &compromisso->mes, &compromisso->dia);
    getchar(); 
}

void ler_compromissos(struct Compromisso compromissos[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("\nDADOS DO %dº COMPROMISSO\n", i + 1);
        ler_compromisso(&compromissos[i]);
    }
}

void imprimir_compromisso(struct Compromisso compromisso) {
    printf("DESCRICAO DO COMPROMISSO:\n%s\n", compromisso.descricao);
    printf("DATA DO COMPROMISSO:\nAno: %d\nMes: %d\nDia: %d\n", compromisso.ano, compromisso.mes, compromisso.dia);
    printf("HORARIO DO COMPROMISSO:\nHora: %d\nMinuto: %d\nSegundo: %d\n", compromisso.hora, compromisso.minuto, compromisso.segundo);
}

void imprimir_compromissos(struct Compromisso compromissos[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("\nDADOS DO %dº COMPROMISSO\n", i + 1);
        imprimir_compromisso(compromissos[i]);
    }
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
