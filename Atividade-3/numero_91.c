#include <stdio.h>

int f91(int n)
{
    if (n >= 101)
    {
        return n - 10;
    }
    else
    {
        return f91(f91(n + 11));
    }
}

int main()
{
    int n = 1;
    while (n)
    {
        scanf("%d", &n);

        if (n == 0)
        {
            break;
        }
        else
        {
            printf("f91(%d) = %d\n", n, f91(n));
        }
    }
    return 0;
}