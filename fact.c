#include <stdio.h>
#include <stdlib.h>
#include "gmp.h"

void fact(int n, mpz_t p) {
    mpz_set_ui(p, 1);
    for (int i = 0; i < n; i++) {
        mpz_mul_ui(p, p, i+1);
    }
}

int main(int argc, char * argv[]) {
    if (argc <= 1) {
        printf("Usage: %s <number>\n", argv[0]);
        return -1;
    }

    int n = atoi(argv[1]);
    mpz_t p;
    mpz_init(p);
    fact(n, p);

    mpz_out_str(stdout, 10, p);
    printf("\n");
    mpz_clear(p);
}