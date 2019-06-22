#include <bits/stdc++.h>
using namespace std;

const int MN = 110;
const int MOD = 1000000000 + 7;
long long dp[MN][3];

int n, k, d;


long long solve(int s, int e) {

    if(s == 0) return e;
    if(dp[s][e] != -1) return dp[s][e];
    long long ans = 0;
    for(int i = 1; i <= k; i++) {
        if(i <= s) ans = (ans + solve(s - i, i >= d || e)) % MOD;
    }
    return dp[s][e] = ans;
}

int main() {

    scanf("%d %d %d", &n, &k, &d);
    memset(dp, -1, sizeof dp);
    // dp[0][0] = 1;
    cout << solve(n, 0) << '\n';
    return 0;
}