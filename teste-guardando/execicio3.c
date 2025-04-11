#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[10];
    float NtMat, NtFis, Media;
} Aluno;

int main() {
    Aluno A1, A2, A3;
    printf("Digite o nome do aluno1: \n");
    scanf("%s", A1.nome);
    printf("Digite a nota de Matematica do aluno1: \n");
    scanf("%f", &A1.NtMat);
    printf("Digite a nota de Física do aluno1: \n");
    scanf("%f", &A1.NtFis);
    A1.Media = (A1.NtMat + A1.NtFis) /2;

    printf("Digite o nome do aluno2: \n");
    scanf("%s", A2.nome);
    printf("Digite a nota de Matematica do aluno2: \n");
    scanf("%f", &A2.NtMat);
    printf("Digite a nota de Física do aluno2: \n");
    scanf("%f", &A2.NtFis);
    A2.Media = (A2.NtMat + A2.NtFis) /2;

    printf("Digite o nome do aluno3: \n");
    scanf("%s", A3.nome);
    printf("Digite a nota de Matematica do aluno3: \n");
    scanf("%f", &A3.NtMat);
    printf("Digite a nota de Física do aluno3: \n");
    scanf("%f", &A3.NtFis);
    A3.Media = (A3.NtMat + A3.NtFis) /2;

    return 0;
}