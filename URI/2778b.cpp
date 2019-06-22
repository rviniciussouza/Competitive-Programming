#include <bits/stdc++.h>
using namespace std;

#define INF 10000010


int main() {

    long long x, y;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(scanf("%lld %lld %lld %lld", &n, &m, &x, &y) == 4) {
 
        for(long long i=1; i <= n; ++i) {
            for(long long j=1; j <= m; ++j) {
                scanf("%lld", &grid[i][j]);
            }
        }

        int xa = x;
        int ya = y;

        dp[n][m] = grid[n][m];
        for(int i = m-1; i >= 0; --i) {
            if(grid[n][i] < 0 && ya == 0) {
                dp[n][i] = dp[n][i+1] + grid[n][i];
                ya--;
            }

            else {
                dp[n][i] = INF;
            }

            if(grid[n][i] == 0 && xa == 0) {
                dp[n][i] = dp[n][i+1] + grid[n][i];
                xa--;
            }

            else {
                dp[n][i] = INF;
            }
        }

        for(int p =)

    }

}