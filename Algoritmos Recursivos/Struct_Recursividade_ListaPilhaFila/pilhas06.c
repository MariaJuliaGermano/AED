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

int verificar_parenteses(char *expressao) {
    Pilha pilha;
    inicializar_pilha(&pilha);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            push(&pilha, '(');
        } 
        else if (expressao[i] == ')') {
            if (isEmpty(&pilha)) {
                return 0; 
            }
            pop(&pilha);
        }
    }
    
    return isEmpty(&pilha);  
}

int main() {
    char expressao[MAX_SIZE];
    
    while (1) {
        printf("\n=== Verificador de Parenteses ===\n");
        printf("Digite a expressao (ou 'sair' para encerrar): ");
        scanf("%s", expressao);
        
        if (strcmp(expressao, "sair") == 0) {
            printf("Encerrando programa...\n");
            break;
        }
        
        if (verificar_parenteses(expressao)) {
            printf("'%s' -> Valido\n", expressao);
        } else {
            printf("'%s' -> Invalido\n", expressao);
        }
    }
    
    return 0;
}