#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 200
#define QTD_CONTAS 100

struct ContaCorrente {
    int numConta, telefone, cpf;
    float saldo;
    char nome[TAM_NOME];
};

struct ContaPoupanca {
    int numConta, telefone, cpf;
    float saldo;
    char nome[TAM_NOME];
};

void lerString(char *str, int tam);
void preencherEstruturas(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam);
int buscarConta(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo);
void cadastrarNovaConta(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo);
void consultarSaldo(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo);
void realizarDeposito(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo);
void realizarSaque(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo);
void exibirContas(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int tipo);

int main() {
    struct ContaCorrente cc[QTD_CONTAS];
    struct ContaPoupanca cp[QTD_CONTAS];
    int opcao, numeroConta, tipo;
    preencherEstruturas(cc, cp, QTD_CONTAS);
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Buscar conta.\n");
        printf("2 - Cadastrar nova conta.\n");
        printf("3 - Consultar saldo de uma conta.\n");
        printf("4 - Depósito em uma conta.\n");
        printf("5 - Saque em uma conta.\n");
        printf("6 - Exibir dados das contas.\n");
        printf("0 - Encerrar programa.\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("\nSelecione uma das opções:\n(1)Conta Corrente  (2)Conta Poupança\n");
            scanf("%d", &tipo);
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            int indice = buscarConta(cc, cp, QTD_CONTAS, numeroConta, tipo);
            if(indice >=  0) {
                printf("Conta encontrada na posição %d.\n\n", indice+1);
            } else if(indice == -1) {
                printf("O cadastro está vazio.\n\n");
            } else if(indice == -2) {
                printf("Conta não encontrada no cadastro.\n\n");
            }
            break;
        case 2:
            printf("\nSelecione uma opção:\n(1)Conta Corrente  (2)Conta Poupança\n");
            scanf("%d", &tipo);
            printf("Número da nova conta: ");
            scanf("%d", &numeroConta);
            cadastrarNovaConta(cc, cp, QTD_CONTAS, numeroConta, tipo);
            break;
        case 3:
            printf("\nSelecione uma opção:\n(1)Conta Corrente  (2)Conta Poupança\n");
            scanf("%d", &tipo);
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            consultarSaldo(cc, cp, QTD_CONTAS, numeroConta, tipo);
            break;
        case 4:
            printf("\nSelecione uma opção:\n(1)Conta Corrente  (2)Conta Poupança\n");
            scanf("%d", &tipo);
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            realizarDeposito(cc, cp, QTD_CONTAS, numeroConta, tipo);
            break;
        case 5:
            printf("\nSelecione uma opção:\n(1)Conta Corrente  (2)Conta Poupança\n");
            scanf("%d", &tipo);
            printf("Número da conta: ");
            scanf("%d", &numeroConta);
            realizarSaque(cc, cp, QTD_CONTAS, numeroConta, tipo);
            break;
        case 6:
            printf("\nSelecione uma opção:\n(1)Conta Corrente  (2)Conta Poupança\n");
            scanf("%d", &tipo);
            exibirContas(cc, cp, QTD_CONTAS, tipo);
            break;
        case 0:
            printf("\nEncerrando o programa.\n\n");
            break;
        default:
            printf("\nOpção inválida.\n\n");
            break;
        }
    } while(opcao != 0);
    return 0;
}

void lerString(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void preencherEstruturas(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam) {
    for(int i = 0; i < tam; ++i) {
        cc[i].numConta = 0;
        cc[i].telefone = 0;
        cc[i].cpf = 0;
        cc[i].saldo = 0;
        cp[i].numConta = 0;
        cp[i].telefone = 0;
        cp[i].cpf = 0;
        cp[i].saldo = 0;
    }
}

int buscarConta(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo) {
    int verif = -1;
    switch (tipo) {
        case 1:
            for (int i = 0; i < tam; ++i) {
                if (conta == cc[i].numConta) {
                    return i;
                } else if (cc[i].numConta != 0) {
                    verif = -2;
                }
            }
            break;
        case 2:
            for (int i = 0; i < tam; ++i) {
                if (conta == cp[i].numConta) {
                    return i;
                } else if (cp[i].numConta != 0) {
                    verif = -2;
                }
            }
            break;
    }
    return verif;
}

void cadastrarNovaConta(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo) {
    int verif = 0, i;
    char temp[TAM_NOME];
    int igual = buscarConta(cc, cp, QTD_CONTAS, conta, tipo);
    if(igual >= 0) {
        printf("Este número já consta no cadastro. Tente novamente.\n");
        return;
    }
    switch(tipo)
    {
    case 1:
        for(i = 0; i < tam; ++i) {
            if(cc[i].numConta == 0) {
                verif = 1;
                cc[i].numConta = conta;
                lerString(temp, TAM_NOME);
                printf("Digite o nome completo: ");
                lerString(cc[i].nome, TAM_NOME);
                printf("Digite o CPF (somente números): ");
                scanf("%d", &cc[i].cpf);
                printf("Digite um telefone para contato: ");
                scanf("%d", &cc[i].telefone);
                lerString(temp, TAM_NOME);
                printf("\n");
                break;
            }
        }
        break;
    case 2:
        for(i = 0; i < tam; ++i) {
            if(cp[i].numConta == 0) {
                verif = 1;
                cp[i].numConta = conta;
                lerString(temp, TAM_NOME);
                printf("\nDigite o nome completo: ");
                lerString(cp[i].nome, TAM_NOME);
                printf("\nDigite o CPF (somente números): ");
                scanf("%d", &cp[i].cpf);
                printf("\nDigite um telefone para contato: ");
                scanf("%d", &cp[i].telefone);
                lerString(temp, TAM_NOME);
                printf("\n");
                break;
            }
        }
        break;
    }
    if(!verif) {
        printf("Máximo de cadastros já realizado!\n");
    }
}

void consultarSaldo(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo) {
    int i = buscarConta(cc, cp, QTD_CONTAS, conta, tipo);
    if(i != -1 && i != -2) {
        switch(tipo)
        {
        case 1:
            printf("O saldo da conta é R$%.2f.\n\n", cc[i].saldo);
            break;
        case 2:
            printf("O saldo da conta é R$%.2f.\n\n", cp[i].saldo);
            break;
        }
    } else {
        printf("Conta não cadastrada!\n");
    }
}

void realizarDeposito(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo) {
    float valor;
    int i = buscarConta(cc, cp, QTD_CONTAS, conta, tipo);
    if(i != -1 && i != -2) {
        printf("Qual valor será depositado? ");
        scanf("%f", &valor);
        switch(tipo)
        {
        case 1:
            cc[i].saldo += valor;
            printf("Depósito efetuado!\n\n");
            break;
        case 2:
            cp[i].saldo += valor;
            printf("Depósito efetuado!\n\n");
            break;
        }
    } else {
        printf("Conta não cadastrada!\n\n");
    }
}

void realizarSaque(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int conta, int tipo) {
    float valor;
    int i = buscarConta(cc, cp, QTD_CONTAS, conta, tipo);
    if(i != -1 && i != -2) {
        printf("Qual valor deseja sacar? ");
        scanf("%f", &valor);
        switch(tipo)
        {
        case 1:
            if(valor <= cc[i].saldo) {
                cc[i].saldo -= valor;
                printf("Saque efetuado!\n\n");
            } else {
                printf("Saldo insuficiente!\n\n");
            }
            break;
        case 2:
            if(valor <= cp[i].saldo) {
                cp[i].saldo -= valor;
                printf("Saque efetuado!\n\n");
            } else {
                printf("Saldo insuficiente!\n\n");
            }
            break;
        }
    } else {
        printf("Conta não cadastrada!\n\n");
    }
}

void exibirContas(struct ContaCorrente cc[], struct ContaPoupanca cp[], int tam, int tipo) {
    switch(tipo)
    {
    case 1:
        printf("\nCADASTROS CONTA CORRENTE\n");
        for(int i = 0; i < tam; ++i) {
            if(cc[i].numConta != 0) {
                printf("Número da conta: %d\n", cc[i].numConta);
                printf("Nome: %s\n", cc[i].nome);
                printf("Telefone: %d\n\n", cc[i].telefone);
            }
        }
        break;
    case 2:
        printf("\nCADASTROS CONTA POUPANÇA\n");
        for(int i = 0; i < tam; ++i) {
            if(cp[i].numConta != 0) {
                printf("Número da conta: %d\n", cp[i].numConta);
                printf("Nome: %s\n", cp[i].nome);
                printf("Telefone: %d\n\n", cp[i].telefone);
            }
        }
        break;
    }
}
