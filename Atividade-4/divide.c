#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void free_list(celula *head);
celula *init();
celula *incluiu(celula *le, int x);
void divide_lista(celula *l, celula *l1, celula *l2);

void free_list(celula *head)
{
    celula *p, *aux;
    p = head;

    while (p)
    {
        aux = p->prox;
        printf("Desalocando\n");
        free(p);
        p = aux;
    }
}
celula *init()
{
    celula *new = malloc(sizeof(celula));
    new->prox = NULL;
    return new;
}
celula *inclui(celula *le, int x)
{
    celula *new = init();
    new->dado = x;
    celula *aux = le;
    while (aux->prox)
    {
        aux = aux->prox;
    }

    aux->prox = new;
}

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
void divide_lista(celula *l, celula *l1, celula *l2)
{
    celula *p = l, *p1 = l1, *p2 = l2;

    //imprime(l);
    while (p->prox)
    {

        celula *paux = p->prox;

        if (((p->prox->dado) % 2) == 0)
        {
            //printf("Par %d\n", p->prox->dado);
            p2->prox = p->prox;
            p2 = p2->prox;
        }
        else
        {
            //printf("Impar %d\n", p->prox->dado);
            p1->prox = p->prox;
            p1 = p1->prox;
        }
        p = p->prox;
    }

    p1->prox = NULL;
    p2->prox = NULL;

    /*imprime(l);
    imprime(l1);
    imprime(l2); */
}
int main()
{
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    inclui(le, 2);
    inclui(le, 3);
    inclui(le, 4);
    inclui(le, 5);
    inclui(le, 7);
    inclui(le, 9);
    celula *l1 = init();
    celula *l2 = init();
    imprime(le);
    imprime(l1);
    imprime(l2);
    divide_lista(le, l1, l2);
    imprime(l1);
    imprime(l2);
    free_list(le);
    free_list(l1);
    free_list(l2);

    return 0;
}