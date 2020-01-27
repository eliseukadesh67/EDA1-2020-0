#include <stdio.h>

int cont_par(char *str, int cont)
{
    if (*str)
    {

        if (*str == *(str + 2))
        {
            cont++;
        }

        return cont_par(str + 1, cont);
    }
    else
    {
        return cont;
    }
}

int main()
{
    char str[200];
    scanf("%s", str);
    printf("%d\n", cont_par(str, 0));
    return 0;
}