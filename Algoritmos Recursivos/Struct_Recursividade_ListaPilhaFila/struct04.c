#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char modelo[30];
    int ano;
    float preco;
} Carro;

int main() {
    Carro *carro = (Carro*) malloc(sizeof(Carro));

    if (carro == NULL) {
        printf("Erro na alocação de memória!");
        return 1;
    }    
    printf("Digite o modelo do carro: ");
    scanf("%s", carro->modelo);
    
    printf("Digite o ano do carro: ");
    scanf("%d", &carro->ano);
    
    printf("Digite o preco do carro: ");
    scanf("%f", &carro->preco);
    
    printf("\n=== Dados do Carro ===\n");
    printf("Modelo: %s\n", carro->modelo);
    printf("Ano: %d\n", carro->ano);
    printf("Preco: R$ %.2f\n", carro->preco);
    
    free(carro);

    return 0;
}
