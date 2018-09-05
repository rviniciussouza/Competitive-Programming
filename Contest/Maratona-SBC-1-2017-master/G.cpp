#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007
#define max_n 100123

ll dp[55][max_n];
ll m, n, t, d;

ll f(int tempo, int pos) {
    if(pos < 1 || pos > d) return 0;
    if(tempo == 1) return 1;    
    if(dp[tempo][pos] != -1) return dp[tempo][pos];
    return dp[tempo][pos] = (f(tempo-1, pos-1) + f(tempo-1, pos+1)) % MOD; 
}

int main() {

    cin>>t>>m>>n;
    d = (n - m) + 1;

    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for(int i=1; i <= d; ++i) {
        ans = (ans + f(t, i)) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}