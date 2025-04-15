#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
    char diagnostico[100];
} Paciente;

void lerPaciente(Paciente *p) {
    printf("\nDigite o nome: ");
    scanf("%s", p->nome);
    
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    
    printf("Digite o diagnostico: ");
    scanf("%s", p->diagnostico);
}

void exibirPacientesIdosos(Paciente *pacientes, int quantidade) {
    int encontrou = 0;
    printf("\n=== Pacientes com mais de 60 anos ===\n");
    
    for(int i = 0; i < quantidade; i++) {
        if(pacientes[i].idade > 60) {
            printf("\n================");
            printf("\nNome: %s", pacientes[i].nome);
            printf("\nIdade: %d", pacientes[i].idade);
            printf("\nDiagnostico: %s", pacientes[i].diagnostico);
            printf("\n================\n");
            encontrou = 1;
        }
    }
    
    if(!encontrou) {
        printf("\nNenhum paciente com mais de 60 anos encontrado!\n");
    }
}

int main() {
    int N;
    printf("Digite o numero de pacientes a serem cadastrados: ");
    scanf("%d", &N);
    
    Paciente *pacientes = (Paciente*) malloc(N * sizeof(Paciente));
    
    if (pacientes == NULL) {
        printf("Erro na alocacao de memoria!");
        return 1;
    }
    
    for(int i = 0; i < N; i++) {
        printf("\nDados do paciente %d:", i + 1);
        lerPaciente(&pacientes[i]);
    }
    
    exibirPacientesIdosos(pacientes, N);
    
    free(pacientes);
    
    return 0;
}
