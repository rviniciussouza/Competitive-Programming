#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii; 
#define max_n 123
#define MOD 100000000

ll dp[max_n][max_n], M, x, y;
ii v[max_n];
bool vis[max_n][max_n];
int n;

bool unite(int ant, int pos, int i) {
    return v[i]. first > v[ant].second && v[i].second > v[pos].second;
}

ll f(int ant, int pos) {
    if(pos > n) return 0;
    if(v[pos].second >= M) return 1;
    if(vis[ant][pos]) return dp[ant][pos];
    vis[ant][pos] = true;
    ll ans = 0;

    for(int i=pos+1; v[i].first <= v[pos].second && i < n; ++i ){
        if(unite(ant, pos, i)) ans = (ans + f(pos, i)) % MOD;
    }

    return dp[ant][pos] = ans;
}

ll solve() {
    ll ans = 0;
    for(int i=1; v[i].first == 0 && i < n; ++i) {
        ans = (ans + f(0, i)) % MOD;
    }

    return ans;
}

int main() {

    while(scanf("%lld %d", &M, &n) && M) {
        for(int i=0; i < n; ++i) {
            scanf("%lld %lld", &x, &y);
            v[i] = ii(x, y);
        }

        v[n] = ii(-1, 0);
        n++;

        sort(v, v + n);
        memset(vis, false, sizeof vis);

        printf("%lld\n", solve());

    }
    return 0;
}