#include <stdio.h>


int maior_elemento(int vet[], int n) {
    if (n == 1) {
        return vet[0];
    } 

    int maior_resto = maior_elemnto(vet, n -1);
    if (vet[n - 1] > maior_resto) {
        return vet[n - 1];
    } else {
        return maior_resto;
    }
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
    
    printf("\nO maior elemento do vetor eh: %d\n", maior_elemento(vetor, n));
    
    int exemplo1[] = {5, 8, 2, 9, 3};
    int exemplo2[] = {1, 2, 3, 4, 5};
    int exemplo3[] = {10};
    
    printf("\nExemplos adicionais:\n");
    printf("Vetor {5,8,2,9,3}: maior = %d\n", maior_elemento(exemplo1, 5));
    printf("Vetor {1,2,3,4,5}: maior = %d\n", maior_elemento(exemplo2, 5));
    printf("Vetor {10}: maior = %d\n", maior_elemento(exemplo3, 1));
    
    return 0;
}