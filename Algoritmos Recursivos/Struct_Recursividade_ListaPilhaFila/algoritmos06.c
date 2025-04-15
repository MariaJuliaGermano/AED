#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindromo_aux(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    
    if (tolower(str[inicio]) != tolower(str[fim])) {
        return 0;
    }
    
    return palindromo_aux(str, inicio + 1, fim - 1);
}

int palindromo(char str[]) {
    return palindromo_aux(str, 0, strlen(str) - 1);
}

int main() {
    char palavra[100];
    
    printf("Digite uma palavra para verificar se eh palindromo: ");
    scanf("%s", palavra);
    
    if (palindromo(palavra)) {
        printf("'%s' eh um palindromo!\n", palavra);
    } else {
        printf("'%s' nao eh um palindromo.\n", palavra);
    }
    
    return 0;
}