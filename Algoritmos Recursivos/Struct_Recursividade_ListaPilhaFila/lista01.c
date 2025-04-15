#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

No* inserir_inicio(No* cabeca, int valor) {
    No* novo = criar_no(valor);
    novo->proximo = cabeca;
    return novo;
}

No* inserir_final(No* cabeca, int valor) {
    No* novo = criar_no(valor);
    
    if (cabeca == NULL) {
        return novo;
    }
    
    No* atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
    return cabeca;
}

No* remover_elemento(No* cabeca, int valor) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }
    
    if (cabeca->valor == valor) {
        No* temp = cabeca->proximo;
        free(cabeca);
        printf("Elemento %d removido com sucesso!\n", valor);
        return temp;
    }
    
    No* atual = cabeca;
    No* anterior = NULL;
    
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual != NULL) {
        anterior->proximo = atual->proximo;
        free(atual);
        printf("Elemento %d removido com sucesso!\n", valor);
    } else {
        printf("Elemento %d não encontrado na lista!\n", valor);
    }
    
    return cabeca;
}

void exibir_lista(No* cabeca) {
    if (cabeca == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    printf("Lista: ");
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(" -> ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

void liberar_lista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    No* lista = NULL;
    int opcao, valor;
    
    do {
        printf("\n=== Menu Lista Encadeada ===\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Remover elemento\n");
        printf("4. Exibir lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido no início: ");
                scanf("%d", &valor);
                lista = inserir_inicio(lista, valor);
                break;
                
            case 2:
                printf("Digite o valor a ser inserido no final: ");
                scanf("%d", &valor);
                lista = inserir_final(lista, valor);
                break;
                
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                lista = remover_elemento(lista, valor);
                break;
                
            case 4:
                exibir_lista(lista);
                break;
                
            case 5:
                printf("Encerrando programa...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 5);
    
    liberar_lista(lista);
    
    return 0;
}