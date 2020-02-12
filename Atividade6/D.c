#include <stdio.h>
#include <stdlib.h>
void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion_sort(int *v, long int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && v[j] < v[j - 1]; j--)
        {
            troca(&v[j], &v[j - 1]);
        }
    }
}

int main()
{
    int i = 0, num = 0, n = 0;
    int vet[10000];
    while (scanf("%d", &num) != EOF)
    {
        vet[i] = num;
        i++;
    }
    n = i;
    insertion_sort(vet, n);
    printf("%d", vet[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", vet[i]);
    }
    printf("\n");
    return 0;
}