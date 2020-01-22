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

    while (scanf("%d %d %d", &a, &s, &m) != EOF)
    {
        int *disp = (int *)calloc(d, sizeof(int));
        maior = 0;
        while (m)
        {

            scanf("%d %d %d", &code, &mat, &ap);

            for (int i = 0; i < d; i++)
            {

                if (i == code)
                {
                    disp[i] += (mat - ap);
                }
            }

            m--;
        }

        for (int i = 0; i < d; i++)
        {
            if (disp[i] > maior)
            {
                maior = disp[i];
            }
        }

        printf("%d/%d\n", s, a);

        for (int i = 0; i < d; i++)
        {
            if (maior == disp[i])
            {
                printf("%d ", i);
            }

            disp[i] = 0;
        }

        printf("\n\n");

        free(disp);
    }
    return 0;
}