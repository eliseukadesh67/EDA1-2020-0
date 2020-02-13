#include <stdio.h>
#include <stdlib.h>
void troca(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion_sort(long long int *v, long long int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && v[j] < v[j - 1]; j--)
        {
            troca(&v[j], &v[j - 1]);
        }
    }
}
long long int binary_search(long long int *v, long long int *aux, long long int n, long long int x)
{
    long long int e = 0, d = n - 1;

    while (e <= d)
    {
        long long int meio = (e + d) / 2;
        if (v[meio] == x)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[meio] == aux[i])
                {
                    return i;
                }
            }

            return meio;
        }
        else if (v[meio] < x)
        {
            e = meio + 1;
        }
        else
        {
            d = meio - 1;
        }
    }

    return -1;
}

int main()
{
    long long int N, M;
    scanf("%lld %lld", &N, &M);
    long long int *vet = malloc(N * sizeof(long long int));
    long long int *aux = malloc(N * sizeof(long long int));
    for (long long int i = 0; i < N; i++)
    {
        long long int num;
        scanf("%lld", &num);
        aux[i] = vet[i] = num;
    }

    insertion_sort(vet, N);

    while (M)
    {
        long long int x;
        scanf("%lld", &x);
        printf("%lld\n", binary_search(vet, aux, N, x));
        M--;
    }

    free(vet);
    free(aux);
    return 0;
}