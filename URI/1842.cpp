#include <bits/stdc++.h>
using namespace std;

int dp[21][420];
int adj[21][21];
int v[21];
int n;

int solve(int m, int t) {
    if(dp[n][t] != -1) return dp[n][t];
    if(m == t) dp[m][t] = 0;
    else if(t < v[m]) dp[m][t] = 0;
    else {
        int ans = 0;
        for(int i=0; i < n; ++i) {
            if(i != m) {
                int custo = v[i] + adj[m][i];
                if(custo > t) continue;
                ans = max(ans, solve(i, t - custo));
            }
        }      

        dp[m][t] = 1 + ans;
    }
    return dp[m][t];
}

int main() {
    while(1) {
        cin >> n;
        if(!n) break;

        for(int i=0; i < n; ++i) scanf("%d", &v[i]);
        for(int i=0; i < n; ++i) {
            for(int j=0; j < n; ++i) {
                scanf("%d", &adj[i][j]);
            }
        }

        int ans = 0;
        for(int i=0; i < n; ++i) ans = max(ans, solve(i,420));
        printf("%d\n", ans);

    }

    return 0;
}