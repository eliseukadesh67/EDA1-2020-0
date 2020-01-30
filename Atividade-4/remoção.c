#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

int remove_depois(celula *p);
void remove_elemento(celula *le, int x);

int remove_depois(celula *p)
{
    celula *aux = p->prox;

    if (aux == NULL)
    {
        return -1;
    }
    else
    {
        celula *aux2 = aux->prox;
        free(p->prox);
        p->prox = aux2;
        return 0;
    }
}
void remove_elemento(celula *le, int x)
{
    celula *aux = le;

    if (aux == NULL)
    {
        return;
    }
    else
    {
        if (aux->prox->dado == x)
        {
            celula *aux2 = aux->prox;
            aux->prox = aux->prox->prox;
            free(aux2);
        }
        else
        {
            remove_elemento(aux->prox, x);
        }
    }
}
void remove_todos_elementos(celula *le, int x)
{
    celula *p = le;

    while (p)
    {

        celula *q = p->prox;

        if (p->prox->dado == x)
        {
            p->prox = p->prox->prox;
            free(q);
        }

        p = p->prox;
    }
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
} */

/* int main()
{
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    celula *p1 = malloc(sizeof(celula));
    p1->prox = NULL;
    p1->dado = 1;
    celula *p2 = malloc(sizeof(celula));
    p2->prox = NULL;
    p2->dado = 2;
    celula *p3 = malloc(sizeof(celula));
    p3->prox = NULL;
    p3->dado = 1;
    celula *p4 = malloc(sizeof(celula));
    p4->prox = NULL;
    p4->dado = 1;
    le->prox = p1;
    p1->prox = p2;
    p2->prox = p3;
    p3->prox = p4;

    imprime(le);
    //remove_todos_elementos(le, 1);
    printf("%d\n", remove_depois(p2));
    //printf("%d\n", remove_depois(p1));
    imprime(le);
    remove_todos_elementos(le, 1);
    imprime(le);

    free(p2);
    free(p1);
    free(le);

    return 0;
} */