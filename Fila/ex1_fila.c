#include <stdlib.h>
#include <stdio.h>
#include "fila_vetor.h"

int main()
{
    fila *f;
    f = malloc(sizeof(fila));
    if (f == NULL)
    {
        exit(1);
    }
    inicia_fila(f);
    if (f->dados == NULL)
    {
        printf("Erro ao criar a fila.\n");
    }
    else
    {
        printf("Fila criada com sucesso!\n");
    }

    enfileira(f, 9);
    enfileira(f, 8);
    enfileira(f, 7);
    enfileira(f, 6);
    desenfileira(f);

    printf("Primeiro da fila : %d\n", f->dados[f->first]);
    printf("Ultimo da fila : %d\n", f->dados[f->last - 1]);

    free_fila(f);
    printf("Fila destruida!\n");
    free(f);
    return 0;
}