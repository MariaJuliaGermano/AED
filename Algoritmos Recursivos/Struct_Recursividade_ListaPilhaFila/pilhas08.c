#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int itens[MAX_SIZE];
    int topo;
} Pilha;

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int isEmpty(Pilha *p) {
    return p->topo == -1;
}

int esta_cheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void push(Pilha *p, int valor) {
    if (esta_cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    int valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

void decimal_para_binario(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    
    Pilha pilha;
    inicializar_pilha(&pilha);
    int numero = decimal;
    
    while (numero > 0) {
        push(&pilha, numero % 2);
        numero = numero / 2;
    }
    
    printf("O número %d em binário é: ", decimal);
    while (!isEmpty(&pilha)) {
        printf("%d", pop(&pilha));
    }
    printf("\n");
}

int validar_entrada(int numero) {
    if (numero < 0) {
        printf("Por favor, digite um número positivo.\n");
        return 0;
    }
    return 1;
}

int main() {
    int numero;
    
    while (1) {
        printf("\n=== Conversor Decimal para Binário ===\n");
        printf("Digite um número decimal positivo (ou -1 para sair): ");
        scanf("%d", &numero);
        
        if (numero == -1) {
            printf("Encerrando programa...\n");
            break;
        }
        
        if (validar_entrada(numero)) {
            decimal_para_binario(numero);
            
            printf("\nProcesso de conversão:\n");
            printf("%d em decimal é convertido dividindo sucessivamente por 2\n", numero);
            printf("e pegando os restos em ordem inversa.\n");
            
            int temp = numero;
            printf("\nDivisões:\n");
            while (temp > 0) {
                printf("%d ÷ 2 = %d, resto = %d\n", temp, temp/2, temp%2);
                temp = temp/2;
            }
        }
    }
    
    return 0;
}