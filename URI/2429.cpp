#include <bits/stdc++.h>
using namespace std;

const int MN = 10010;
vector<int> G[MN];
int vis[MN], low[MN], num[MN], ans = 0, counter = 0;
stack<int> p;

void dfs(int u) {

    low[u] = num[u] = counter++;
    vis[u] = true;
    p.push(u);

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(num[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(vis[v] == true) low[u] = min(low[u], low[v]);
    }

    if(low[u] == num[u]) {
        while(true) {
            int v = p.top(); p.pop(); 
            vis[v] = false;
            if(u == v) break;
        }
    
        ans++;
    }
}

int main() {

    int n, u, v;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
    }

    memset(num, -1, sizeof num);

    for(int i = 1; i <= n; ++i) {
        if(num[i] == -1) dfs(i);
    }

    if(ans > 1) puts("N");
    else puts("S");

    return 0;
}