#include <stdio.h>
#include <stdlib.h>

long long int fat(int n)
{

    if (n == 0) // Caso base
    {
        return 1;
    }
    else
    {
        return n * fat(n - 1); // Recursão
    }
}

int main()
{
    int n = 20;
    printf("%lld\n", fat(n));
    return 0;
}