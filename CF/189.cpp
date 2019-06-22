#include <bits/stdc++.h>
using namespace std;

const int MN = 4123;
const int INF = 1233456;
int dp[MN];

int main() {

    int n, v[3];
    scanf("%d", &n);
    scanf("%d", &v[0]);
    scanf("%d", &v[1]);
    scanf("%d", &v[2]);

    memset(dp, -INF, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(v[j] > i) continue;
            dp[i] = max(dp[i], 1 + dp[i - v[j]]);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}