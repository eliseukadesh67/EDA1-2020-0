#include <stdio.h>

long long int soma(unsigned long long int n)
{
    long long int ans = 0;
    if (n / 10 == 0)
    {
        return n;
    }
    else
    {
        ans += soma(n / 10);
        ans += n % 10;
        return ans;
    }
}

int div(unsigned long long int n)
{
    int ans = 1;
    if (n == 9)
    {
        return ans;
    }
    else if (n < 9)
    {

        ans = 0;
        return 0;
    }
    else
    {
        ans += div(soma(n));
        return ans;
    }
}

int main()
{
    char n[1000];
    while (n != "0")
    {
        scanf("%s", n);
        if (n == "0")
        {
            break;
        }
        if (div(atoi(n)) - 1)
        {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", n, div(n));
        }
        else
        {
            printf("%s is not a multiple of 9.\n", n);
        }
    }
    return 0;
}