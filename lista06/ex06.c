#include <stdio.h>

// Essa quantidade de termos consegue aproximar 7 casas decimais de pi
#define N_TERMOS 100000000

int main() {
    double aprox = 0;
    int sinal = 1;
    int n = 1;

    for (int i = 0; i < N_TERMOS; i++) {
        aprox += sinal * (1/(double)(n+(i*2)));
        sinal = -sinal;
    }

    aprox *= 4;
    printf("Aproximando em %d termos, pi é aproximadamente %.20f\n", N_TERMOS, aprox);
}