#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int n, int x)
{
    int meio;
    int e = -1;
    int d = n;

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
    int M, N;
    scanf("%d %d", &N, &M);
    int *v = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }
    while (M)
    {
        int num;
        scanf("%d", &num);
        printf("%d\n", busca_binaria(v, N, num));
        M--;
    }
    return 0;
}