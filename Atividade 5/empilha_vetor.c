#include <stdio.h>
#include <stdlib.h>
typedef struct pilha
{
    int *dados;
    int N, topo;
} pilha;

int empilha(pilha *p, int x);

int empilha(pilha *p, int x)
{
    if (p->topo == p->N)
    {
        if (p->topo == p->N)
        {
            p->N *= 2;

            p->dados = realloc(p->dados, 2 * p->N * sizeof(int));

            // Dobrando a capacidade da pilha para evitar chamadas da função realloc().

            if (p->dados == NULL)
            {
                return 0;
            }
        }
    }

    p->dados[p->topo] = x;
    p->topo++;
    return 1;
}

/* int main()
{
    pilha *p = malloc(sizeof(pilha));
    p->N = 2;
    p->topo = 0;
    p->dados = malloc(sizeof(int));
    printf("%d\n", empilha(p, 1));
    printf("%d\n", empilha(p, 2));
    printf("%d\n", empilha(p, 3));
    free(p->dados);
    free(p);

    return 0;
} */