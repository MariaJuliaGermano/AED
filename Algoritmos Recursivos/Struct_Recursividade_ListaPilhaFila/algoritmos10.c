#include <stdio.h>

int produto_recursivo(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b == 1) {
        return a;
    }
    if (b < 0) {
        return -produto_recursivo(a, -b);
    }
    
    return a + produto_recursivo(a, b - 1);
}

int produto_iterativo(int a, int b) {
    int resultado = 0;
    int multiplicador = b;
    
    int sinal = 1;
    if (b < 0) {
        multiplicador = -b;
        sinal = -1;
    }
    
    for (int i = 0; i < multiplicador; i++) {
        resultado += a;
    }
    
    return resultado * sinal;
}

int main() {
    int a, b;
    
    printf("Digite dois numeros inteiros para calcular o produto: ");
    scanf("%d %d", &a, &b);
    
    printf("\nVersao Recursiva:");
    printf("\nO produto de %d e %d eh: %d\n", a, b, produto_recursivo(a, b));
    
    printf("\nVersao Iterativa:");
    printf("\nO produto de %d e %d eh: %d\n", a, b, produto_iterativo(a, b));
    
    return 0;
}