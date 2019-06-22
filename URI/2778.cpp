#include <bits/stdc++.h>
using namespace std;

#define INF 10000010

long long n, m;
long long dp[110][110][3][21][21];
bool vis[110][110][3][21][21];
long long grid[110][110];

long long f(long long i, long long j, long long s, long long x, long long y) {
    if(i < 1 || i > n) return INF;
    if(j < 1 || j > m) return INF;
    if(i == n && j == m) return dp[i][j][s][x][y] = grid[i][j];
    if(vis[i][j][s][x][y] != false) return dp[i][j][s][x][y];
    vis[i][j][s][x][y] = true;

    long long ans = INF;
    long long xa = x, ya = y;

    if(grid[i][j] < 0) {
        if( y == 0) return dp[i][j][s][x][y] = INF;
        ya = y-1;
    }

    if(grid[i][j] == 0) {
        if(x == 0) return dp[i][j][s][x][y] = INF;
        xa = x - 1;
    }

    if(s == 0) {
        ans = min(f(i, j+1, 1, xa, ya), f(i+1, j, 0, xa, ya));
        ans = min(ans, f(i, j-1, 2, xa, ya));
    }
    else if(s == 1)
        ans = min(f(i, j+1, 1, xa, ya), f(i+1, j, 0, xa, ya));

    else
        ans = min(f(i, j-1, 2, xa, ya), f(i+1, j, 0, xa, ya));
    
    dp[i][j][s][x][y] = (ans >= INF) ? ans : ans + grid[i][j];

    return dp[i][j][s][x][y];

}

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


        // for(long long i = 0; i < 110; ++i) {
        //     for(long long j = 0; j < 110; ++j) {
        //         for(long long k = 0; k < 3; ++k) {
        //             for(long long m = 0; m < 21; ++m) {
        //                 for(long long n = 0; n < 21; ++n) {
        //                     dp[i][j][k][m][n] = 0;
        //                     vis[i][j][k][m][n] = false;
        //                 }
        //             }
        //         }
        //     }
        // }

        memset(dp, 0L, sizeof dp);
        memset(vis, false, sizeof vis);
        long long ans = f(1,1,0,x,y);
        if(ans >= INF) printf("Impossivel\n");
        else printf("%lld\n", ans);

        // printf("%lld\n", dp[3][1][0][1][2]);
        // printf("%lld\n", dp[1][1][0][2][2]);
        // printf("%lld\n", dp[2][2][0][2][2]);

    }

    return 0;
}