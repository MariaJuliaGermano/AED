int main() {
    int vetor[100], cont;
    for (cont = 0; cont < 100; cont++) {
        vetor[cont] = 1000 - cont;
    }

    for (cont = 0; cont < 1000; cont++) {
        printf("%d", vetor[cont]);
    }

    return 0;
}