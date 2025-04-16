#include <stdio.h>

#define TIPO double

/*
(b) O erro acontece devido à imprecisão dos números float, que utilizam o padrão de representação
IEEE 754. Portanto, ao alterar a ordem da soma, o erro é acumulado de um modo diferente e resulta
em um resultado diferente.

(c) O tipo double representa até 15 dígitos decimais com precisão, enquanto o tipo float representa
apenas 7. No entanto, números double utilizam 64 bits de memória, enquanto floats requerem apenas 32
bits.
*/ 

TIPO somatorio(int j, int k) {
    TIPO s = 0.0;
    int sinal = j%2==0 ? -1 : 1;
    for (int i = j; j<k ? i<=k : i>=k ; j<k ? i++ : i--) {
        s += sinal/(TIPO)i;
        sinal = -sinal;
    }
    return s;
}

int main() {
    int j = 1, k = 1000000;

    printf("Realizando o somatório de %d até %d\n", j, k);
    TIPO s1 = somatorio(j, k);
    printf("Resultado: %.20f\n", s1);

    printf("Realizando o somatório de %d até %d\n", k, j);
    TIPO s2 = somatorio(k, j);
    printf("Resultado: %.20f\n", s2);
}