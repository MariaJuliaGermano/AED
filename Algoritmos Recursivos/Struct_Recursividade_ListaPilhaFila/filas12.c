#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int itens[MAX_SIZE];
    int inicio;
    int fim;
    int tamanho;
} Fila;

typedef struct {
    int itens[MAX_SIZE];
    int topo;
} Pilha;

void inicializar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_cheia(Fila *f) {
    return f->tamanho == MAX_SIZE;
}

void enfileirar(Fila *f, int valor) {
    if (fila_cheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % MAX_SIZE;
    f->itens[f->fim] = valor;
    f->tamanho++;
}

int desenfileirar(Fila *f) {
    if (fila_vazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1;
    }
    int valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_SIZE;
    f->tamanho--;
    return valor;
}

void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

int pilha_vazia(Pilha *p) {
    return p->topo == -1;
}

int pilha_cheia(Pilha *p) {
    return p->topo == MAX_SIZE - 1;
}

void empilhar(Pilha *p, int valor) {
    if (pilha_cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

int desempilhar(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    int valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

void inverter_fila(Fila *f) {
    Pilha pilha_aux;
    inicializar_pilha(&pilha_aux);
    
    while (!fila_vazia(f)) {
        empilhar(&pilha_aux, desenfileirar(f));
    }
    
    while (!pilha_vazia(&pilha_aux)) {
        enfileirar(f, desempilhar(&pilha_aux));
    }
}

void exibir_fila(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila: ");
    int pos = f->inicio;
    for (int i = 0; i < f->tamanho; i++) {
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
        printf("\n=== Menu ===\n");
        printf("1. Adicionar elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Inverter fila\n");
        printf("4. Exibir fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                printf("Elemento adicionado com sucesso!\n");
                exibir_fila(&fila);
                break;
                
            case 2:
                valor = desenfileirar(&fila);
                if (valor != -1) {
                    printf("Elemento removido: %d\n", valor);
                    exibir_fila(&fila);
                }
                break;
                
            case 3:
                printf("Fila original: ");
                exibir_fila(&fila);
                inverter_fila(&fila);
                printf("Fila invertida: ");
                exibir_fila(&fila);
                break;
                
            case 4:
                exibir_fila(&fila);
                break;
                
            case 5:
                printf("Encerrando programa...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 5);
    
    return 0;
}