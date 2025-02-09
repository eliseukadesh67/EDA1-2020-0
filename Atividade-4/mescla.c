#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *new_node();
celula *init_list();
void add_node(celula *le, int x);
void free_list(celula *le);
void mescla_listas(celula *l1, celula *l2, celula *l3);

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
void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    celula *aux1 = l1;
    celula *aux2 = l2;
    celula *aux3 = l3;
    aux2 = aux2->prox, aux1 = aux1->prox;
    while (aux1 && aux2)
    {
        if (aux1->dado < aux2->dado)
        {
            //printf("l1 atual : %d\n", aux1->prox->dado);
            aux3->prox = aux1;
            aux1 = aux1->prox;
            aux3 = aux3->prox;
            //printf("l3 atual : %d\n", l3->prox->dado);
        }
        else
        {
            aux3->prox = aux2;
            aux2 = aux2->prox;
            aux3 = aux3->prox;
        }
    }

    if (aux1)
    {
        aux3->prox = aux1;
    }

    if (aux2)
    {
        aux3->prox = aux2;
    }
}

/* int main()
{
    celula *l1 = init_list();
    celula *l2 = init_list();
    celula *l3 = init_list();
    add_node(l1, 1);
    add_node(l1, 7);
    add_node(l1, 9);
    add_node(l1, 10);
    add_node(l2, 2);
    add_node(l2, 3);
    add_node(l2, 8);
    imprime(l1);
    imprime(l2);
    imprime(l3);
    mescla_listas(l1, l2, l3);
    printf("Lista 1 : ");
    imprime(l1);
    printf("Lista 2 : ");
    imprime(l2);
    printf("Lista 3 : ");
    imprime(l3);
    free_list(l1);
    free(l1);
    printf("Lista 1 limpa.\n");
    free_list(l2);
    free(l2);
    printf("Lista 2 limpa.\n");
    free_list(l3);
    free(l3);
    printf("Lista 3 limpa.\n");

    return 0;
} */