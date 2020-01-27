#include <stdio.h>
#include <stdlib.h>

void fib(int *f, int n)
{
    if (n == 1)
    {
        f[0] = 1;
    }
    else if (n == 2)
    {
        f[0] = f[1] = 1;
    }
    else
    {
        fib(f, n - 1);
        f[n - 1] = f[n - 2] + f[n - 3];
    }

    // Realiza n chamadas recursivas, O(n) //
}

int main()
{
    int n;
    int *f;
    scanf("%d", &n);
    f = (int *)malloc(n * sizeof(int));
    if (f == NULL)
    {
        exit(1);
    }
    else
    {
        fib(f, n);
        printf("Fib[%d] = %d\n", n, f[n - 1]);
    }

    free(f);
    return 0;
}