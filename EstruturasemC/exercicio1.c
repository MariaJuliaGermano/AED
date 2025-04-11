#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    char mes[10];
    int ano;
} Data;

typedef struct {
    char nome[15];
    int idade;
    float salario;
    Data dt_nasc;
} Funcionario;

int main(){
    Funcionario Colaboradores[3];

    for (int i = 0; i < 3; i++) {
        printf("Colaborador: %d\n", i + 1);
        
        printf("Digite o nome do colaborador:\n");
        scanf("%s", Colaboradores[i].nome);
        
        printf("Digite a idade do colaborador:\n");
        scanf("%d", &Colaboradores[i].idade);
        
        printf("Digite o salário do colaborador:\n");
        scanf("%f", &Colaboradores[i].salario);
        
        printf("Digite o ano de nascimento do colaborador:\n");
        scanf("%d", &Colaboradores[i].dt_nasc.ano);
        
        printf("Digite o mes de nascimento do colaborador:\n");
        scanf("%s", Colaboradores[i].dt_nasc.mes);
        
        printf("Digite o dia de nascimento do colaborador:\n");
        scanf("%d", &Colaboradores[i].dt_nasc.dia);
        
        printf("\n");

    }

    system("pause"); // faz com que o programa não encerre ao ser executado
    return 0;
}