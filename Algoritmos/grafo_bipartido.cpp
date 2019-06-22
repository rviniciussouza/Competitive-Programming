#include <bits/stdc++.h>
using namespace std;

const int MN = 110;
vector<int> G[MN];
int vis[MN], flag;

void bipartido(int u) {

    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v] == -1) {
            vis[v] = vis[u] ^ 1;
            bipartido(v);
        }
        else {
            if(vis[v] == vis[u]) flag = true;
        }
    }
}


int main() {

    stringstream ss;
    string in;
    int u, v, n;
    while(scanf("%d", &n) && n != 0) {

        for(int i = 0; i <= n; ++i) {
            G[i].clear();        
            vis[i] = -1;
        }
        
        for(int i = 0; i < n; ++i) {
            scanf("%d", &u);
            getchar();
            getline(cin, in);
            ss << in;
            while(ss >> v) {
                G[u-1].push_back(v-1);
                G[v-1].push_back(u-1);
            }

            ss.clear();
        }

        flag = false;
        for(int i = 0; i < n; ++i) {
            if(vis[i] == -1) {
                vis[i] = 1;
                bipartido(i);
            }
        }

        if(flag) puts("NAO");
        else puts("SIM");
    }

    return 0;

}