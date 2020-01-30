#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *busca(celula *le, int x);
celula *busca_rec(celula *le, int x);
celula *new_node();
celula *init_list();
void add_node(celula *le, int x);
void free_list(celula *le);

celula *init_list()
{
    celula *head = malloc(sizeof(celula));
    head->prox = NULL;

    return head;
}
celula *new_node(int x)
{
    celula *novo = malloc(sizeof(celula));
    novo->prox = NULL;
    novo->dado = x;
    return novo;
}

void add_node(celula *le, int x)
{
    celula *new = new_node(x);
    celula *aux = le;
    while (aux->prox)
    {
        aux = aux->prox;
    }

    aux->prox = new;
}
void free_list(celula *head)
{
    celula *p, *aux;
    p = head;

    while (p)
    {
        aux = p->prox;
        printf("Desalocando %d\n", p->dado);
        free(p);
        p = aux;
    }
}
celula *busca(celula *le, int x)
{
    celula *aux = le;
    while (aux->prox)
    {
        if (aux->prox->dado == x)
        {
            return aux->prox;
        }
        else
        {
            aux = aux->prox;
        }
    }
}
celula *busca_rec(celula *le, int x)
{
    celula *aux = le;

    if (aux->prox == NULL)
    {
        return NULL;
    }
    else
    {
        if (aux->prox->dado == x)
        {
            return aux->prox;
        }
        else
        {
            return busca_rec(aux->prox, x);
        }
    }
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

int main()
{
    celula *ocurrence;
    celula *le = init_list();
    add_node(le, 1);
    add_node(le, 2);
    add_node(le, 3);
    add_node(le, 6);
    add_node(le, 4);
    free_list(le);
    return 0;
}