#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int num;
    struct No* prox;
} No;

typedef struct Pilha {
    No* topo, *base;
    int quant;
} Pilha;

Pilha* criarPilha ();
void menu ();
int pilhaVazia (Pilha* p);
void empilhar (Pilha* p, int valor);
int desempilhar (Pilha* p);
int calculaMedia (Pilha* p);
int somatorio (Pilha* p);
int lenPilha (Pilha* p);
int getMenorValor (Pilha* p);
int getMaiorValor (Pilha* p);
int* retornarVetor (Pilha* p);
void printVetor (int* vetor, int tam);
int getTopo (Pilha* p);
int getBase (Pilha* p);
void printStack (Pilha* p);
void esvaziarPilha (Pilha* p);

int main () {
    Pilha* p = criarPilha ();
    int opcao;
    menu ();
    printf ("Digite a opcao: ");
    scanf ("%d", &opcao);

    while (opcao != 12) {
        while (opcao != 1 && pilhaVazia (p)) {
            printf ("Erro: Pilha vazia!!\n");
            menu ();
            printf ("Digite a opcao: ");
            scanf ("%d", &opcao);
        }
        switch (opcao) {
            case 1: {
                int valor;
                printf ("Insira o valor: ");
                scanf ("%d", &valor);
                empilhar (p, valor);
                break;
            }
            case 2: printf ("%d desempilhado\n", desempilhar (p)); break;
            case 3: printf ("Media dos elementos: %d\n", calculaMedia (p)); break;
            case 4: printf ("Soma dos elementos: %d\n", somatorio (p)); break;
            case 5: printf ("Tamanho da pilha: %d valores\n", lenPilha (p)); break;
            case 6: printf ("Maior valor da pilha: %d\n", getMaiorValor (p)); break;
            case 7: printf ("Menor valor da pilha: %d\n", getMenorValor (p)); break;
            case 8: {
                int* arr = retornarVetor (p);
                printf ("Todos os dados da pilha salvos pelo vetor:\n");
                printVetor (arr, lenPilha (p));
                free (arr);
                break;
            }
            case 9: printf ("Elemento no topo da pilha: %d\n", getTopo (p)); break;
            case 10: printf ("Elemento na base da pilha: %d\n", getBase (p)); break;
            case 11: {
                printf ("Todos os elementos exibidos pela pilha:\n"); 
                printStack (p); 
                break;
            }
        }
        menu ();
        printf ("Digite a opcao: ");
        scanf ("%d", &opcao);
    }
    esvaziarPilha (p);
}

Pilha* criarPilha () {
    Pilha* p = (Pilha*) malloc (sizeof (Pilha));
    p->topo = NULL;
    p->base = NULL;
    p->quant = 0;
    return p;
}

void menu () {
    printf ("Escolha uma opcao:\n");
    printf ("1 - Inserir um numero na pilha\n");
    printf ("2 - Desempilhar um numero da pilha\n");
    printf ("3 - Calcular media dos valores da pilha\n");
    printf ("4 - Calcular soma dos valores da pilha\n");
    printf ("5 - Quantidade de elementos na pilha\n");
    printf ("6 - Buscar maior valor da pilha\n");
    printf ("7 - Buscar menor valor da pilha\n");
    printf ("8 - Retornar e exibir todos os elementos da pilha em um vetor\n");
    printf ("9 - Retornar elemento no topo da pilha\n");
    printf ("10 - Retornar elemento na base da pilha\n");
    printf ("11 - Exibir todos os elementos da pilha\n");
    printf ("12 - Sair\n");
}

int pilhaVazia (Pilha* p) {
    return p->topo == NULL;
}

void empilhar (Pilha* p, int valor) {
    No* novo = (No*) malloc (sizeof (No));
    novo->num = valor;

    if (pilhaVazia (p)) {
        p->base = novo;
        novo->prox = NULL;
    } 
    else 
        novo->prox = p->topo;

    p->topo = novo;
    p->quant++;
}

int desempilhar (Pilha* p) {
    int numero = p->topo->num;
    No* aux = p->topo;
    p->topo = p->topo->prox;
    free (aux);
    p->quant--;
    return numero;
}

int calculaMedia (Pilha* p) {
    int soma = somatorio (p);
    int len = lenPilha (p);
    return soma / len;
}

int somatorio (Pilha* p) {
    int soma = 0;
    for (No* aux = p->topo; aux != NULL; aux = aux->prox) 
        soma += aux->num;    

    return soma;
}

int lenPilha (Pilha* p) {
    return p->quant;
}

int getMenorValor (Pilha* p) {
    No* aux = p->topo;
    int menor = aux->num;
    aux = aux->prox;

    while (aux != NULL) {
        if (aux->num < menor)
            menor = aux->num;

        aux = aux->prox;
    }

    return menor;
}

int getMaiorValor (Pilha* p) {
    No* aux = p->topo;
    int maior = aux->num;
    aux = aux->prox;

    while (aux != NULL) {
        if (aux->num > maior) 
            maior = aux->num;

        aux = aux->prox;
    }

    return maior;
}

int* retornarVetor (Pilha* p) {
    int* arr = (int*) malloc (lenPilha (p) * sizeof (int));
    int indice = 0;
    for (No* aux = p->topo; aux != NULL; aux = aux->prox) {
        arr[indice] = aux->num;
        indice++;
    }
    return arr;
}

int getTopo (Pilha* p) {
    return p->topo->num;
}

int getBase (Pilha* p) {
    return p->base->num;
}

void printStack (Pilha* p) {
    for (No* aux = p->topo; aux != NULL; aux = aux->prox) {
        printf ("%d\n", aux->num);
    }
}

void esvaziarPilha (Pilha* p) {
    No* aux2;
    for (No* aux1 = p->topo; aux1 != NULL; aux1 = aux2) {
        aux2 = aux1->prox;
        free (aux1);
    }
    free (p);
}

void printVetor (int* arr, int tam) {
    for (int i = 0; i < tam-1; i++)
        printf ("%d ", arr[i]);
    printf ("%d\n", arr[tam-1]);
}