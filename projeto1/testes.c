#include <stdio.h>
#include <math.h>
#include "trabalho1.h"

void test_calculaValorDevido() {
    printf("%f %f\n", calculaValorDevido(80, 6, 18, 100, 0.1, 0.5), 7.44);
    printf("%f %f\n", calculaValorDevido(100, 6, 18, 100, 0.1, 0.5), 7.8);
    printf("%f %f\n", calculaValorDevido(200, 6, 18, 100, 0.1, 0.5), 9.42);
    printf("%f %f\n", calculaValorDevido(300, 6, 18, 100, 0.1, 0.5), 10.86);
    printf("%f %f\n", calculaValorDevido(400, 6, 18, 100, 0.1, 0.5), 12.12);
    printf("%f %f\n", calculaValorDevido(500, 6, 18, 100, 0.1, 0.5), 13.2);
    printf("%f %f\n", calculaValorDevido(1000, 6, 18, 100, 0.1, 0.5), 17.7);

    printf("%f %f\n", calculaValorDevido(80, 7, 16, 80, 0.05, 0.6), 8.28);
    printf("%f %f\n", calculaValorDevido(100, 7, 16, 80, 0.05, 0.6), 8.58);
    printf("%f %f\n", calculaValorDevido(200, 7, 16, 80, 0.05, 0.6), 10.07);
    printf("%f %f\n", calculaValorDevido(300, 7, 16, 80, 0.05, 0.6), 11.46);
    printf("%f %f\n", calculaValorDevido(400, 7, 16, 80, 0.05, 0.6), 12.76);
    printf("%f %f\n", calculaValorDevido(500, 7, 16, 80, 0.05, 0.6), 13.94);
    printf("%f %f\n", calculaValorDevido(1000, 7, 16, 80, 0.05, 0.6), 18.39);

    printf("TRADICIONAL %f %f\n", calculaValorDevido(1220, 7, 16, 100, 0, 0), 1.22*16.0 + 7.0);
    printf("TRADICIONAL %f %f\n", calculaValorDevido(1220, 7, 16, 1, 0, 0), 1.22*16.0 + 7.0);
}

void test_fourcc() {
    printf("%u\n", fourcc('M', 'P', 'E', 'G'));
    printf("%u\n", fourcc('D', 'I', 'V', 'X'));
}

void test_raizAproximada() {
    printf("%f %f\n", raizAproximada(2, 1e-10), sqrt(2));
    printf("%f %f\n", raizAproximada(0.36, 1e-10), sqrt(0.36));
    printf("%f %f\n", raizAproximada(3, 1e-10), sqrt(3));
    printf("%f %f\n", raizAproximada(100, 1e-10), sqrt(100));
    printf("%f %f\n", raizAproximada(169, 1e-10), sqrt(169));
    printf("%f %f\n", raizAproximada(4533553, 1e-10), sqrt(4533553));
    printf("%f %f\n", raizAproximada(0.47642319, 1e-10), sqrt(0.47642319));
    printf("%f %f\n", raizAproximada(0, 1e-10), sqrt(0));
}

int main() {
    printf("calculaValorDevido:\n");
    test_calculaValorDevido();
    printf("\n");

    printf("fourcc:\n");
    test_fourcc();
    printf("\n");

    printf("raizAproximada:\n");
    test_raizAproximada();
    printf("\n");
}