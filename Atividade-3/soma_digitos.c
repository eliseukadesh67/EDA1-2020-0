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

int main()
{
    unsigned long long int n;
    scanf("%lld", &n);
    unsigned int ans = soma(n);
    printf("%d\n", ans);

    return 0;
}