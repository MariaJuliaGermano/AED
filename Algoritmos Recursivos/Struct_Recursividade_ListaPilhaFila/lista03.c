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

No* inserir_ordenado(No* cabeca, int valor) {
    No* novo = criar_no(valor);
    
    if (cabeca == NULL || valor <= cabeca->valor) {
        novo->proximo = cabeca;
        return novo;
    }
    
    No* atual = cabeca;
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }
    
    novo->proximo = atual->proximo;
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
    
    printf("Lista ordenada: ");
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

int contar_elementos(No* cabeca) {
    int contador = 0;
    No* atual = cabeca;
    
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    
    return contador;
}

void liberar_lista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

No* reverter_lista(No* cabeca) {
    No* anterior = NULL;
    No* atual = cabeca;
    No* proximo = NULL;
    
    while (atual != NULL) {
        // Guarda o próximo nó
        proximo = atual->proximo;
        
        // Inverte a ligação do nó atual
        atual->proximo = anterior;
        
        // Move os ponteiros uma posição para frente
        anterior = atual;
        atual = proximo;
    }
    
    // O último nó (anterior) será a nova cabeça da lista
    return anterior;
}

// Versão recursiva da função de reversão
No* reverter_lista_recursivo(No* cabeca) {
    // Casos base: lista vazia ou último nó
    if (cabeca == NULL || cabeca->proximo == NULL) {
        return cabeca;
    }
    
    // Recursivamente reverte o resto da lista
    No* resto = reverter_lista_recursivo(cabeca->proximo);
    
    // Inverte a ligação do próximo nó
    cabeca->proximo->proximo = cabeca;
    cabeca->proximo = NULL;
    
    return resto;
}

int main() {
    No* lista = NULL;
    int opcao, valor;
    
    do {
        printf("\n=== Menu Lista Encadeada Ordenada ===\n");
        printf("1. Inserir elemento (ordenado)\n");
        printf("2. Remover elemento\n");
        printf("3. Exibir lista\n");
        printf("4. Contar elementos\n");
        printf("5. Reverter lista (iterativo)\n");
        printf("6. Reverter lista (recursivo)\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                lista = inserir_ordenado(lista, valor);
                printf("Elemento inserido com sucesso!\n");
                break;
                
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                lista = remover_elemento(lista, valor);
                break;
                
            case 3:
                exibir_lista(lista);
                break;
                
            case 4:
                printf("Número de elementos na lista: %d\n", 
                       contar_elementos(lista));
                break;
                
            case 5:
                lista = reverter_lista(lista);
                printf("Lista revertida com sucesso (método iterativo)!\n");
                exibir_lista(lista);
                break;
                
            case 6:
                lista = reverter_lista_recursivo(lista);
                printf("Lista revertida com sucesso (método recursivo)!\n");
                exibir_lista(lista);
                break;
                
            case 7:
                printf("Encerrando programa...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 7);
    
    liberar_lista(lista);
    
    return 0;
}
