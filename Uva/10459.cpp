#include <bits/stdc++.h>
using namespace std;

#define MAX 5123

const int INF = 1e9;

vector<int> bt;
vector<int> G[MAX];
vector<int> degree(MAX);

void findcenter(int n) {
    queue<int> F;
    for(int i=1; i <= n; ++i)
        if(degree[i] == 1) F.push(i); 

    while(n > 2) {

        n = n - F.size();
        int k = F.size();

        for(int i=0; i < k; ++i) {
            int v = F.front(); F.pop();

            for(int j=0; j < G[v].size(); ++j) {
                degree[G[v][j]] -= 1;
                if(degree[G[v][j]] == 1)
                    F.push(G[v][j]);
            }
        }
    }

    while(!F.empty()) {
        bt.push_back(F.front());
        F.pop();     
    }
}

int bfs(vector<int> &dist) {

    int wt = -1;
    for(int k = 0; k < bt.size(); ++k) {
        queue<int> F;
        vector<bool> vis(MAX, false);
        F.push(bt[k]);
        dist[bt[k]] = 0;
        while(!F.empty()) {            
            int v = F.front(); F.pop();
            vis[v] = true;
            for(int i = 0; i < G[v].size(); ++i) {
                int u = G[v][i];
                if(vis[u] == false) {
                    dist[u] = max(dist[u], dist[v] + 1);
                    wt = max(wt, dist[u]);
                    F.push(u);
                }
            }
        }
    }

    return wt;
}


int main() {
    int n, k, u, v;

    while(scanf("%d", &n) != EOF) {

        for(int i=0; i < MAX; ++i) G[i].clear(), degree[i] = 0;
        bt.clear();

        for(int i=1; i <= n; ++i) {
            scanf("%d", &k);
            for(int j = 0; j < k; ++j) {
                scanf("%d", &v);
                G[i].push_back(v);
                degree[i] += 1;
            }
        }

        findcenter(n);

        printf("Best Roots  :");
        if(bt.size() == 2) {
            printf(" %d %d\n", min(bt[0], bt[1]), max(bt[0], bt[1]));
        }
        else printf(" %d\n", bt[0]);

        vector<int> dist(MAX, -INF);
        int wt = bfs(dist);

        printf("Worst Roots :");
        for(int i=1; i <= n; ++i) {
            if(dist[i] == wt) printf(" %d", i);
        } printf("\n");
    }

    return 0;
}