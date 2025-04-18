#include <stdio.h>

int main() {
    printf("Digite um número n: ");
    int n;
    scanf("%d",&n);

    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    printf("Fatorial de %d é %d\n", n, f);
}
