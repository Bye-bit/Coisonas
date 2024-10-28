#include <stdio.h>
#include <string.h>

#define TAM_ESTOQUE 40
#define TAM_NOME_PRODUTO 50

struct Produto {
    int codigo;
    char descricao[TAM_NOME_PRODUTO];
    float valor_unitario;
    int quantidade_estoque;
};

void cadastrar_produto(struct Produto estoque[], int *total_produtos);
void alterar_valor(struct Produto estoque[], int total_produtos, int codigo);
float consultar_valor(struct Produto estoque[], int total_produtos, int codigo);
int consultar_estoque(struct Produto estoque[], int total_produtos, int codigo);
void realizar_venda(struct Produto estoque[], int total_produtos, int codigo, int quantidade);
void atualizar_estoque(struct Produto estoque[], int total_produtos, int codigo, int nova_quantidade);
void exibir_todos_produtos(struct Produto estoque[], int total_produtos);
void exibir_produtos_estoque_zero(struct Produto estoque[], int total_produtos);

int main() {
    struct Produto estoque[TAM_ESTOQUE];
    int total_produtos = 0;
    int opcao, codigo, quantidade;
    float valor;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Alterar Valor Unitário\n");
        printf("3. Consultar Valor Unitário\n");
        printf("4. Consultar Quantidade em Estoque\n");
        printf("5. Realizar Venda\n");
        printf("6. Atualizar Quantidade em Estoque\n");
        printf("7. Exibir Todos os Produtos\n");
        printf("8. Exibir Produtos com Estoque Zero\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_produto(estoque, &total_produtos);
                break;
            case 2:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                alterar_valor(estoque, total_produtos, codigo);
                break;
            case 3:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                valor = consultar_valor(estoque, total_produtos, codigo);
                if (valor != -1) {
                    printf("Valor unitário do produto: %.2f\n", valor);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;
            case 4:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                quantidade = consultar_estoque(estoque, total_produtos, codigo);
                if (quantidade != -1) {
                    printf("Quantidade em estoque: %d\n", quantidade);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;
            case 5:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade desejada: ");
                scanf("%d", &quantidade);
                realizar_venda(estoque, total_produtos, codigo, quantidade);
                break;
            case 6:
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                printf("Digite a nova quantidade em estoque: ");
                scanf("%d", &quantidade);
                atualizar_estoque(estoque, total_produtos, codigo, quantidade);
                break;
            case 7:
                exibir_todos_produtos(estoque, total_produtos);
                break;
            case 8:
                exibir_produtos_estoque_zero(estoque, total_produtos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

void cadastrar_produto(struct Produto estoque[], int *total_produtos) {
    if (*total_produtos >= TAM_ESTOQUE) {
        printf("Estoque cheio! Não é possível cadastrar novos produtos.\n");
        return;
    }

    printf("Digite o código do produto: ");
    scanf("%d", &estoque[*total_produtos].codigo);
    getchar();

    printf("Digite a descrição do produto: ");
    fgets(estoque[*total_produtos].descricao, 100, stdin);
    estoque[*total_produtos].descricao[strcspn(estoque[*total_produtos].descricao, "\n")] = '\0';

    printf("Digite o valor unitário do produto: ");
    scanf("%f", &estoque[*total_produtos].valor_unitario);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &estoque[*total_produtos].quantidade_estoque);

    (*total_produtos)++;

    printf("Produto cadastrado com sucesso!\n");
}


void alterar_valor(struct Produto estoque[], int total_produtos, int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Digite o novo valor unitário: ");
            scanf("%f", &estoque[i].valor_unitario);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

float consultar_valor(struct Produto estoque[], int total_produtos, int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            return estoque[i].valor_unitario;
        }
    }
    return -1;
}

int consultar_estoque(struct Produto estoque[], int total_produtos, int codigo) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            return estoque[i].quantidade_estoque;
        }
    }
    return -1;
}

void realizar_venda(struct Produto estoque[], int total_produtos, int codigo, int quantidade) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            if (estoque[i].quantidade_estoque == 0) {
                printf("Produto com estoque zero.\n");
            } else if (quantidade <= estoque[i].quantidade_estoque) {
                float valor_total = estoque[i].valor_unitario * quantidade;
                estoque[i].quantidade_estoque -= quantidade;
                printf("Venda realizada. Valor a pagar: R$ %.2f\n", valor_total);
            } else {
                printf("Estoque insuficiente. Deseja comprar toda a quantidade disponível? (1-Sim / 0-Não): ");
                int escolha;
                scanf("%d", &escolha);
                if (escolha == 1) {
                    float valor_total = estoque[i].valor_unitario * estoque[i].quantidade_estoque;
                    estoque[i].quantidade_estoque = 0;
                    printf("Venda realizada. Valor a pagar: R$ %.2f\n", valor_total);
                } else {
                    printf("Venda não realizada.\n");
                }
            }
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void atualizar_estoque(struct Produto estoque[], int total_produtos, int codigo, int nova_quantidade) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            estoque[i].quantidade_estoque = nova_quantidade;
            printf("Quantidade atualizada.\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void exibir_todos_produtos(struct Produto estoque[], int total_produtos) {
    for (int i = 0; i < total_produtos; i++) {
        printf("Código: %d | Descrição: %s\n", estoque[i].codigo, estoque[i].descricao);
    }
}

void exibir_produtos_estoque_zero(struct Produto estoque[], int total_produtos) {
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].quantidade_estoque == 0) {
            printf("Código: %d | Descrição: %s\n", estoque[i].codigo, estoque[i].descricao);
        }
    }
}
