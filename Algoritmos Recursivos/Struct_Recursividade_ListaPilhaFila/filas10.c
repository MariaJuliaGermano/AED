#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  

typedef struct {
    int itens[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void inicializar_fila(FilaCircular *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int isEmpty(FilaCircular *f) {
    return f->tamanho == 0;
}

int esta_cheia(FilaCircular *f) {
    return f->tamanho == MAX_SIZE;
}

void enqueue(FilaCircular *f, int valor) {
    if (esta_cheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    
    f->fim = (f->fim + 1) % MAX_SIZE;
    f->itens[f->fim] = valor;
    f->tamanho++;
    printf("Elemento %d inserido na posição %d\n", valor, f->fim);
}

int dequeue(FilaCircular *f) {
    if (isEmpty(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    
    int valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_SIZE;
    f->tamanho--;
    printf("Elemento %d removido da posição %d\n", valor, (f->inicio - 1 + MAX_SIZE) % MAX_SIZE);
    return valor;
}

void front(FilaCircular *f) {
    if (isEmpty(f)) {
        printf("Erro: Fila vazia!\n");
        return;
    }
    printf("Primeiro elemento da fila: %d (posição %d)\n", f->itens[f->inicio], f->inicio);
}

void exibir_fila(FilaCircular *f) {
    if (isEmpty(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("\nEstado da Fila Circular:\n");
    printf("[ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (f->tamanho > 0 && 
            ((f->inicio <= f->fim && i >= f->inicio && i <= f->fim) ||
             (f->inicio > f->fim && (i >= f->inicio || i <= f->fim)))) {
            printf("\033[32m%d\033[0m ", f->itens[i]); 
        } else {
            printf("_ "); 
        }
    }
    printf("]\n");
    
    printf("  ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i == f->inicio && !isEmpty(f)) {
            printf("I "); 
        } else if (i == f->fim && !isEmpty(f)) {
            printf("F "); 
        } else {
            printf("  ");
        }
    }
    printf("\n");
    
    printf("Início: %d, Fim: %d, Tamanho: %d\n", f->inicio, f->fim, f->tamanho);
}

void exibir_info(FilaCircular *f) {
    printf("\nInformações da Fila Circular:\n");
    printf("Capacidade total: %d\n", MAX_SIZE);
    printf("Elementos ocupados: %d\n", f->tamanho);
    printf("Espaços livres: %d\n", MAX_SIZE - f->tamanho);
    printf("Posição do início: %d\n", f->inicio);
    printf("Posição do fim: %d\n", f->fim);
}

int main() {
    FilaCircular fila;
    inicializar_fila(&fila);
    int opcao, valor;
    
    do {
        printf("\n=== Menu Fila Circular ===\n");
        printf("1. Enqueue (Inserir)\n");
        printf("2. Dequeue (Remover)\n");
        printf("3. Front (Primeiro elemento)\n");
        printf("4. Exibir fila\n");
        printf("5. Exibir informações\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                enqueue(&fila, valor);
                exibir_fila(&fila);
                break;
                
            case 2:
                dequeue(&fila);
                exibir_fila(&fila);
                break;
                
            case 3:
                front(&fila);
                break;
                
            case 4:
                exibir_fila(&fila);
                break;
                
            case 5:
                exibir_info(&fila);
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