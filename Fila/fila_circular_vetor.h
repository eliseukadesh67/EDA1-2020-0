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

int desenfileira(fila *f)
{
    if (f->first == f->last)
    {
        return 0;
    }

    f->first++;

    f->first = (f->first + 1) % f->N;

    return 1;
}
void colocanafila(fila *f, int x)
{
    f->dados[f->last++] = x;
    if (f->last == f->N)
    {
        f->last = 0;
    }
}