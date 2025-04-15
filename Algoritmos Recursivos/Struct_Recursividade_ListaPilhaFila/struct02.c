#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;


int main() {
    Aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("=== Aluno %d ===\n", i + 1);

        printf("Digite o nome: ");
        scanf("%s", alunos[i].nome);
      
        printf("Digite a matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Digite a nota: ");
        scanf("%f", &alunos[i].nota);
    };

    printf("\n ==== Dados dos alunos ===");
    for (int i; i < 5; i++) {
        printf("\n==========");
        printf("\nAluno %d", i + 1);
        printf("\nNome: %s", alunos[i].nome);
        printf("\nMatricula: %d", alunos[i].matricula);
        printf("\nNota: %2.f", alunos[i].nota);
        printf("\n==========");
    }

    return 0;
}