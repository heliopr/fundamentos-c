#include <stdio.h>

#define N_MAX 1000

// 640
int main() {
    int min = 0;
    int max = N_MAX;
    int n = (max+min)/2;
    int acertou = 0;
    while (!acertou) {
        printf("O número é: %d\n", n);
        int r;
        scanf("%d", &r);

        if (r == 1) max = n;
        else if (r == 2) acertou = 1;
        else if (r == 3) min = n;
        n = (max+min)/2;
    }

    printf("%d\n", n);
}
