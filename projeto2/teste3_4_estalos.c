/*============================================================================*/
/* Exemplo: adiciona e remove ru�do. */

#include <stdlib.h>
#include "wavfile.h"

#include "trabalho2.h"

/*============================================================================*/

#define INPUT_FILE "data/sonic1.wav"
#define OUTPUT_FILE1 "data/teste3_estalos_meu.wav"
#define OUTPUT_FILE2 "data/teste4_removeEstalos_meu.wav"

/*============================================================================*/

int main ()
{
	WavHeader header; /* Cabe�alho para as informa��es sobre o arquivo. */
	double* data_l; /* Dados do canal esquerdo. Alocado na readWavFile. */
	double* data_r; /* Dados do canal direito. Alocado na readWavFile, se necess�rio. */
    int n_amostras; /* N�mero de amostras nos buffers. */

    /* L� um arquivo. */
    n_amostras = readWavFile (INPUT_FILE, &header, &data_l, &data_r);
    if (!n_amostras)
    {
        printf ("Erro lendo %s.\n", INPUT_FILE);
        return (1);
    }

    /* Adiciona ru�do (deixando o per�odo diferente na esquerda e na direita para ficar bem percept�vel). */
    estalos (data_l, n_amostras, 44100, -1);
    estalos (data_r, n_amostras, 44100*4, 0.8);

    if (!writeWavFile (OUTPUT_FILE1, &header, data_l, data_r))
    {
        printf ("Erro salvando %s.\n", OUTPUT_FILE1);
        return (1);
    }

    /* Remove ru�do. */
    removeEstalos (data_l, n_amostras);
    removeEstalos (data_r, n_amostras);

    if (!writeWavFile (OUTPUT_FILE2, &header, data_l, data_r))
    {
        printf ("Erro salvando %s.\n", OUTPUT_FILE2);
        return (1);
    }

    /* Desaloca os vetores. O direito s� vai ter sido alocado se o arquivo for est�reo. */
	free (data_l);
	if (data_r)
        free (data_r);

	return (0);
}

/*============================================================================*/
