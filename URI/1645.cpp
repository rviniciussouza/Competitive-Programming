#include <bits/stdc++.h>
using namespace std;

long long dp[101][101];
int v[101];

int main(){

    int n, k;
    while(scanf("%d %d", &n, &k) && n) {

        for(int i=1; i <= n; ++i) scanf("%d", &v[i]);
        memset(dp, 0, sizeof dp);
        for(int i=1; i <= n; ++i) dp[1][i] = 1;

        for(int i=2; i <=n; ++i)
            for(int j=1; j <=n; ++j)
                for(int x = 1; x < j; ++x)
                    if(v[j] > v[x]) dp[i][j] += dp[i-1][x];

        long long ans = 0;
        for(int i=1; i <=n; ++i)
            ans += dp[k][i];
        
        cout<<ans<<endl;
    }

    return 0;
}