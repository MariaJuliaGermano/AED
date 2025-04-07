#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} no;

no* novoNo(int valor);
no* inserir(no* raiz, int valor);
no* buscar(no* raiz, int valor);
no* minimo(no* no);
no* remover(no* raiz, int valor);
void emOrdem(no *raiz);
void menu();

int main() {
    menu();
    return 0;
}

no* novoNo(int valor) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

no* inserir(no* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

no* buscar(no* raiz, int valor) {
    if (raiz == NULL || valor == raiz->valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    return buscar(raiz->direita, valor);
}

no* minimo(no* no) {
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

no* remover(no* raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            no* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            no* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        no* temp = minimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

void emOrdem(no* raiz) {
    if (raiz == NULL) {
        return;
    }
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->valor);
    emOrdem(raiz->direita);
}

void menu() {
    no* raiz = NULL;
    int opcao, valor;

    do {
        printf("\n====== MENU ÁRVORE BINÁRIA DE BUSCA ======\n");
        printf("1 - Inserir Valor\n");
        printf("2 - Remover Valor\n");
        printf("3 - Buscar Valor\n");
        printf("4 - Exibir em Ordem\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                if (raiz == NULL) {
                    printf("A árvore está vazia.\n");
                } else {
                    printf("Digite o valor a remover: ");
                    scanf("%d", &valor);
                    raiz = remover(raiz, valor);
                }
                break;
            case 3:
                if (raiz == NULL) {
                    printf("A árvore está vazia.\n");
                } else {
                    printf("Digite o valor a buscar: ");
                    scanf("%d", &valor);
                    no* encontrado = buscar(raiz, valor);
                    if (encontrado != NULL) {
                        printf("Valor %d encontrado na árvore.\n", valor);
                    } else {
                        printf("Valor %d não encontrado.\n", valor);
                    }
                }
                break;
            case 4:
                if (raiz == NULL) {
                    printf("A árvore está vazia.\n");
                } else {
                    printf("Elementos em ordem: ");
                    emOrdem(raiz);
                    printf("\n");
                }
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);
}
