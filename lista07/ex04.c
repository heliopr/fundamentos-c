#include <stdio.h>

/*
Escreva um programa que lê um inteiro positivo e um dígito. O programa deve verificar se o
número dado contém o dígito em qualquer posição. Não é preciso dizer qual a posição, apenas indicar
se o dígito está ou não presente.
*/
int main() {
    printf("Digite um numero inteiro e um digito: ");
    int n, d;
    scanf("%d", &n);
    scanf("%d", &d);

    int encontrou = 0;
    while (n > 0 && !encontrou) {
        if (n%10 == d) encontrou = 1;
        n = n/10;
    }

    if (encontrou) printf("Encontrou!\n");
    else printf("Não encontrou!\n");
}
