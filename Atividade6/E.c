#include <stdio.h>
#include <stdlib.h>
void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ordena(int *v, int n)
{

    if (n <= 1)
    {
        return;
    }
    ordena(v, n - 1);
    if (*(v + 1) < *(v))
    {
        troca(v + 1, v);
        ordena(v - 1, n - 1);
    }
    else
    {
        ordena(v + 1, n - 1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int j = n;
    int *vet = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        vet[i] = j;
        j--;
    }
    ordena(vet, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vet[i]);
    }

    return 0;
}
