#include <stdio.h>

void contagem_regressiva_recursiva(int n) {
    if (n < 0) {
        return;
    }
    
    printf("%d", n);
    
    if (n > 0) {
        printf(", ");
    }
    
    contagem_regressiva_recursiva(n - 1);
}

void contagem_regressiva_iterativa(int n) {
    for (int i = n; i >= 0; i--) {
        printf("%d", i);
        if (i > 0) {
            printf(", ");
        }
    }
}

int main() {
    int numero;
    
    printf("Digite um numero para iniciar a contagem regressiva: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Por favor, digite um numero positivo.\n");
        return 1;
    }
    
    printf("\nVersao Recursiva:\n");
    printf("Contagem regressiva: ");
    contagem_regressiva_recursiva(numero);
    printf(".\n");
    
    printf("\nVersao Iterativa:\n");
    printf("Contagem regressiva: ");
    contagem_regressiva_iterativa(numero);
    printf(".\n");
    
    return 0;
}