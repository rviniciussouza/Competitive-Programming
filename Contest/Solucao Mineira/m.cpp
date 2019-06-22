#include <bits/stdc++.h>
using namespace std;
const int N = 30;
const int M = 112;

int color[N];
vector<int> g[N];
map<int, string> dp;

bool cycle (const int i) {
    if (color[i] == 2)
        return false;
    color[i] = 1;
    bool ans = false;
    for (auto j : g[i]) {
        if (color[j] == 1)
            return true;
        ans |= cycle(j);
    }
    color[i] = 2;
    return ans;
}

void build (const int i) {
    if (dp.count(i))
        return;
    string ans = "";
    for (auto j : g[i])
        build(j),
        ans += dp[j];
    if (!int(ans.size()))
        ans.push_back(char(i + 'a'));
    dp[i] = ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string c, s; cin >> c >> s;
        int x = c[0] - 'a';
        
        //~ cout << c << " bla " << s << "\n";
        if (c == s) continue;
        for (auto j : s) {
            int y = j - 'a';
            g[x].push_back(y);
        }
    }
    memset(color, 0, sizeof color);
    for (int i = 0; i < N; ++i)
        if (!color[i] and cycle(i)) {
            cout << -1 << endl;
            return 0;
        }
    for (int i = 0; i < N; ++i)
        build(i);
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        char c; cin >> c;
        int idx = c - 'a';
        cout << dp[idx];
    }
    cout << endl;
    return 0;
}