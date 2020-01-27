#include <stdio.h>

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        int ant1 = 1, ant2 = 1, atual;

        for (int i = 2; i < n; i++) // Complexidade O(n)
        {
            atual = ant1 + ant2;
            ant1 = ant2;
            ant2 = atual;
        }

        return atual;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}