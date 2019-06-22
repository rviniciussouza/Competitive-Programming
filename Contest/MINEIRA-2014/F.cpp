#include <bits/stdc++.h>
using namespace std;

const int MN = 100110;

vector<int> G[MN];
bool vis[MN];

void DFS(int u) {

    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v] == false) DFS(v);
    }
}

int main() {

    int n, k, q, r;

    while(scanf("%d %d", &n, &k) && n != 0) {

        memset(vis, false, sizeof vis);
        for(int i = 0; i < MN; ++i) G[i].clear();

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &q);
            for(int j = 0; j < q; ++j) {
                scanf("%d", &r);
                G[i].push_back(n + r);
                G[n + r].push_back(i);
            }
        }

        DFS(1);

        bool flag = false;
        for(int i = 1; i <= n; ++i) {
            if(vis[i] == false) flag = true;
        }

        if(!flag) puts("S");
        else puts("N");

    }

    return 0;

}