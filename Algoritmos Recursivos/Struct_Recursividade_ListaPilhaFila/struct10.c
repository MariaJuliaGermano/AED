#include <stdio.h>
#include <string.h>

typedef struct {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("\nDepósito de R$ %.2f realizado com sucesso!", valor);
        printf("\nNovo saldo: R$ %.2f\n", conta->saldo);
    } else {
        printf("\nValor inválido para depósito!\n");
    }
}

void sacar(ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("\nSaque de R$ %.2f realizado com sucesso!", valor);
        printf("\nNovo saldo: R$ %.2f\n", conta->saldo);
    } else if (valor <= 0) {
        printf("\nValor inválido para saque!\n");
    } else {
        printf("\nSaldo insuficiente para saque!\n");
    }
}

void exibirSaldo(ContaBancaria conta) {
    printf("\n=== Dados da Conta ===");
    printf("\nTitular: %s", conta.nomeTitular);
    printf("\nNúmero da conta: %d", conta.numeroConta);
    printf("\nSaldo atual: R$ %.2f\n", conta.saldo);
}

int main() {
    ContaBancaria conta;
    int opcao;
    float valor;
    
    printf("=== Cadastro de Conta ===\n");
    printf("Nome do titular: ");
    scanf("%s", conta.nomeTitular);
    
    printf("Número da conta: ");
    scanf("%d", &conta.numeroConta);
    
    conta.saldo = 0.0;
    
    do {
        printf("\n=== Menu Bancário ===\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Consultar Saldo\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("\nValor para depósito: R$ ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
                
            case 2:
                printf("\nValor para saque: R$ ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
                
            case 3:
                exibirSaldo(conta);
                break;
                
            case 4:
                printf("\nEncerrando operações. Obrigado!\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 4);
    
    return 0;
}
