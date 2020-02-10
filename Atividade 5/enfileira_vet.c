#include <stdlib.h>
#include <stdio.h>
typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    if (f->u == f->N)
    {
        f->N *= 2;
        f->dados = realloc(f->dados, f->N * sizeof(int));
        if (f->dados == NULL)
        {
            return 0;
        }
    }

    f->dados[f->u] = x;
    f->u++;
    return 1;
}

/* int main()
{
    fila *f = malloc(sizeof(fila));
    f->dados = malloc(sizeof(int));
    f->p = f->u = 0;
    f->N = 2;
    printf("%d\n", enfileira(f, 8));
    printf("Primeiro da fila : %d| Ultimo da fila : %d\n", f->dados[f->p], f->dados[f->u - 1]);
    printf("%d\n", enfileira(f, 7));
    printf("Primeiro da fila : %d| Ultimo da fila : %d\n", f->dados[f->p], f->dados[f->u - 1]);
    printf("%d\n", enfileira(f, 6));
    printf("Primeiro da fila : %d| Ultimo da fila : %d\n", f->dados[f->p], f->dados[f->u - 1]);
    free(f->dados);
    free(f);
    return 0;
} */