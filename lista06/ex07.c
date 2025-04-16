#include <stdio.h>

float somatorio(int j, int k) {
    float s = 0.0f;
    for (int i = j; j<k ? i<=k : i>=k ; j<k ? i++ : i--) {
        float numerador = i%2==0 ? -1 : 1;
        s += numerador/(float)i;
    }
    return s;
}

int main() {
    int j = 1, k = 1000000;

    printf("Realizando o somatório de %d até %d\n", j, k);
    float s1 = somatorio(j, k);
    printf("Resultado: %.20f\n", s1);

    printf("Realizando o somatório de %d até %d\n", k, j);
    float s2 = somatorio(k, j);
    printf("Resultado: %.20f\n", s2);
}