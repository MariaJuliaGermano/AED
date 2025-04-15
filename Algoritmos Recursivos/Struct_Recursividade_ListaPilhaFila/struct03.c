#include <stdio.h>

typedef struct {
    char nome[30];
    int codigo;
    float preco;
} Produto;

void exibirProduto(Produto p) {
    printf("\n=== Dados do Produto ===\n");
    printf("Nome: %s\n", p.nome);
    printf("Codigo: %d\n", p.codigo);
    printf("Preco: R$ %.2f\n", p.preco);
}

int main() {
    Produto prod;
    
    printf("Digite o nome do produto: ");
    scanf("%s", prod.nome);
    
    printf("Digite o codigo do produto: ");
    scanf("%d", &prod.codigo);
    
    printf("Digite o preco do produto: ");
    scanf("%f", &prod.preco);
    
    exibirProduto(prod);
    
    return 0;
}