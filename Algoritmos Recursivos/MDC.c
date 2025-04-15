#include <stdio.h>

int mdc_recursivo(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc_recursivo(b, a % b);
}

int mdc_interativa(int a, int b) {
    int resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
}

int main() {
    int num1, num2;
    printf("Digite dois números para calcular o MDC: /n");
    scanf("%d %d", num1, num2);

    printf("\nMétodo Recursivo: %d\n", mdc_recursivo(num1, num2));
    printf("\nMétodo interativo: %d\n", mdc_interativa(num1, num2));

    return 0;
}