#include <stdio.h>

int maior(int *v, int n)
{
    if (n == 1)
    {
        return *v;
    }
    else
    {

        int elem = maior(v, n - 1);

        if (v[n - 1] > elem)
        {
            return v[n - 1];
        }
        else
        {
            return elem;
        }
    }
}

int main()
{
    int vetor[5] = {2, 3, 40, 7, 9};

    printf("O maior elemento é : %d\n", maior(vetor, 5));

    return 0;
}