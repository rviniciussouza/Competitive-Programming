#include <bits/stdc++.h>
using namespace std;

#define max_n 1234

int dp[max_n][max_n];
int v[max_n];
int n;

int f(int a, int b, int x, int y) {
    if(n < (a || b ) < 0) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    if(v[a] + x == y) dp[a][b] = y + f(a+1, b+1, y, y);
    else if(v[b] + y == x) dp[a][b] = x + f(a+1, b+1, x, x);
    else dp[a][b] = max(f(a+1, b, x + v[a], y), f(a, b+1, x, y + v[b]));

    return dp[a][b];      
}


int main(){
    while(scanf("%d", &n) && n != 0) {
        for(int i=1;  i <= n; ++i) scanf("%d", &v[i]);

        memset(dp, -1, sizeof dp);

        int ans = 0;
        for(int i=1; i < n; ++i) {
            ans = max(ans, f(i-1, i, 0, 0));
        }

        printf("%d\n", ans);
    
    }

    return 0;

}