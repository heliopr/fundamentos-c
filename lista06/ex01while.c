#include <stdio.h>

int main() {
    printf("Digite 10 números para fazer a média\n");

    int soma = 0;
    int cont = 0;
    int i = 0;
    while (i < 10) {
        int x;
        scanf("%d", &x);

        if (x < 20) {
            soma += x;
            cont++;
        }
        i++;
    }

    float media = (float)soma/cont;
    printf("Média: %f\n", media);
}