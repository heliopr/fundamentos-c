#include <stdio.h>

#define N 7

void mostraLinha(int asteriscos, int cerquilhas) {
    for (int i = 0; i < asteriscos; i++) printf("*");
    for (int i = 0; i < cerquilhas; i++) printf("#");
    for (int i = 0; i < asteriscos; i++) printf("*");
    printf("\n");
}

void main() {
    for (int i = 3; i <= N; i+=2) {
        int asteriscos = 1, cerquilhas = (2*i)-2;
        for (int j = 0; j < i; j++) {
            mostraLinha(asteriscos, cerquilhas);
            asteriscos++;
            cerquilhas -= 2;
        }
        printf("\n");
    }
}