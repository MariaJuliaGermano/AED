#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char itens[MAX_SIZE];
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

void push(Pilha *p, char valor) {
    if (esta_cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

char pop(Pilha *p) {
    if (isEmpty(p)) {
        return '\0';  
    }
    char valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

void inverter_string(char *str) {
    Pilha pilha;
    inicializar_pilha(&pilha);
    int tamanho = strlen(str);
    
    for (int i = 0; i < tamanho; i++) {
        push(&pilha, str[i]);
    }
    
    for (int i = 0; i < tamanho; i++) {
        str[i] = pop(&pilha);
    }
}

void exibir_resultado(char *original, char *invertida) {
    printf("\nString original: %s", original);
    printf("\nString invertida: %s\n", invertida);
}

int main() {
    char str_original[MAX_SIZE];
    char str_invertida[MAX_SIZE];
    
    while (1) {
        printf("\n=== Inversor de Strings ===\n");
        printf("Digite uma string (ou 'sair' para encerrar): ");
        
        fflush(stdin);
        
        fgets(str_original, MAX_SIZE, stdin);
        
        str_original[strcspn(str_original, "\n")] = 0;
        
        if (strcmp(str_original, "sair") == 0) {
            printf("Encerrando programa...\n");
            break;
        }
        
        strcpy(str_invertida, str_original);
        
        inverter_string(str_invertida);
        
        exibir_resultado(str_original, str_invertida);
    }
    
    return 0;
}