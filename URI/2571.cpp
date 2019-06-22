#include<bits/stdc++.h>

using namespace std;

long double eleve(long double a, long long int e) {
    if(e == 0) return 1.0;
    if(e == 1) return a;
    long double x = eleve(a, e/2);
    long double y = x * x;
    if(e%2 == 1) y *= a;
    return y;
}

int main()
{
    long long m;
    long double p,j,x;

    cin >> m >> p >> j >> x;

    long long ini = 0, fim = 1000000000;

    long long ans;
    while(fim - ini > 1) {
        long long meio = (ini + fim) / 2;
	
        if(m * eleve(1-(p/100), meio) * (j/100) >= x) {
            ini = meio;
            ans = meio;
        }

        else {
            fim = meio;
        }
    
    }

    printf("%lld\n", ans);

    return 0;
}