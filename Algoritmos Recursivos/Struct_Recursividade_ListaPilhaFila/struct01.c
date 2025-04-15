#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa pessoa;

    printf("Nome: ");
    scanf("%s", pessoa.nome);

    printf("\nIdade: ");
    scanf("%d", &pessoa.idade);

    printf("\nAltura:");
    scanf("%f", &pessoa.altura);

    printf("\nAs informacoes preenchidas foram:");
    printf("\n Nome: %s", pessoa.nome);
    printf("\n Idade: %d", pessoa.idade);
    printf("\n Altura: %2.f", pessoa.altura);

    return 0;
}