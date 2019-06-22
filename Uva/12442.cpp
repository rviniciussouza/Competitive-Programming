#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MN = 50010;

int qtd[MN], ancestral[MN], vis[MN], G[MN];
queue<int> p;

int dfs(int u) {

    vis[u] = 0; ancestral[u] = u;
    int ans = 0; p.push(u);
    int v = G[u];
    if(vis[v] == 1) ans = max(ans, qtd[v]); 
    else if(vis[v] == 0) ancestral[u] = v;
    else {
        ans = max(ans, dfs(v));
        ancestral[u] = ancestral[v];
    }   

    vis[u] = 1;
    return qtd[u] = ans + 1;
}

int main() {

    int t, n, m, u, v;
    scanf("%d", &t);

    for(int k = 1; k <= t; ++k) {
        scanf("%d", &n);
        
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            G[u] = v;
        }

        int qtdmax = 0, idmax;

        memset(vis, -1, sizeof vis);
        memset(qtd, 0, sizeof qtd);

        for(int i = 1; i <= n; ++i) {
            if(vis[i] == -1) dfs(i);

            while(!p.empty()) {
                v = p.front(); p.pop(); 
                qtd[v] = max(qtd[v], qtd[ancestral[v]]);
                if(qtd[v] > qtdmax) {
                    qtdmax = qtd[v];
                    idmax = v;
                }
            }
        }

        printf("Case %d: %d\n", k, idmax);
    }

    return 0;

}