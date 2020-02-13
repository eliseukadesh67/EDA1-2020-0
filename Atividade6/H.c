#include <stdio.h>
#include <stdlib.h>

long int busca_binaria(long long int *v, long int n, int x)
{
    long int meio;
    long int e = -1;
    long int d = n;

    while (e < d - 1)
    {
        meio = (e + d) / 2;
        if (v[meio] < x)
        {
            e = meio;
        }
        else
        {
            d = meio;
        }
    }
    return d;
}
int main()
{
    long int c, t;
    long int *raios;
    long long int *busca;
    long int cord;
    long int cont = 0;
    scanf("%ld %ld", &c, &t);
    raios = malloc(c * sizeof(long int));
    busca = malloc(c * sizeof(long long int));
    for (int i = 0; i < c; i++)
    {
        long int r;
        scanf("%ld", &r);
        raios[i] = r;
        busca[i] = r * r;
    }
    while (t)
    {
        long int x, y;
        scanf("%ld %ld", &x, &y);
        cord = (x * x) + (y * y);
        long int retorno = busca_binaria(busca, c, cord);
        cont += c - retorno;

        t--;
    }

    printf("%ld\n", cont);
    free(raios);
    free(busca);
    return 0;
}