#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void init(celula **new)
{
    new = malloc(sizeof(*celula));
    new->prox = NULL;
    new->dado = 4;
}

int main()
{
    celula *new;
    init(&new);
    printf("%d\n", new->dado);
    free(new);
    return 0;
}