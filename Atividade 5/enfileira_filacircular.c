#include <stdlib.h>
#include <stdio.h>
typedef struct fila
{
    int *dados;
    int N, p, u;
} fila;

int enfileira(fila *f, int x)
{
    if (f->p < f->u)
    {
        //Redimensiona
    }
    else if (f->u < f->p)
    {
        if (f->u < f->N - f->p)
        {
        }
        else if (f->u > f->N - f->p)
        {
        }
        else
        {
        }
    }
}