#include <stdio.h>

int main() {
    printf("Digite 2 numeros:\n");
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    int q = 0, r = 0;
    while (x >= y) {
        x -= y;
        q++;
    }
    r = x;
    printf("Quociente: %d. Resto: %d\n", q, r);
}
