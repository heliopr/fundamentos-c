#include <stdio.h>

int main() {
    printf("Digite um número n: ");

    int n;
    scanf("%d", &n);

    int soma = 0;
    for (int i = 1; i < n && soma < n; i++) {
        if (n%i == 0) soma += i;
    }

    if (soma == n) printf("%d é perfeito\n", n);
    else printf("%d não é perfeito\n", n);
}