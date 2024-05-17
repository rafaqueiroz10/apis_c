#include <stdio.h>
#include <stdlib.h>
#include "vetores.c"
#include "ordenacao.c"

int main () {
    int* v = criarVetor (5);
    carregarVetor (v, 5);
    printf ("%d\n", somatorio (v, 5));
    selectionSort (v, 5);
    printarVetor (v, 5);
    free (v);
    return 0;
}