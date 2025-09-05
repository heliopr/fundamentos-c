#include <stdio.h>

int primo(int n) {
    if (n == 2) return 1;
    if (n < 2) return 0;
    if (n % 2 == 0) return 0;

    int i = 3;
    while (i < n) {
        if (n % i == 0)
            return 0;
        i += 2;
    }

    return 1;
}

void main() {
    printf("%d\n", primo(-1));
    printf("%d\n", primo(2));
    printf("%d\n", primo(3));
    printf("%d\n", primo(6));
    printf("%d\n", primo(7));
    printf("%d\n", primo(-7));
    printf("%d\n", primo(11));
}