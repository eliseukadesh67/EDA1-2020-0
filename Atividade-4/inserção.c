#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio(celula *le, int x);
void insere_antes(celula *le, int x, int y);

void insere_inicio(celula *le, int x)
{
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    novo->dado = x;
    celula *aux = le;

    if (le->prox == NULL)
    {
        le->prox = novo;
    }
    else
    {
        novo->prox = le->prox;
        le->prox = novo;
    }
}
void insere_antes(celula *le, int x, int y)
{
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    novo->dado = x;
    celula *aux = le, *aux2 = le->prox;

    while (aux2 != NULL && aux2->dado != y)
    {
        aux = aux2;
        aux2 = aux2->prox;
    }

    novo->prox = aux2;
    aux->prox = novo;
}
/* void imprime(celula *le)
{
    celula *aux = le->prox;

    while (aux)
    {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }

    printf("NULL\n");
}
int main()
{
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    celula *p1 = malloc(sizeof(celula));
    p1->dado = 2;
    p1->prox = NULL;
    le->prox = p1;
    insere_inicio(le, 8);
    insere_antes(le, 4, 8);
    insere_antes(le, 99, 2);
    insere_antes(le, 77, 8);
    insere_antes(le, 66, 10);
    insere_inicio(le, 3);
    imprime(le);
    free(p1);
    free(le);

    return 0;
} */