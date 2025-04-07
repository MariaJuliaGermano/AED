#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} no;

no* novoNo(int valor) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

no* inserir(no* raiz, int valor) {
    if (raiz == NULL) return novoNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

no* buscar(no* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

int main() {
    no* raiz = NULL;

    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 70);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 60);
    inserir(raiz, 80);

    int valores[] = {60, 25, 40};
    int tamanho = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < tamanho; i++) {
        int v = valores[i];
        no* resultado = buscar(raiz, v);
        if (resultado != NULL)
            printf("Valor %d encontrado na árvore.\n", v);
        else
            printf("Valor %d NÃO encontrado na árvore.\n", v);
    }

    return 0;
}
