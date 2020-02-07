#include <stdlib.h>
#include <stdio.h>
#include "fila_circular_vetor.h"

int main()
{
    fila *f = malloc(sizeof(fila));
    f->N = 10;
    f->dados = malloc(sizeof(item));
    f->first = f->last = 0;
    colocanafila(f, 4);
    colocanafila(f, 3);
    colocanafila(f, 2);
    desenfileira(f);
    printf("%d\n", f->first);
    free(f->dados);
    free(f);
    return 0;
}