#include <stdlib.h>
#if tipo == 0
#define item char
#elif tipo == 1
#define item int
#elif tipo == 2
#define item float
#elif tipo == 3
#define item double
#elif tipo == 4
#define item long int
#elif tipo == 5
#define item long long int
#endif

typedef struct fila
{
    item *dados;
    int first, last, N;
} fila;

void inicia_fila(fila *f)
{
    f->N = 10;
    f->last = f->first = 0;
    f->dados = (item *)malloc(f->N * sizeof(item));
}
void enfileira(fila *f, item x)
{
    if (f->last == f->N)
    {
        f->N *= 2;
        f->dados = (item *)realloc(f->dados, f->N * sizeof(fila));

        if (f->dados == NULL)
        {
            exit(1);
        }
    }

    f->dados[f->last++] = x;
}
int desenfileira(fila *f)
{
    if (f->first == f->last)
    {
        return 0;
    }
    else
    {
        f->first++;
        return 1;
    }
}
void free_fila(fila *f)
{
    free(f->dados);
    f->first = f->last = 0;
    f->N = 0;
}