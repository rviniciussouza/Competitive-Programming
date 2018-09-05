#include <bits/stdc++.h>
using namespace std;

long long busca(long long n) {
    int l = 1, r = n;
    while(l <= r) {
        long long med = (l + r) / 2;
        long long k = 1 + ((med - 1) * 2);
        if(k == n)  return med;
        if(k < n) l = med + 1;
        else r = med - 1;
    }
}

int main() {

    long long n;
    while(scanf("%lld", &n) == 1) {
        long long sn = (busca(n) * (1 + n)) / 2;
        long long ans;
        if(n > 1) {
            ans = ((sn * 2) - 1) + ((sn * 2) - 3) + ((sn * 2) - 5);
        }

        else ans = 1;

        cout << ans <<'\n';
    }

    return 0;

}