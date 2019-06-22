#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000 + 10

vector<long long> G[MAXN];
long long vis[MAXN], h[MAXN];
long long k, ciclo;
bool flag;

void dfs(int v, int pai, int cnt) {

    vis[v] = 1;
    h[v] = cnt;

    for(int i = G[v].size() -1; i >= 0; --i) {        
        int x = G[v][i];
        
        if(vis[x] == 0) dfs(x, v, cnt + 1);
        else if(vis[x] == 1 && x != pai) ciclo = cnt - h[x] + 1;
    }

    vis[v] = 2;
}


int main() {

    long long w, a, b, u, v;
    map<long long, int> M;

    while(1) {
        scanf("%lld %lld", &k, &w);

        if(k == 0) {
            break;
        }

        int cnt_v = 0;
        flag = false;

        for(int i = 0; i < MAXN; ++i) {
            G[i].clear();
        }

        M.clear();

        memset(vis, 0, sizeof vis);

        for(int i = 0; i < w; ++i) {
            
            scanf("%lld %lld", &a, &b);

            if(M.find(a) == M.end()) M[a] = cnt_v++;
            if(M.find(b) == M.end()) M[b] = cnt_v++;

            u = M[a], v = M[b];

            G[u].push_back(v);
            G[v].push_back(u);
        }   

        for(int i = 0; i < cnt_v; ++i) {
            sort(G[i].begin(),G[i].end());
            G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
        }

        for(int i = 0; i < cnt_v; ++i) {
            if(G[i].size() > 2) {
                flag = true;
            }
        }

        if(flag) {
            printf("N\n");
            continue;
        }

        ciclo = -1;

        for(int i = 0; i < cnt_v; ++i)
            if(vis[i] == 0) dfs(i, -1, 0);

        if(ciclo == k || ciclo == -1) printf("Y\n"); 
        else printf("N\n");
    }

    return 0;

}