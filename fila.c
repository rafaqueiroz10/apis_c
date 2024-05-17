#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento;
    struct No* prox;
} No;

typedef struct Fila {
    No* inicio, *fim;
    int quantos;
} Fila;

Fila* criarFila ();
int filaVazia (Fila* f);
void menu ();
void inserir (Fila* f, int valor);
int remover (Fila* f);
double calculaMedia (Fila* f);
int somatorio (Fila* f);
int lenFila (Fila* f);
int getMaior (Fila* f);
int getMenor (Fila* f);
int* retornarVetor (Fila* f);
void printVetor (int* arr, int tam);
int getInicio (Fila* f);
int getFim (Fila* f);
void printFila (Fila* f);
int pesquisarElemento (Fila* f, int valor);
void esvaziarFila (Fila* f);

int main () {
    Fila* f = criarFila ();
    int opcao;
    menu ();
    printf ("Digite a opcao: ");
    scanf ("%d", &opcao);

    while (opcao != 13) {
        while (opcao != 1 && filaVazia (f)) {
            printf ("Erro!! Fila esta vazia!!\n");
            menu ();
            printf ("Digite a opcao: ");
            scanf ("%d", &opcao);
        }

        switch (opcao) {
            case 1: {
                int valor;
                printf ("Digite o valor a ser inserido: ");
                scanf ("%d", &valor); 
                inserir (f, valor);
                break;
            }
            case 2: printf ("%d removido da fila\n", remover (f)); break;
            case 3: printf ("Media dos elementos: %.1f\n", calculaMedia (f)); break;
            case 4: printf ("Soma dos elementos: %d\n", somatorio (f)); break;
            case 5: printf ("Tamanho da fila: %d valores\n", lenFila (f)); break;
            case 6: printf ("Maior valor da fila: %d\n", getMaior (f)); break;
            case 7: printf ("Menor valor da fila: %d\n", getMenor (f)); break;
            case 8: {
                int* arr = retornarVetor (f);
                printf ("Todos os dados da fila salvos pelo vetor:\n");
                printVetor (arr, lenFila (f));
                free (arr);
                break;
            }
            case 9: printf ("Elemento no início da fila: %d\n", getInicio (f)); break;
            case 10: printf ("Ultimo elemento da fila: %d\n", getFim (f)); break;
            case 11: {
                printf ("Todos os elementos exibidos pela fila:\n"); 
                printFila (f); 
                break;
            }
            case 12: {
                int valor;
                printf ("Digite o elemento a ser buscado: ");
                scanf ("%d", &valor);
                if (pesquisarElemento (f, valor)) 
                    printf ("Elemento %d encontrado\n", valor);
                else 
                    printf ("Elemento nao encontrado\n");

                break;
            }
        }
        menu ();
        printf ("Digite a opcao: ");
        scanf ("%d", &opcao);
    }
    esvaziarFila (f);

    return 0;
}

Fila* criarFila () {
    Fila* f = (Fila*) malloc (sizeof (Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->quantos = 0;
    return f;
}

int filaVazia (Fila* f) {
    return f->quantos == 0;
}

void menu () {
    printf ("Escolha uma opcao:\n");
    printf ("1 - Inserir um numero na fila\n");
    printf ("2 - Remover um numero na fila\n");
    printf ("3 - Calcular media dos valores na fila\n");
    printf ("4 - Calcular soma dos valores na fila\n");
    printf ("5 - Quantidade de elementos na fila\n");
    printf ("6 - Buscar maior valor na fila\n");
    printf ("7 - Buscar menor valor na fila\n");
    printf ("8 - Retornar e exibir todos os elementos na fila em um vetor\n");
    printf ("9 - Retornar elemento no inicio da fila\n");
    printf ("10 - Retornar elemento na fim da fila\n");
    printf ("11 - Exibir todos os elementos na fila\n");
    printf ("12 - Buscar um elemento na fila\n");
    printf ("13 - Sair\n");
}

void inserir (Fila* f, int valor) {
    No* novo = (No*) malloc (sizeof (No));
    novo->elemento = valor;

    if (filaVazia(f)) {
        f->fim = novo;
        f->inicio = novo;
        novo->prox = NULL;
    }
    else {
        f->fim->prox = novo;
        f->fim = novo;
        novo->prox = NULL;
    }
    f->quantos++;
}

int remover (Fila* f) {
    int numero = f->inicio->elemento;
    No* inicio = f->inicio;
    f->inicio = f->inicio->prox;
    free (inicio);
    f->quantos--;
    return numero;
}

double calculaMedia (Fila* f) {
    return somatorio(f) / lenFila(f);
}

int somatorio (Fila* f) {
    int soma = 0;
    for (No* aux = f->inicio; aux != NULL; aux = aux->prox) {
        soma += aux->elemento;
    }
    return soma;
}

int lenFila (Fila* f) {
    return f->quantos;
}

int getMaior (Fila* f) {
    No* aux = f->inicio;
    int maior = aux->elemento;
    aux = aux->prox;

    for (; aux != NULL; aux = aux->prox) {
        if (aux->elemento > maior) {
            maior = aux->elemento;
        }
    }
    return maior;
}

int getMenor (Fila* f) {
    No* aux = f->inicio;
    int menor = aux->elemento;
    aux = aux->prox;

    for (; aux != NULL; aux = aux->prox) {
        if (aux->elemento < menor) {
            menor = aux->elemento;
        }
    }
    return menor;
}

int* retornarVetor (Fila* f) {
    int* arr = (int*) malloc (lenFila (f) * sizeof (int));
    int indice = 0;
    for (No* aux = f->inicio; aux != NULL; aux = aux->prox) 
        arr[indice++] = aux->elemento;

    return arr;
}

void printVetor (int* arr, int tam) {
    for (int i = 0; i < tam-1; i++) 
        printf ("%d ", arr[i]);
    printf ("%d\n", arr[tam-1]);
}

int getInicio (Fila* f) {
    return f->inicio->elemento;
}

int getFim (Fila* f) {
    return f->fim->elemento;
}

void printFila (Fila* f) {
    for (No* aux = f->inicio; aux != NULL; aux = aux->prox) {
        printf ("%d\n", aux->elemento);
    }
}

int pesquisarElemento (Fila* f, int valor) {
    for (No* aux = f->inicio; aux != NULL; aux = aux->prox)
        if (aux->elemento == valor) 
            return 1;

    return 0;
}

void esvaziarFila (Fila* f) {
    No* prox, *aux;
    for (aux = f->inicio; aux != NULL; aux = prox) {
        prox = aux->prox;
        free (aux);
    }
    free (f);
}