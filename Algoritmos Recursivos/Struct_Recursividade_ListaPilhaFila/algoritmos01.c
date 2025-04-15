#include <stdio.h>

int contar_digitos(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + contar_digitos(n/10);
    }
}


int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("O numero %d tem %d digitos\n", numero, contar_digitos(numero));


    return 0;
}