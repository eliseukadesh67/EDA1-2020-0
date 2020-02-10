#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int desempilha(celula *p, int *y);

celula *init_stack()
{
    celula *topo = malloc(sizeof(celula));
    if (topo == NULL)
    {
        exit(1);
    }
    topo->prox = NULL;
    return topo;
}

int desempilha(celula *p, int *y)
{
    if (p->prox == NULL)
    {
        return 0;
    }
    celula *lixo = p->prox;
    *y = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}
/* void push(celula *topo, int x)
{
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL)
    {
        exit(1);
    }
    novo->dado = x;
    novo->prox = topo->prox;
    topo->prox = novo;
}

int main()
{

    int x;
    celula *p = init_stack();
    push(p, 3);
    push(p, 4);
    push(p, 5);
    printf("Topo da fila : %d\n", p->prox->dado);
    printf("%d\n", desempilha(p, &x));
    printf("Dado removido : %d\n", x);
    printf("Topo da fila : %d\n", p->prox->dado);
    printf("%d\n", desempilha(p, &x));
    printf("Dado removido : %d\n", x);
    printf("Topo da fila : %d\n", p->prox->dado);
    printf("%d\n", desempilha(p, &x));
    printf("Dado removido : %d\n", x);
    printf("%d\n", desempilha(p, &x));
    free(p);
} */