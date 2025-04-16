#include <stdio.h>

int main() {
    float soma = 0;
    float maior = -1;
    float menor = 11;

    printf("Digite 6 notas para serem avaliadas:\n");
    for (int i = 0; i < 6; i++) {
        int nota;
        scanf("%d", &nota);

        soma += nota;
        if (nota > maior) maior = nota;
        if (nota < menor) menor = nota;
    }

    soma -= maior;
    soma -= menor;
    float media = soma/4;
    printf("Média: %f\n", media);
}