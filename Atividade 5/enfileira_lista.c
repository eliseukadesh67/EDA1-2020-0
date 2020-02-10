#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *enfileira(celula *f, int x)
{
    celula *nova = malloc(sizeof(celula));
    if (nova != NULL)
    {
        nova->prox = f->prox;
        f->prox = nova;
        f->dado = x;
    }

    return nova;
}

/* int main()
{
    celula *f = malloc(sizeof(celula));
    printf("%d\n", enfileira(f, 9)->dado);
    printf("Primeiro da fila : %d\n", f->prox->dado);
    printf("%d\n", enfileira(f, 10)->dado);
    printf("Primeiro da fila : %d\n", f->prox->dado);
    free(f->prox->prox);
    free(f->prox);
    free(f);
} */