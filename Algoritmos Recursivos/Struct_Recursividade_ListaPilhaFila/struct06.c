#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

void lerLivro(Livro *l) {
    printf("\nDigite o título: ");
    scanf("%s", l->titulo);
    
    printf("Digite o autor: ");
    scanf("%s", l->autor);
    
    printf("Digite o ano de publicação: ");
    scanf("%d", &l->ano);
}

void exibirLivrosAposAno(Livro livros[], int quantidade, int anoBase) {
    int encontrou = 0;
    printf("\n=== Livros publicados após %d ===\n", anoBase);
    
    for(int i = 0; i < quantidade; i++) {
        if(livros[i].ano > anoBase) {
            printf("\n================");
            printf("\nTítulo: %s", livros[i].titulo);
            printf("\nAutor: %s", livros[i].autor);
            printf("\nAno: %d", livros[i].ano);
            printf("\n================\n");
            encontrou = 1;
        }
    }
    
    if(!encontrou) {
        printf("\nNenhum livro encontrado após o ano %d\n", anoBase);
    }
}

int main() {
    int N, anoBase;
    
    printf("Digite a quantidade de livros a serem cadastrados: ");
    scanf("%d", &N);
    
    Livro *livros = (Livro*) malloc(N * sizeof(Livro));
    
    if (livros == NULL) {
        printf("Erro na alocação de memória!");
        return 1;
    }
    
    for(int i = 0; i < N; i++) {
        printf("\nDados do livro %d:", i + 1);
        lerLivro(&livros[i]);
    }
    
    printf("\nDigite o ano base para filtrar os livros: ");
    scanf("%d", &anoBase);
    
    exibirLivrosAposAno(livros, N, anoBase);
    
    free(livros);
    
    return 0;
}