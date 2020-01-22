#include <stdio.h>

int hanoi(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return 2 * hanoi(n - 1) + 1;
    }
}

int main()
{
    int pecas = 1, cont = 1;
    while (pecas)
    {
        scanf("%d", &pecas);
        if (pecas == 0)
        {
            break;
        }
        printf("Teste %d\n", cont);
        printf("%d\n\n", hanoi(pecas));
        cont++;
    }
}