#include <stdio.h>

int soma_digitos(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        return (numero % 10) + soma_digitos(numero / 10);
    }
}

int main() {
    int numero;
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        numero = -numero;
    }
    
    printf("A soma dos digitos de %d eh: %d\n", numero, soma_digitos(numero));
    
    return 0;
}