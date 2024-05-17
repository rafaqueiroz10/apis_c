#include <stdio.h>

void troca (int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort (int* v, int tam) {
    for (int i = 0; i < tam; i++) 
        for (int j = i + 1; j < tam; j++) 
            if (v[i] > v[j]) 
                troca (&v[i], &v[j]);
}

void selectionSort (int* v, int tam) {
    int menor;
    for (int i = 0; i < tam; i++) {
        menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (v[j] < v[menor]) 
                menor = j;

            troca (&v[menor], &v[i]);
        }
    }
}