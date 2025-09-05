/*  Projeto 2
    Hélio Procailo Repczuk (2791137) e Matheus Pasqualotto de Souza (2791145)
    UTFPR 2025.1 - Engenharia de Computação
    Fundamentos de Programação
*/
#include "trabalho2.h"
#include <stdlib.h>
#include <math.h>

void mudaGanho(double* dados, int n_amostras, double ganho)
{
    for (int i = 0; i < n_amostras; i++)
    {
        /* Se representarmos o vetor dados em um gráfico, i é o valor de x, e dados[i] é o valor de y.
        Ao multiplicar dados[y] * ganho, estamos esticando os valores do gráfico no eixo y, o que é
        equivalente a multiplicar o ganho. */
        dados[i] *= ganho;
    }
}

void simulaSubAmostragem(double* dados, int n_amostras, int n_constantes)
{
    for (int i = 0; i < n_amostras; i += n_constantes)
    {
        // Armazena a amostra para não acessar dados[i] várias vezes
        double amostra = dados[i];

        // A cada i, substitui os próximos n_constantes valores pelo valor da amostra dados[i].
        for (int j = 0; j < n_constantes; j++)
        {
            dados[i+j] = amostra;
        }
    }
}

void estalos(double* dados, int n_amostras, int intervalo_max, double valor1)
{
    // Inicializa i com um valor no intervalo [0, intervalo_max-1]
    int i = rand() % intervalo_max;

    while (i < n_amostras)
    {
        dados[i] = valor1;
        valor1 = -valor1;
        i += (rand() % intervalo_max) + 1; // Sorteia um intervalo aleatório entre [1, intervalo_max] e incrementa i
    }
} 

double mediana(double x, double y, double z) {
    /* Dados a, b e c quaisquer, b é mediana <=> a <= b <= c ou c <= b <= a, então:
        (b >= a && b <= c) || (b >= c && b <= a)
        Testando isso para x, y, e z é possível descobrir a mediana. */
    if ((x < y && y < z) || (z < y && y < x))
        return y;
    else if ((y < x && x < z) || (z < x && x < y))
        return x;
    return z;
}

void removeEstalos(double* dados, int n_amostras) {
    double a = dados[0];
    double b = dados[1];
    for (int i = 2; i < n_amostras; i++)
    {
        double c = dados[i];
        double m = mediana(a, b, c);
        /* Utiliza as variáveis a e b para conseguir aplicar a mediana nos valores originais dos dados.
        Dessa forma, ao modificar dados[i-1], seu novo valor não afeta os valores de a, b e nem c que
        serão utilizados na próxima iteração. */
        dados[i-1] = m;
        a = b;
        b = c;
    }
}

void geraOndaQuadrada(double* dados, int n_amostras, int taxa, double freq)
{
    double meioPeriodo = (double)(taxa / (2.0 * freq));
    double erro = 0;
    int i = 0;
    int valor = 1;

    while (i < n_amostras)
    {
        double duracaoExata = meioPeriodo+erro;
        int duracaoAtual = (int)duracaoExata;
        // O erro é a diferença da duração (duracaoExata) e sua parte inteira (duracaoAtual)
        erro = duracaoExata - duracaoAtual;

        // Preenche os valores do meio período atual
        for (int j = 0; j < duracaoAtual && i < n_amostras; j++)
        {
            dados[i] = valor;
            i++;
        }
        valor = -valor; // Inverte o valor após o meio período
    }
}

void geraSenoide(double* dados, int n_amostras, int taxa, double freq, double fase)
{
    /* A função consiste em modificar a função sin(x) na forma: y = sin(offset + x * 2π * f/t), onde:
        offset = fase, f = freq e t = taxa. A cada valor de i, armazenamos sua imagem (y) no vetor de dados. */
    for (int i = 0; i < n_amostras; i++)
    {
        double delta = i * 2 * TRAB_PI * (freq/taxa);
        double x = fase + delta;
        double y = sin(x);
        dados[i] = y;
    }
}
