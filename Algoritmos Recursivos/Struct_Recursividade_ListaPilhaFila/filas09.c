#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int itens[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int isEmpty(Fila *f) {
    return f->tamanho == 0;
}

int esta_cheia(Fila *f) {
    return f->tamanho == MAX_SIZE;
}

void enqueue(Fila *f, int valor) {
    if (esta_cheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    
    f->fim = (f->fim + 1) % MAX_SIZE;  // Implementação circular
    f->itens[f->fim] = valor;
    f->tamanho++;
    printf("Elemento %d inserido com sucesso!\n", valor);
}

int dequeue(Fila *f) {
    if (isEmpty(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    
    int valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_SIZE;  // Implementação circular
    f->tamanho--;
    printf("Elemento %d removido com sucesso!\n", valor);
    return valor;
}

void front(Fila *f) {
    if (isEmpty(f)) {
        printf("Erro: Fila vazia!\n");
        return;
    }
    printf("Primeiro elemento da fila: %d\n", f->itens[f->inicio]);
}

void exibir_fila(Fila *f) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila: ");
    int i;
    int pos = f->inicio;
    for (i = 0; i < f->tamanho; i++) {
        printf("%d", f->itens[pos]);
        if (i < f->tamanho - 1) {
            printf(" <- ");
        }
        pos = (pos + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializar_fila(&fila);
    int opcao, valor;
    
    do {
        printf("\n=== Menu Fila ===\n");
        printf("1. Enqueue (Inserir)\n");
        printf("2. Dequeue (Remover)\n");
        printf("3. Front (Primeiro elemento)\n");
        printf("4. isEmpty (Verificar se está vazia)\n");
        printf("5. Exibir fila\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                enqueue(&fila, valor);
                break;
                
            case 2:
                dequeue(&fila);
                break;
                
            case 3:
                front(&fila);
                break;
                
            case 4:
                if (isEmpty(&fila)) {
                    printf("A fila está vazia!\n");
                } else {
                    printf("A fila não está vazia!\n");
                }
                break;
                
            case 5:
                exibir_fila(&fila);
                break;
                
            case 6:
                printf("Encerrando programa...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 6);
    
    return 0;
}