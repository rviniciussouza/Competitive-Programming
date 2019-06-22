#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll myModPow(ll n, ll k, ll mod) {
    if (!k) return 1LL;
    ll aux = myModPow(n, k/2, mod);
    aux = (aux * aux) % mod;
    return k&1 ? (aux * n) % mod : aux;
}

main() {
    string s;
    cin >> s;
    
    int cont = 0;
    ll div = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == 'F') cont++;
        else cont--;
        if (cont == 0) div++;
    }
    printf("%lld\n", myModPow(2LL, div-1LL, 1000000007LL));
}