#include <stdio.h>

#define N 11

int main() {
    int t = -1;
    int e = N/2;

    for (int i = 0; i < (N/2)+1; i++) {
        for (int j = 0; j < e; j++) {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < t; j++) {
            printf("-");
        }

        if (t > 0) printf("*");
        printf("\n");
        t += 2;
        e--;
    }
    return 0;
}

