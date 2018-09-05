#include <stdio.h>

long long fat(int n)
{
    long long x = 1;
    for(int i=2; i <= n; ++i)
        x *= i;
    return x;
}


int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        printf("%lld\n", fat(n) + fat(m));
    }

    return 0;
}