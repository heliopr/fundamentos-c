#include <stdio.h>
#include <math.h>

#define RANGE 100
#define STEP 0.01
#define TOL 1e-10
#define DELTA 1e-10
#define MAX_ROOTS 256

double f(double x) {
    double y = sin(x);
    return y;
}


#define ABS(x) (((x)<0)?-(x):(x))
#define EQUAL(x, y) (ABS((x)-(y)) <= TOL)

double derive(double x0) {
    double y1 = f(x0 - DELTA);
    double y2 = f(x0 + DELTA);
    return (y2-y1)/(2*DELTA);
}

double findRoot(double x0) {
    double x = x0;
    double y = f(x);
    while (!EQUAL(y, 0)) {
        double derivative = derive(x);
        if (EQUAL(derivative, 0))
            break;

        x = x - (y/derivative);
        y = f(x);
    }
    return x;
}

void main() {
    double roots[MAX_ROOTS] = {0};
    int num_roots = 0;

    for (int i = 0; i < (RANGE*2)/STEP; i++) {
        double x = -RANGE + (i*STEP);
        double root = findRoot(x);
        if (!EQUAL(f(root), 0)) continue;

        int new_root =  1;
        for (int j = 0; j < num_roots; j++) {
            if (EQUAL(roots[j], root)) {
                new_root = 0;
                break;
            }
        }
        if (new_root) {
            roots[num_roots] = root;
            num_roots++;
            if (num_roots == MAX_ROOTS) {
                printf("Número máximo de raízes alcançado, parando busca... (AUMENTE MAX_ROOTS)\n");
                break;
            }
        }
    }

    printf("%d raízes encontradas\n", num_roots);
    printf("Mostrar? (S/n) ");
    char c; scanf("%c", &c);
    if (c == 10 || c == 's' || c == 'S') {
        for (int i = 0; i < num_roots; i++) {
            printf("%.10lf\n", roots[i]);
        }
    }
}