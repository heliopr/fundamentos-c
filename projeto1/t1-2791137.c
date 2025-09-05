// Hélio Procailo Repczuk
#include "trabalho1.h"
#include <math.h>

float calculaValorDevido(float peso, float custo_fixo, float preco_kg, float largura_faixa, float desconto_faixa, float desconto_max) {
    float preco_g = preco_kg/1000;
    float preco = 0;
    int i = 0;
    while (peso > 0) {
        float delta = largura_faixa;
        if (delta > peso)
            delta = peso; // Limita o delta para que não ultrapasse o peso total

        float desconto = i * desconto_faixa; // Calcula o desconto atual
        if (desconto > desconto_max)
            desconto = desconto_max; // Limita o desconto para que ele não ultrapasse o desconto máximo
        preco += delta * preco_g * (1-desconto); // Se o desconto é de 0.1, o preco deve ser multiplicado por (1-0.1)
        peso -= delta;

        i++;
    }

    return preco + custo_fixo;
}

unsigned int fourcc(char c1, char c2, char c3, char c4) {
    // Ao fazer c2<<8 estamos deslocando c2 8 bits para a esquerda e concatenando com c1, que ocupa os primeiros 8 bits, e assim sucessivamente...
    // Retornando um número de 4 bytes onde o primeiro byte é c1, o segundo é c2, o terceiro é c3, e o último é c4
    return (unsigned int) (c1 | (c2 << 8) | (c3 << 16) | (c4 << 24));
}

double raizAproximada(double x, double erro_minimo) {
    // Se x >= 1, sua raiz com certeza será maior do que 1 e menor do que x
    double min = 1, max = x;

    // Se x < 1, sua raiz é maior do que x e menor do que 1
    if (x < 1) {
        min = x;
        max = 1;
    }

    double raiz = (min+max)/2; // Primeiro chute
    double y = raiz*raiz;
    while (fabs(x-y) >= erro_minimo) {
        if (y > x)
            max = raiz; // Se o quadrado do chute > x, então a raiz de x < chute
        else
            min = raiz; // Se o quadrado do chute < x, então a raiz de x > chute

        raiz = (min+max)/2;
        y = raiz*raiz; // Guarda o resultado para evitar computar o mesmo quadrado várias vezes
    }
    return raiz;
}