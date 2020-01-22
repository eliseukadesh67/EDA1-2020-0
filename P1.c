#include <stdio.h>
#include <stdlib.h>

int mai(int *v, int n)
{
    if (n == 1)
    {
        return *v;
    }
    else
    {

        int elem = mai(v, n - 1);

        if (v[n - 1] > elem)
        {
            return v[n - 1];
        }
        else
        {
            return elem;
        }
    }
}

int main()
{
    int d, a, s, m, code, mat, ap, maior;
    scanf("%d", &d);
    int *disp = (int *)calloc(d, sizeof(int));

    while (scanf("%d %d %d", &a, &s, &m) != EOF)
    {
        while (m)
        {
            scanf("%d %d %d", &code, &mat, &ap);

            m--;
        }

        for (int i = 0; i < d; i++)
        {
            if (i == code)
            {
                disp[i] += mat - ap;
            }
        }
        maior = mai(disp, d);

        printf("%d/%d\n", s, a);

        for (int i = 0; i < d; i++)
        {
            if (maior == disp[i])
            {
                printf("%d ", i);
            }
        }

        printf("\n");

        free(disp);
    }
    return 0;
}