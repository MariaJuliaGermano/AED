#include <stdio.h>

int produto(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b == 1) {
        return a;
    }
    if (b < 0) {
        return -produto(a, -b);
    }
    
    return a + produto(a, b - 1);
}

int main() {
    int a, b;
    
    printf("Digite dois numeros inteiros para calcular o produto: ");
    scanf("%d %d", &a, &b);
    
    printf("O produto de %d e %d eh: %d\n", a, b, produto(a, b));
    
    return 0;
}
