#include <stdio.h>

int maior_elemento_recursivo(int vet[], int n) {
    if (n == 1) {
        return vet[0];
    } 

    int maior_resto = maior_elemento_recursivo(vet, n - 1);
    if (vet[n - 1] > maior_resto) {
        return vet[n - 1];
    } else {
        return maior_resto;
    }
}

int maior_elemento_iterativo(int vet[], int n) {
    int maior = vet[0]; 
    
    for (int i = 1; i < n; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
    
    return maior;
}

int main() {
    int n;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    int vetor[n];
    
    printf("Digite os %d elementos do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    printf("\nVersao Recursiva:");
    printf("\nO maior elemento do vetor eh: %d\n", maior_elemento_recursivo(vetor, n));
    
    printf("\nVersao Iterativa:");
    printf("\nO maior elemento do vetor eh: %d\n", maior_elemento_iterativo(vetor, n));
    
    return 0;
}