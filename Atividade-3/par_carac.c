#include <stdio.h>

int cont_par(char *str)
{
    if (*(str + 2))
    {

        if (*str == *(str + 2))
        {
            return cont_par(str + 1) + 1;
        }
        else
        {
            return cont_par(str + 1);
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    char str[200];
    scanf("%s", str);
    printf("%d\n", cont_par(str));
    return 0;
}