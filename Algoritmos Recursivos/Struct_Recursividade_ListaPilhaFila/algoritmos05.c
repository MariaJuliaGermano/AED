#include <stdio.h>

void contagem_regressiva(int n) {
    if (n < 0) {
        return;
    }
    
    printf("%d", n);
    
    if (n > 0) {
        printf(", ");
    }
    
    contagem_regressiva(n - 1);
}

int main() {
    int numero;
    
    printf("Digite um numero para iniciar a contagem regressiva: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Por favor, digite um numero positivo.\n");
        return 1;
    }
    
    printf("Contagem regressiva: ");
    contagem_regressiva(numero);
    printf(".\n");
    
    return 0;
}