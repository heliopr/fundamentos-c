#include <stdio.h>

/*
Escreva um programa no qual o usuário digita uma quantia arbitrária de números inteiros
positivos. Quando o usuário digitar um número menor ou igual a 0, o programa deve indicar o tamanho
da maior sequência crescente observada. Por exemplo, se os números digitados forem 5, 10, 3, 2, 4,
7, 9, 8, 5, a maior sequência crescente é 2, 4, 7, 9, então o programa deve mostrar na tela que a maior
sequência crescente tem 4 números. Já a sequência 10, 8, 7, 5, 2 está em ordem decrescente,
portanto a maior sequência crescente observada tem tamanho 1.
*/
int main() {
    int maiorSequencia = 1;
    int sequencia = 1;
    int ult = -1;
    int n;
    scanf("%d", &n);

    while (n > 0) {
        if (ult != -1) {
            if (n > ult) sequencia++;
            else sequencia = 1;

            if (sequencia > maiorSequencia) maiorSequencia = sequencia;
        }
        ult = n;
        scanf("%d", &n);
    }

    printf("Maior sequência crescente: %d\n", maiorSequencia);
}
