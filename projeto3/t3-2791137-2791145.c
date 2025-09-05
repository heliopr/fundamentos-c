/*
    UTFPR - Engenharia de Computação 2025.1
    Fundamentos de Programação - Projeto 3
    Hélio Procailo Repczuk - 2791137
    Matheus Pasqualotto de Souza - 2791145
*/

#include <stdlib.h>
#include "trabalho3.h"

/*
    Verifica se algum vizinho de (x,y) já foi marcado com algum id, se sim a função
    retorna esse id, caso contrário retorna 0.
*/
int identificaVizinho(int **furos, int largura, int altura, int x, int y)
{
    // Vizinho de cima
    if (y > 0 && furos[y-1][x] != 0)
        return furos[y-1][x];

    // Vizinho de baixo
    if (y < largura-1 && furos[y+1][x] != 0)
        return furos[y+1][x];

    // Vizinho esquerdo
    if (x > 0 && furos[y][x-1] != 0)
        return furos[y][x-1];

    // Vizinho direito
    if (x < largura-1 && furos[y][x+1] != 0)
        return furos[y][x+1];

    return 0;
}

/*
    Esta função percorre a matriz furos e substitui todos os furos que tem o id
    passado para a função por novo_id.
*/
void substituiIds(int **furos, int largura, int altura, int id, int novo_id)
{
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            if (furos[y][x] == id)
                furos[y][x] = novo_id;
        }
    }
}

/*
    Se (x,y) faz parte de um grupo e um vizinho de (x,y) faz parte de um grupo
    diferente, então os grupos são vizinhos e logo fazem parte do mesmo furo,
    e devem ser mesclados em um único grupo.
*/
void substituiVizinho(int **furos, int largura, int altura, int id, int x_vizinho, int y_vizinho)
{
    int id_vizinho = furos[y_vizinho][x_vizinho];
    if (id_vizinho != 0 && id_vizinho != id)
        substituiIds(furos, largura, altura, id_vizinho, id);
}

/*
    Mescla todos os grupos grupos vizinhos de (x,y).
*/
void substituiVizinhos(int **furos, int largura, int altura, int x, int y, int id)
{
    if (y > 0)
        substituiVizinho(furos, largura, altura, id, x, y-1); // Vizinho de cima

    if (y < altura-1)
        substituiVizinho(furos, largura, altura, id, x, y+1); // Vizinho de baixo

    if (x > 0)
        substituiVizinho(furos, largura, altura, id, x-1, y); // Vizinho esquerdo

    if (x < largura-1)
        substituiVizinho(furos, largura, altura, id, x+1, y); // Vizinho direito
}

/*
    Retorna uma matriz alocada dinamicamente e guarda em cada posição o id do furo que
    cada pixel pertence.
*/
int **identificaFuros(Imagem1C *img)
{
    int altura = img->altura;
    int largura = img->largura;

    /* IMPORTANTE: se não zerar a memória alocada (com calloc) pode causar problemas. */
    int **furos = (int**)calloc(altura, sizeof(int*));
    for (int i = 0; i < img->altura; i++)
        furos[i] = (int*)calloc(largura, sizeof(int));

    int cont = 0;
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            /*
                Se encontrar um pixel branco que não foi associado a nenhum grupo,
                então encontra/cria algum grupo e associa a posição a esse grupo.
            */
            if (img->dados[y][x] >= 100 && furos[y][x] == 0)
            {
                int id = identificaVizinho(furos, largura, altura, x, y);
                if (id == 0) // Se não encontrar nenhum grupo vizinho, cria um novo grupo
                    id = ++cont;

                furos[y][x] = id;
            }
        }
    }

    // Percorre a matriz novamente mesclando todos os grupos adjacentes.
    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            int id = furos[y][x];
            if (id > 0)
                substituiVizinhos(furos, largura, altura, x, y, id);
        }
    }

    return furos;
}

/*
    Dado um id, encontra as posições (x,y) min e max onde esse id aparece.
*/
Rect encontraRetangulo(int **furos, int largura, int altura, int id)
{
    int x_min = largura+1, y_min = altura+1;
    int x_max = -1, y_max = -1;

    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            if (furos[y][x] == id)
            {
                furos[y][x] = 0; // Zera a posição para não checarmos mais
                if (x < x_min) x_min = x;
                if (x > x_max) x_max = x;
                if (y < y_min) y_min = y;
                if (y > y_max) y_max = y;
            }
        }
    }

    // Se não encontrou nenhuma posição com o id, retorna um Rect preenchido como -1
    if (x_min >= largura || y_min >= altura)
        return (Rect){-1, -1, -1, -1};

    Rect r = (Rect){(Coordenada){x_min, y_min}, (Coordenada){x_max, y_max}};
    return r;
}

/*
    A cada pixel que faz parte de furo que encontra, encontra o retangulo que envolve aquele furo.
*/
Rect *encontraRetangulos(int **furos, int largura, int altura, int *n_furos)
{
    int cont = 0;
    int alocado = 1;
    Rect *rects = (Rect*)malloc(sizeof(Rect)*alocado); // Aloca a lista de retangulos com 1 posição inicialmente

    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura; x++)
        {
            int id = furos[y][x];
            if (id > 0)
            {
                if (cont == alocado) // Se o vetor atingiu sua capacidade máxima, realoca o vetor com o dobro da capacidade
                {
                    alocado *= 2;
                    rects = (Rect*)realloc(rects, sizeof(Rect)*alocado);
                }
                rects[cont] = encontraRetangulo(furos, largura, altura, id);
                cont++;
            }
        }
    }

    // Se não encontrar nenhum furo, retorna NULL e seta n_furos para 0
    if (cont == 0)
    {
        free(rects);
        *n_furos = 0;
        return NULL;
    }

    *n_furos = cont;
    return rects;
}

// Rect *... > Rect* ...
Rect *encontraFuros(Imagem1C *mask, int *n_furos)
{
    // Primeiro identifica todos os furos, associando um id a cada um dos pixeis que fazem parte do furo
    int **furos = identificaFuros(mask);

    Rect *rects = encontraRetangulos(furos, mask->largura, mask->altura, n_furos);

    /*
        Desaloca a matriz de furos não vai ser usada, já que a única
        informação útil são as posições dos furos.
    */
    for (int i = 0; i < mask->altura; i++)
        free(furos[i]);
    free(furos);
    return rects;
}