#include <stdio.h>

#define TAM_NOME 50

struct Pessoa
{
    char nome[TAM_NOME];
    int idade;
    int peso;
    int altura;
};


int main()
{
    struct Pessoa Pessoa;
    {
        printf("Digite O Seu  Nome: \n");
        lerStr(Pessoa.nome,TAM_NOME);
        printf("Digite A Sua Idade: \n");
        scanf("%d",&Pessoa.idade);
        printf("Digite O Seu Peso: \n");
        scanf("%d",&Pessoa.peso);
        printf("Digite A Sua Altura Em Centimetros: \n");
        scanf("%d",&Pessoa.altura);

    }
    printf("Nome: %s",Pessoa.nome);
    printf("Altura: %dcm",Pessoa.altura);
    printf("Idade: %d",Pessoa.idade);
    printf("Peso: %dkg",Pessoa.peso);
    calcularIMC(Pessoa);
}

void lerStr(char *str, int tam)
{
fgets(str,tam,stdin);
int len = strlen(str);
if (str[len-1]== '\n')
{
    str[len-1] == '\0';
}
}

double calcularIMC(struct Pessoa p)
{
return p.peso / (p.altura*p.altura);
}
//structs são legaizinhos !
