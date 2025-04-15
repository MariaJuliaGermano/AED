#include <stdio.h>

int soma_digitos_recursivo(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        return (numero % 10) + soma_digitos_recursivo(numero / 10);
    }
}

int soma_digitos_iterativo(int numero) {
    int soma = 0;
    
    while (numero > 0) {
        soma += numero % 10;  
        numero = numero / 10; 
    }
    
    return soma;
}

int main() {
    int numero;
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        numero = -numero;
    }
    
    printf("\nVersao Recursiva:");
    printf("\nA soma dos digitos de %d eh: %d\n", numero, soma_digitos_recursivo(numero));
    
    printf("\nVersao Iterativa:");
    printf("\nA soma dos digitos de %d eh: %d\n", numero, soma_digitos_iterativo(numero));
    
    return 0;
}