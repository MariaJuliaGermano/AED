#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    char cargo[30];
    float salario;
} Funcionario;


void lerFuncionario(Funcionario *f) {
    printf("\nDigite o nome: ");
    scanf("%s", f->nome);
    
    printf("Digite o cargo: ");
    scanf("%s", f->cargo);
    
    printf("Digite o salário: R$ ");
    scanf("%f", &f->salario);
}


void mostrarFuncionario(Funcionario f) {
    printf("\n================");
    printf("\nNome: %s", f.nome);
    printf("\nCargo: %s", f.cargo);
    printf("\nSalário: R$ %.2f", f.salario);
    printf("\n================\n");
}


int main() {
    int N;
    printf("Digite o número de funcionários a serem cadastrados: ");
    scanf("%d", &N);
    
    Funcionario *funcionarios = (Funcionario*) malloc(N * sizeof(Funcionario));
    
    if (funcionarios == NULL) {
        printf("Erro na alocação de memória!");
        return 1;
    }
    
    for(int i = 0; i < N; i++) {
        printf("\nDados do funcionário %d:", i + 1);
        lerFuncionario(&funcionarios[i]);
    }
    
    printf("\n=== Lista de Funcionários Cadastrados ===\n");
    for(int i = 0; i < N; i++) {
        printf("\nFuncionário %d:", i + 1);
        mostrarFuncionario(funcionarios[i]);
    }
    
    free(funcionarios);
    
    return 0;
}
