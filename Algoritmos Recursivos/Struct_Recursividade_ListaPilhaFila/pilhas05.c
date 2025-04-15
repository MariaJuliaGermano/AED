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
    printf("Elemento %d inserido com sucesso!\n", valor);
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    int valor = p->itens[p->topo];
    p->topo--;
    printf("Elemento %d removido com sucesso!\n", valor);
    return valor;
}

void top(Pilha *p) {
    if (isEmpty(p)) {
        printf("Erro: Pilha vazia!\n");
        return;
    }
    printf("Elemento do topo: %d\n", p->itens[p->topo]);
}

void exibir_pilha(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d", p->itens[i]);
        if (i < p->topo) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializar_pilha(&pilha);
    int opcao, valor;
    
    do {
        printf("\n=== Menu Pilha ===\n");
        printf("1. Push (Inserir)\n");
        printf("2. Pop (Remover)\n");
        printf("3. Top (Elemento do topo)\n");
        printf("4. isEmpty (Verificar se está vazia)\n");
        printf("5. Exibir pilha\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(&pilha, valor);
                break;
                
            case 2:
                pop(&pilha);
                break;
                
            case 3:
                top(&pilha);
                break;
                
            case 4:
                if (isEmpty(&pilha)) {
                    printf("A pilha está vazia!\n");
                } else {
                    printf("A pilha não está vazia!\n");
                }
                break;
                
            case 5:
                exibir_pilha(&pilha);
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