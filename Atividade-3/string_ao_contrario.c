#include <stdio.h>

void str_invert(char *str)
{
    if (*str)
    {
        str_invert(str + 1);
        printf("%c", *str);
    }
}

int main()
{
    char str[500];
    scanf("%s", str);
    str_invert(str);
    printf("\n");
    return 0;
}