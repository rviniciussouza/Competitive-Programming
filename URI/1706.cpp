#include <bits/stdc++.h>
using namespace std;

string nota[1010];
bool visitado[1010];
vector<vector<int> > G;

bool dfs(int u) {

    visitado[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!visitado[v]) {
            if(!dfs(v)) {
                if(nota[u] == "A") {
                    nota[u] = "B";
                }

                else {
                    nota[u] = "A";
                }
            }
        }
    }

    return nota[u] == "A" ? true : false;
}

int main() {

    int n, m, u, v;

    while(scanf("%d %d", &n, &m) == 2) {

        G.clear();
        G.resize(n+1);

        for(int i = 1; i <= n; ++i) {
            visitado[i] = false;
            cin >> nota[i];
        }

        // for(int i = 1; i <= n; ++i) {
            // cout << nota[i];
        // }

        for(int i = 0; i < m; ++i) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        bool flag = false;

        for(int i = 1; i <= n; ++i) {
            if(!visitado[i]) {
                if(!dfs(i)) {
                    flag = true;
                    break;
                }
            }
        }

        if(flag) printf("N\n");
        else printf("Y\n");
    
    }

    return 0;
}