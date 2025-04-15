#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CLIENTES 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int senha;
    char tipoAtendimento[20];
    time_t horaChegada;
} Cliente;

typedef struct {
    Cliente clientes[MAX_CLIENTES];
    int inicio;
    int fim;
    int tamanho;
    int proximaSenha;
} FilaBanco;

void inicializar_fila(FilaBanco *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
    f->proximaSenha = 1;
}

int esta_vazia(FilaBanco *f) {
    return f->tamanho == 0;
}

int esta_cheia(FilaBanco *f) {
    return f->tamanho == MAX_CLIENTES;
}

void adicionar_cliente(FilaBanco *f) {
    if (esta_cheia(f)) {
        printf("\nDesculpe, a fila está cheia. Por favor, aguarde.\n");
        return;
    }
    
    Cliente novo;
    printf("\n=== Novo Cliente ===\n");
    printf("Nome: ");
    scanf(" %[^\n]s", novo.nome);
    
    printf("Tipo de Atendimento (1-Caixa, 2-Gerente): ");
    int tipo;
    scanf("%d", &tipo);
    strcpy(novo.tipoAtendimento, tipo == 1 ? "Caixa" : "Gerente");
    
    novo.senha = f->proximaSenha++;
    novo.horaChegada = time(NULL);
    
    f->fim = (f->fim + 1) % MAX_CLIENTES;
    f->clientes[f->fim] = novo;
    f->tamanho++;
    
    printf("\nCliente adicionado com sucesso!");
    printf("\nSenha: %d", novo.senha);
    printf("\nHorário de chegada: %s", ctime(&novo.horaChegada));
}

void atender_cliente(FilaBanco *f) {
    if (esta_vazia(f)) {
        printf("\nNão há clientes na fila.\n");
        return;
    }
    
    Cliente cliente = f->clientes[f->inicio];
    time_t horaAtendimento = time(NULL);
    double tempoEspera = difftime(horaAtendimento, cliente.horaChegada);
    
    printf("\n=== Atendendo Cliente ===");
    printf("\nSenha: %d", cliente.senha);
    printf("\nNome: %s", cliente.nome);
    printf("\nTipo de Atendimento: %s", cliente.tipoAtendimento);
    printf("\nTempo de espera: %.0f minutos e %.0f segundos", 
           floor(tempoEspera/60), fmod(tempoEspera, 60));
    
    f->inicio = (f->inicio + 1) % MAX_CLIENTES;
    f->tamanho--;
}

void exibir_fila(FilaBanco *f) {
    if (esta_vazia(f)) {
        printf("\nNão há clientes na fila.\n");
        return;
    }
    
    printf("\n=== Fila de Atendimento ===");
    printf("\nTotal de clientes: %d\n", f->tamanho);
    
    int pos = f->inicio;
    for (int i = 0; i < f->tamanho; i++) {
        Cliente cliente = f->clientes[pos];
        time_t horaAtual = time(NULL);
        double tempoEspera = difftime(horaAtual, cliente.horaChegada);
        
        printf("\n--- Cliente %d ---", i + 1);
        printf("\nSenha: %d", cliente.senha);
        printf("\nNome: %s", cliente.nome);
        printf("\nTipo: %s", cliente.tipoAtendimento);
        printf("\nTempo de espera: %.0f minutos e %.0f segundos", 
               floor(tempoEspera/60), fmod(tempoEspera, 60));
        
        pos = (pos + 1) % MAX_CLIENTES;
    }
    printf("\n");
}

void estatisticas_atendimento(FilaBanco *f) {
    printf("\n=== Estatísticas de Atendimento ===");
    printf("\nTotal de clientes na fila: %d", f->tamanho);
    printf("\nSenhas distribuídas hoje: %d", f->proximaSenha - 1);
    
    if (!esta_vazia(f)) {
        int caixas = 0, gerentes = 0;
        int pos = f->inicio;
        time_t maiorEspera = 0;
        char clienteMaiorEspera[MAX_NOME];
        
        for (int i = 0; i < f->tamanho; i++) {
            Cliente cliente = f->clientes[pos];
            if (strcmp(cliente.tipoAtendimento, "Caixa") == 0) caixas++;
            else gerentes++;
            
            time_t tempoEspera = difftime(time(NULL), cliente.horaChegada);
            if (tempoEspera > maiorEspera) {
                maiorEspera = tempoEspera;
                strcpy(clienteMaiorEspera, cliente.nome);
            }
            
            pos = (pos + 1) % MAX_CLIENTES;
        }
        
        printf("\nClientes aguardando caixa: %d", caixas);
        printf("\nClientes aguardando gerente: %d", gerentes);
        printf("\nCliente com maior tempo de espera: %s (%.0f minutos)", 
               clienteMaiorEspera, floor(maiorEspera/60));
    }
    printf("\n");
}

int main() {
    FilaBanco fila;
    inicializar_fila(&fila);
    int opcao;
    
    do {
        printf("\n=== Sistema de Atendimento Bancário ===\n");
        printf("1. Adicionar novo cliente\n");
        printf("2. Atender próximo cliente\n");
        printf("3. Visualizar fila\n");
        printf("4. Estatísticas de atendimento\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                adicionar_cliente(&fila);
                break;
            case 2:
                atender_cliente(&fila);
                break;
            case 3:
                exibir_fila(&fila);
                break;
            case 4:
                estatisticas_atendimento(&fila);
                break;
            case 5:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 5);
    
    return 0;
}