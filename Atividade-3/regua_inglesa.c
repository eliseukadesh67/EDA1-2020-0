#include <stdio.h>
#include <stdlib.h>

void regua_inglesa(int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        regua_inglesa(n - 1);
        printf(".");
        for (int i = 0; i < n; i++)
        {
            printf("-");
        }
        printf("\n");
        regua_inglesa(n - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    regua_inglesa(n);
    return 0;
}