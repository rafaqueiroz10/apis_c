#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento;
    struct No* prox;
    struct No* anterior;
} No;

typedef struct {
    No* inicio, *fim;
    int quantos;
} Lista;

Lista* criarLista ();
int listaVazia (Lista* li);
void inserirInicio (Lista* li, int valor);
void inserirFim (Lista* li, int valor);
void remover (Lista* li, int valor);
void printInicioFim (Lista* li);
void printFimInicio (Lista* li);
void esvaziarLista (Lista* li);

int main () {
    Lista* li = criarLista ();
    inserirInicio (li, 85);
    inserirInicio (li, 32);
    printInicioFim (li);
    inserirFim (li, 41);
    inserirFim (li, 41);
    inserirInicio (li, 12);
    printInicioFim (li);
    printFimInicio (li);
    remover (li, 12);
    remover (li, 41);
    printInicioFim (li);
    printFimInicio (li);
    printf ("Tamanho da lista: %d elementos\n", li->quantos);
    esvaziarLista (li); 

    return 0;
}

Lista* criarLista () {
    Lista* li = (Lista*) malloc (sizeof (Lista));
    if (li == NULL)
        return NULL;

    li->inicio = NULL;
    li->fim = NULL;
    li->quantos = 0;
    return li;
}

int listaVazia (Lista* li) {
    return li->quantos == 0;
}

void inserirInicio (Lista* li, int valor) {
    No* novo = (No*) malloc (sizeof (No));
    novo->elemento = valor;

    if (listaVazia (li)) {
        li->inicio = novo;
        li->fim = novo;
        novo->anterior = NULL;
        novo->prox = NULL;
    } 
    else {
        novo->prox = li->inicio;
        li->inicio->anterior = novo;
        novo->anterior = NULL;
        li->inicio = novo;
    }

    li->quantos++;
}

void inserirFim (Lista* li, int valor) {
    No* novo = (No*) malloc (sizeof (No));
    novo->elemento = valor;

    if (listaVazia (li)) {
        li->inicio = novo;
        li->fim = novo;
        novo->anterior = NULL;
        novo->prox = NULL;
    } 
    else {
        li->fim->prox = novo;
        novo->anterior = li->fim;
        li->fim = novo;
        li->fim->prox = NULL;
    }

    li->quantos++;
}

void remover (Lista* li, int valor) {
    if (listaVazia (li)) {
        printf ("Lista vazia!!\n");
        return;
    }
    for (No* aux = li->inicio; aux != NULL;) {
        if (aux->elemento == valor) {
            if (aux == li->inicio) {
                No* prox = li->inicio->prox;
                prox->anterior = NULL;
                li->inicio = prox;
                free (aux);
                aux = li->inicio;
            }
            else if (aux == li->fim) {
                No* anterior = li->fim->anterior;
                anterior->prox = NULL;
                li->fim = anterior;
                free (aux);
                aux = NULL;
            }
            else {
                No* anterior = aux->anterior;
                No* proximo = aux->prox;
                proximo->anterior = anterior;
                anterior->prox = proximo;
                free (aux);
                aux = proximo;
            }
            li->quantos--;
        }
        else {
            aux = aux->prox;
        }
    }
}

void printInicioFim (Lista* li) {
    if (listaVazia (li)) {
        printf ("Lista vazia!!\n");
        return;
    }
    for (No* aux = li->inicio; aux != NULL; aux = aux->prox) 
        printf ("%d ", aux->elemento);
    printf ("\n"); 
}

void printFimInicio (Lista* li) {
    if (listaVazia (li)) {
        printf ("Lista vazia!!\n");
        return;
    }
    for (No* aux = li->fim; aux != NULL; aux = aux->anterior) 
        printf ("%d ", aux->elemento);
    printf ("\n");
}

void esvaziarLista (Lista* li) {
    for (No* prox, *aux = li->inicio; aux != NULL; aux = prox) {
        prox = aux->prox;
        free (aux);
    }
    free (li);
}
