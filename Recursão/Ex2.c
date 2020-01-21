#include <stdio.h>
#include <stdlib.h>

//a^b = a*a^b-1

int potencia(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * potencia(a, b - 1);
    }
}

int main()
{
    int a = 2, b = 30;
    printf("%d\n", potencia(a, b));
    return 0;
}