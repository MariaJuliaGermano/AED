#include <stdio.h>
#include <iostream>
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
        std::cout << "Colaborador: " << i + 1 << "\n";
        
        std::cout << "Digite o nome o colaborador:\n";
        std::cin >> Colaboradores[i].nome;

        std::cout << "Digite a idade do colaborador:\n";
        std::cin >> Colaboradores[i].idade;

        std::cout << "Digite o salário do colaborador:\n";
        std:cin >> Colaboradores[i].salario;

        std::cout << "Digite o ano do colaborador:\n";
        std:cin >> Colaboradores[i].dt_nasc.ano;

        std::cout << "Digite o mes do colaborador:\n";
        std:cin >>  Colaboradores[1].dt_nasc.mes;

        std::cout << "Digite o dia do colaborador:\n";
        std:cin >>  Colaboradores[1].dt_nasc.dia;

    }

    system("pause"); // faz com que o programa não encerre ao ser executado
    return 0;
}

