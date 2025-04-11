#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float preco;
    int qnt_vend;
} Produto;


int main() {
    Produto produtos[10];
    float total_vendas;

    for (int i=0; i < 10; i++) {
        printf("Produto %d\n", i + 1);

        printf("Digite o nome do produto: \n");
        scanf("%49s", produtos[i].nome);

        printf("Digite o preço do produto: \n");
        scanf("%f", &produtos[i].preco);

        printf("Digite a quantidade de vendas do produto: \n");
        scanf("%d", &produtos[i].qnt_vend);

        total_vendas += produtos[i].preco * produtos[i].qnt_vend;
        printf("\n");
    };

    printf("O valor total de vendas: R$ %.2f \n", total_vendas);

    return 0;
}