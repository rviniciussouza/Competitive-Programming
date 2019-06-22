#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;
int vis[2010][1010], dp[2010][1010];
pair<int, int> v[1010];
int m;

int solve(int pos, int p) {

    if(pos == 0) return 0;
    if(pos < 0) return -INF;
    if(vis[pos][p] != -1) return dp[pos][p];
    vis[pos][p] = 1;

    int ans = -INF;
    for(int i = p; i < m; ++i) {
        ans = max(ans, solve(pos - v[i].first, i) + v[i].second);
    }

    return dp[pos][p] = ans;
}

int main() {

    int n, q, p;
    while(cin>>m>>n) {

        memset(vis, -1, sizeof vis);
        memset(dp, 0, sizeof dp);

        for(int i = 0; i < m; ++i) {
            cin >> q >> p;
            v[i] = make_pair(q, p);
        }

        int ans = -INF;
        for(int i = 0; i < m; ++i) {
            ans = max(ans, solve(n - v[i].first, i) + v[i].second);
        }
        ans = ans < 0 ? 0 : ans;
        cout << ans << '\n';


    } 

    return 0;
}