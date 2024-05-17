#include <stdio.h>
#include <stdlib.h>

int* criarVetor (int tam) {
    return (int*) malloc (tam * sizeof (int));
}

void carregarVetor (int* v, int tam) {
    for (int i = 0; i < tam; i++) 
        scanf ("%d", &v[i]);
}

int somatorio (int* v, int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) 
        soma += v[i];

    return soma;
}

void printarVetor (int* v, int tam) {
    for (int i = 0; i < tam; i++) {
        printf ("%d\n", v[i]);
    }
}