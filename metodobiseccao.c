#include <stdio.h>
#include <math.h>

#define STEP 0.1                 // Incremento a cada iteração
#define ITERATIONS 20            // O número máximo de iterações para aproximar a raiz
#define RANGE 100                // Vai de -RANGE até +RANGE
#define TOL (1.0/1000000.0)      // Tolerância para considerar 2 raízes iguais, se |x1-x2| <= TOL as 2 raízes são consideradas iguais

// Defina a função aqui
// Exemplo: x² - 3x - 4
double f(double x) {
    return pow(x, 2) - (3*x) - 4;
    //return (0.15 * x * x) + sin(3*x) - 0.5;
}


#define ABS(x) (((x)<0)?-(x):(x))

double encontrarRaiz(double a, double b, int i) {
    double c = (a+b)/2;
    if (i == ITERATIONS || ABS(b-a) <= TOL) return c;

    double ya = f(a);
    double yb = f(b);
    double yc = f(c);
    int cresc = yb > ya;

    if (yc > 0) encontrarRaiz(cresc?a:c, cresc?c:b, i+1);
    else if (yc < 0) encontrarRaiz(cresc?c:a, cresc?b:c, i+1);
    else return c;
}

int main()
{
    double ult = -RANGE -1;
    int n = 0;
    for (int i = 0; i < (RANGE*2)/STEP; i++) {
        double a = -RANGE + (i * STEP);
        double b = a + STEP;
        double ya = f(a);
        double yb = f(b);

        if (ya*yb <= 0) {
            double raiz = encontrarRaiz(a, b, 0);
            if (ABS(raiz-ult) > TOL) {
                printf("Provável raiz encontrada: %.6f\n", raiz);
                n += 1;
                ult = raiz;
            }
        }
    }
    printf("Total de raízes: %d\n", n);
    return 0;
}