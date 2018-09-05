#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    while(scanf("%d", &n) && n)
    {
        long long resto = 0, soma = 0;
        for(int i=0; i < n; ++i) {
            scanf("%d", &a);
            resto += a;
            soma += abs(resto);
        }

        printf("%lld\n", soma);
    }

    return 0;
}