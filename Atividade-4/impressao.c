#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le)
{
    celula *aux = le->prox;

    while (aux)
    {
        printf("%d -> ", aux->dado);
        aux = aux->prox;
    }

    printf("NULL\n");
}
void imprime_rec(celula *le)
{
    celula *aux = le;

    if (!aux->prox)
    {
        printf("NULL\n");
        return;
    }
    else
    {
        printf("%d -> ", aux->prox->dado);
        imprime(aux->prox);
    }
}

int main()
{
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    celula *p1 = malloc(sizeof(celula));
    p1->dado = 2;
    p1->prox = NULL;
    le->prox = p1;
    imprime_rec(le);
    free(p1);
    free(le);

    return 0;
}