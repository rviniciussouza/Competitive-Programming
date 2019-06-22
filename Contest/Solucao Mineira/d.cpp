#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f3f3f3f3f
#define maxn 200010
typedef long long ll;

ll ans;
ll n, m;
string s;

void add(int i) {
    // adiciona de [0,i) na esq e de [i,fim] na direita
    
    ll num = 0;
    for (int j=0;j<i;j++)
        num = num * 10 + s[j] - '0';
        
    ll copia = n;
    while (copia) {
        num *= 10LL;
        copia /= 10LL;
    }
    num += n;
    
    for (int j=i;j<s.size();j++)
        num = num * 10 + s[j] - '0';
    
    if (num % m == 0) {
        ans = min(ans, num); 
        // cout << "debug: " << s << " " << i << " " << num << endl;
    }
}
main() {
    scanf("%lld %lld", &n, &m);
    
    if (n % m == 0) {
        printf("%lld\n", n);
        return 0;
    }

    ans = inf;

    s= "";
    for (int i=1;i<=6;++i) {
        s += '0';
        add(0);
    }
    for (ll i=1;i<maxn;i++) {
        s = "";
        ll copia = i;
        while (copia) {
            s += '0' + copia % 10;
            copia /= 10;
        }
        reverse(s.begin(), s.end());
        for (int j=0;j<=s.size();j++)
            add(j);
    }
    printf("%lld\n", ans);
}