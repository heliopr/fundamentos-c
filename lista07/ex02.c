#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int crescente = 1;
    int decrescente = 1;
    int ult;
    scanf("%d", &ult);
    for (int i = 0; i < n-1; i++) {
        int x;
        scanf("%d", &x);

        if (x > ult) decrescente = 0;
        if (x < ult) crescente = 0;
        ult = x;
    }

    if (crescente) printf("A sequência é crescente\n");
    else if (decrescente) printf("A sequência é decrescente\n");
    else printf("A sequência não é crescente e nem decrescente\n");
}
