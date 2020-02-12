#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1, a2, elem1, elem2;
    char c1, c2;
    scanf("%d %c", &a1, &c1);
    scanf("%d %c", &a2, &c2);
    elem1 = a1 + c1;
    elem2 = a2 + c2;
    if (abs(elem1 - elem2) == 1)
    {
        printf("São pares.\n");
    }
    else
    {
        printf("Não são pares.\n");
    }
    return 0;
}