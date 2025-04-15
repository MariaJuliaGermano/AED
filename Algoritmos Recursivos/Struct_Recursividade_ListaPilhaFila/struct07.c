#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    char telefone[15];
} Contato;


void adicionarContato(Contato *contatos, int *totalContatos) {
    printf("\n=== Adicionar Contato ===\n");
    printf("Nome: ");
    scanf("%s", contatos[*totalContatos].nome);
    
    printf("Telefone: ");
    scanf("%s", contatos[*totalContatos].telefone);
    
    (*totalContatos)++;
    printf("\nContato adicionado com sucesso!\n");
}


void buscarContato(Contato *contatos, int totalContatos) {
    char nomeBusca[50];
    int encontrou = 0;
    
    printf("\n=== Buscar Contato ===\n");
    printf("Digite o nome para busca: ");
    scanf("%s", nomeBusca);
    
    for(int i = 0; i < totalContatos; i++) {
        if(strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("\nContato encontrado:");
            printf("\nNome: %s", contatos[i].nome);
            printf("\nTelefone: %s\n", contatos[i].telefone);
            encontrou = 1;
            break;
        }
    }
    
    if(!encontrou) {
        printf("\nContato não encontrado!\n");
    }
}

int main() {
    Contato *agenda = (Contato*)malloc(100 * sizeof(Contato)); // Permite até 100 contatos
    int totalContatos = 0;
    int opcao;
    
    if(agenda == NULL) {
        printf("Erro na alocação de memória!");
        return 1;
    }
    
    do {
        printf("\n=== Agenda Telefônica ===\n");
        printf("1. Adicionar Contato\n");
        printf("2. Buscar Contato\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                if(totalContatos < 100) {
                    adicionarContato(agenda, &totalContatos);
                } else {
                    printf("\nAgenda cheia!\n");
                }
                break;
            case 2:
                buscarContato(agenda, totalContatos);
                break;
            case 3:
                printf("\nEncerrando programa...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 3);
    
    free(agenda);
    return 0;
}