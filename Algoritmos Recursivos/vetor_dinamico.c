#include <stdio.h>
#include <stdlib.h>

int main () {
    int *p;
    int tamanho = 1000;


    // alocação de memória dinamicamente
    p = (int*) malloc(tamanho * sizeof(int));


    free(p); // é importante, após utilizar o vetor, liberar a sua memória se foi utilizado, aqui nesse caso ainda não utilizamos ele, mas se caso tivessemos utilizado seria importante liberar a memória dele


    return 0;
}