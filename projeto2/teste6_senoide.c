/*============================================================================*/
/* Exemplo: Gera sinais - com senoides. */

#include <stdlib.h>
#include <math.h>
#include "wavfile.h"

#include "trabalho2.h"

/*============================================================================*/

#define OUTPUT_FILE "data/teste6_senoide_meu.wav"

#define BASE_TEMPO 11605 /* Número de amostras em 1/2 batida a 114 bpm. */
#define N_BEATS 32

// Notas
#define D 146.83
#define EB 155.56
#define E 164.81
#define F 174.61
#define FS 185.00
#define G 196.00
#define GS 207.65
#define A 220.00
#define BB 233.08
#define B 246.94
#define C 261.63
#define CS 277.18

/*============================================================================*/

int main ()
{
	WavHeader header;
	double* dados_l; /* Dados do canal esquerdo. Alocado na generateSignal. */
	double* dados_r; /* Dados do canal direito. Alocado na generateSignal. */

    /* Ponteiros usados para se deslocar em dados_l e dados_r. */
    double* ptr_l;
    double* ptr_r;

	int n_amostras = BASE_TEMPO*N_BEATS;
	int i;

    /* Gera um novo sinal. */
	header = generateSignal (&n_amostras, 2, 44100, &dados_l, &dados_r);
	if (!dados_l || !dados_r || n_amostras != BASE_TEMPO*N_BEATS)
    {
        printf ("Erro gerando sinal.\n");
        return (1);
    }

    // Limpa os vetores.
    for (i = 0; i < n_amostras; i++)
    {
        dados_l [i] = 0;
        dados_r [i] = 0;
    }

    // Cria a música a partir de ondas quadradas.
    ptr_l = dados_l;
    ptr_r = dados_r;

	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, G, 0);
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, D, 0);
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, BB, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, F, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, C, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, G, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*3;
	ptr_r += BASE_TEMPO*3;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, G, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, D, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, BB, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, F, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
    geraSenoide (ptr_l, BASE_TEMPO, 44100, CS, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO, 44100, GS, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO;
	ptr_r += BASE_TEMPO;
    geraSenoide (ptr_l, BASE_TEMPO*2, 44100, C, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, G, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*4;
	ptr_r += BASE_TEMPO*4;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, G, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, D, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, BB, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, F, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
	geraSenoide (ptr_l, BASE_TEMPO*2, 44100, C, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*2, 44100, G, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*3;
	ptr_r += BASE_TEMPO*3;
	geraSenoide (ptr_l, BASE_TEMPO, 44100, BB, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO, 44100, F, asin (*(ptr_r-1)));
	ptr_l += BASE_TEMPO*2;
	ptr_r += BASE_TEMPO*2;
    geraSenoide (ptr_l, BASE_TEMPO*7, 44100, G, asin (*(ptr_l-1)));
	geraSenoide (ptr_r, BASE_TEMPO*7, 44100, D, asin (*(ptr_r-1)));

    mudaGanho (dados_l, n_amostras, 0.6);
    mudaGanho (dados_r, n_amostras, 0.6);

    /* Salva */
    if (!writeWavFile (OUTPUT_FILE, &header, dados_l, dados_r))
    {
        printf ("Erro salvando %s.\n", OUTPUT_FILE);
        return (1);
    }

    /* Desaloca os vetores. */
	free (dados_l);
    free (dados_r);

	return (0);
}

/*============================================================================*/
