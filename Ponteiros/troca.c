#include <stdio.h>
#include <stdlib.h>

void troca_int(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void troca_str(char **x, char **y)
{
    char *tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
int main()
{
    int a, b;
    char *s1, *s2;
    a = 3;
    b = 4;
    troca_int(&a, &b);
    printf("a is %d\n", a);
    printf("b is %d\n", b);
    s1 = "Eu deveria aparecer depois";
    s2 = "Eu deveria aparecer primeiro";
    troca_str(&s1, &s2);
    printf("s1 is %s\n", s1);
    printf("s2 is %s\n", s2);

    return 0;
}