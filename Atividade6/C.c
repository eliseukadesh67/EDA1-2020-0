#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int *dados;
    int first, last, N;
} fila;

fila *inicia_fila(int tamanho)
{
    fila *f = malloc(sizeof(fila));
    f->N = tamanho;
    f->last = f->first = 0;
    f->dados = malloc(f->N * sizeof(int));
    return f;
}
void free_fila(fila *f)
{
    free(f->dados);
    f->first = f->last = 0;
    f->N = 0;
}
void preenche(fila *f, int x)
{
    f->dados[f->last] = x;
    f->last++;
}

int main()
{
    int n;
    scanf("%d", &n);
    fila *f = inicia_fila(n);
    fila *final = inicia_fila(n - 1);
    for (int i = 0; i < n; i++)
    {
        preenche(f, i + 1);
    }

    f->dados = realloc(f->dados, 2 * n * sizeof(int));

    while (f->N >= 2)
    {
        final->dados[final->last] = f->dados[f->first];
        final->last++;
        f->first += 2;
        f->dados[f->last] = f->dados[f->first - 1];
        f->last++;
        f->N--;
    }

    printf("Cartas descartadas: ");
    while (final->first != final->last - 1)
    {
        printf("%d, ", final->dados[final->first]);
        final->first++;
    }

    printf("%d\n", final->dados[final->first]);

    printf("Carta restante: %d\n", f->dados[f->last - 1]);

    free_fila(f);
    free_fila(final);
    free(f);
    free(final);

    return 0;
}