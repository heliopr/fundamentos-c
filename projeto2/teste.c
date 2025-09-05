#include <stdio.h>
#include <math.h>

#include "wavfile.h"

#define TOL 1e-4

void teste(char *ref, char *meu) {
    printf("Testando %s e %s\n", ref, meu);
    WavHeader header_ref;
    double *dados_l_ref;
    double *dados_r_ref;
    int n_ref;

    n_ref = readWavFile(ref, &header_ref, &dados_l_ref, &dados_r_ref);
    if (!n_ref)
    {
        printf ("Erro lendo %s.\n", ref);
        return;
    }

    WavHeader header_meu;
    double *dados_l_meu;
    double *dados_r_meu;
    int n_meu;

    n_meu = readWavFile(meu, &header_meu, &dados_l_meu, &dados_r_meu);
    if (!n_meu)
    {
        printf ("Erro lendo %s.\n", meu);
        return;
    }

    if (n_meu != n_ref) {
        printf("Diferença de bytes: %d\n", n_ref-n_meu);
    }

    int cont = 0;
    for (int i = 0; i < n_ref; i++) {
        if (fabs(dados_l_meu[i]-dados_l_ref[i]) > TOL) {
            cont++;
            printf("%.8f %.8f\n", dados_l_meu[i], dados_l_ref[i]);
        }
        if (fabs(dados_r_meu[i]-dados_r_ref[i]) > TOL) {
            printf("%.8f %.8f\n", dados_r_meu[i], dados_r_ref[i]);
            cont++;
        }
    }
    printf("DIFF: %d\n", cont);
}

int main() {
    teste("data/teste2_subamostra_ref.wav", "data/teste2_subamostra_meu.wav");
}