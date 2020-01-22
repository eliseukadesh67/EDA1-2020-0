#include <stdio.h>

void str_invert(char *str)
{
    if (str++ == NULL)
    {
        printf("fodeu");
        return;
    }
    else
    {
        str_invert(str++);
    }
}

int main()
{
    char str[500];
    scanf("%s", str);
    str_invert(str);
    return 0;
}