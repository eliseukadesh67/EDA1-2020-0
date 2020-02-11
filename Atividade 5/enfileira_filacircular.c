#include <stdlib.h>
#include <stdio.h>
typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    if (((f->u + 1) % (f->N)) == f->p)
    {
        if (f->u < f->p)
        {
            if (f->u < (f->N - f->p))
            {
                f->N *= 2;
                f->dados = realloc(f->dados, f->N * sizeof(int));
                if (f->dados == NULL)
                {
                    return 0;
                }
                int cont = f->N / 2;
                while (f->u)
                {
                    f->u--;
                    f->dados[cont] = f->dados[f->u];
                    cont++;
                }

                f->u = cont;
            }
            else if (f->u > (f->N - f->p))
            {
                f->N *= 2;
                f->dados = realloc(f->dados, f->N * sizeof(int));
                if (f->dados == NULL)
                {
                    return 0;
                }
                int cont_fim = f->N - 1;
                int cont_init = (f->N / 2) - 1;

                while (cont_init >= f->p)
                {
                    f->dados[cont_fim] = f->dados[cont_init];
                    cont_init--;
                    cont_fim--;
                }

                f->p = cont_fim;
            }
        }
    }

    f->dados[f->u] = x;
    f->u++;
    if (f->u == f->N)
    {
        f->u = 0;
    }

    return 1;
}

/* int main()
{
    fila *f = malloc(sizeof(fila));
    f->N = 5;
    f->u = f->p = 0;
    f->dados = malloc(f->N * sizeof(int));
    printf("%d\n", enfileira(f, 1));
    printf("%d\n", enfileira(f, 2));
    printf("%d\n", enfileira(f, 3));
    printf("%d\n", enfileira(f, 4));
    f->p++;
    f->p++;
    f->p++;
    printf("%d\n", enfileira(f, 5));
    f->p++;
    printf("%d\n", enfileira(f, 6));
    printf("%d\n", enfileira(f, 7));
    printf("%d\n", enfileira(f, 8));
    printf("%d\n", enfileira(f, 9));
    printf("Primeiro : %d\n", f->p);
    printf("Ultimo : %d\n", f->u);
    free(f->dados);
    free(f);
} */