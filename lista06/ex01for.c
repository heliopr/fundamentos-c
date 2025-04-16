#include <stdio.h>

int main() {
    printf("Digite 10 números para fazer a média\n");

    int soma = 0;
    int cont = 0;
    for (int i = 0; i < 10; i++) {
        int x;
        scanf("%d", &x);

        if (x < 20) {
            soma += x;
            cont++;
        }
    }

    float media = (float)soma/cont;
    printf("Média: %f\n", media);
}