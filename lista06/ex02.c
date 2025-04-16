#include <stdio.h>

int main() {
    printf("Números encontrados:\n");
    for (int n = 1000; n < 10000; n++) {
        int a = n/100; // XXxx
        int b = n%100; // xxXX
        int c = a+b;

        if (c*c == n) {
            printf("%d (%d + %d = %d, %d * %d = %d)\n", n, a, b, c, c, c, n);
        }
    }
}