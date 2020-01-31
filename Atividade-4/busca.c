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
    p = head->prox;

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
    celula *aux = le->prox;

    while (aux)
    {
        if (aux->dado == x)
        {
            return aux;
        }

        aux = aux->prox;
    }
    return aux;
}
celula *busca_rec(celula *le, int x)
{
    celula *aux = le;
    if (aux == NULL)
    {
        return aux;
    }
    else
    {
        if (aux->dado == x)
        {
            return aux;
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

/* int main()
{
    celula *le = init_list();
    celula *ocurrence;
    add_node(le, 1);
    add_node(le, 2);
    add_node(le, 3);
    add_node(le, 6);
    add_node(le, 4);
    imprime(le);
    ocurrence = busca(le, 4);
    if (ocurrence)
    {
        printf("%d Encontrado.\n", ocurrence->dado);
    }
    else
    {
        printf("Não Encontrado.\n");
    }
    free_list(le);
    printf("Desalocando a cabeça.\n");
    free(le);
    return 0;
} */