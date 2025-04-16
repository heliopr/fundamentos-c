#include <stdio.h>

int checar_horario(int h, int m, int s) {
    if (h < 0 || h > 59) {
        printf("Hora inválida.\n");
        return 0;
    }

    if (m < 0 || m > 59) {
        printf("Minuto inválido.\n");
        return 0;
    }

    if (s < 0 || s > 59) {
        printf("Segundo inválido.\n");
        return 0;
    }

    return 1;
}

int main() {
    printf("Digite um horário (hora:minuto:segundo)\n");
    int h1, m1, s1;
    scanf("%d:%d:%d", &h1, &m1, &s1);

    if (!checar_horario(h1, m1, s1)) return 1;

    printf("Digite outro horário (hora:minuto:segundo)\n");
    int h2, m2, s2;
    scanf("%d:%d:%d", &h2, &m2, &s2);

    if (!checar_horario(h2, m2, s2)) return 1;

    int h = 0, m = 0, s = 0;

    // Soma os segundos
    s = s1+s2;
    m += s/60;
    s = s%60;
    
    // Soma os minutos
    m += m1+m2;
    h += m/60;
    m = m%60;

    // Soma as horas
    h += h1+h2;

    printf("Resultado: %02d:%02d:%02d\n", h, m , s);
}