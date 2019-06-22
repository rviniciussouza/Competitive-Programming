#include <bits/stdc++.h>
using namespace std;

const int MN = 10010;
vector<int> G[MN], R[MN];
stack<int> pilha;
bool vis[MN];
int n;

int dfsStack(int u) {
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!vis[v]) dfsStack(v);
    }
    pilha.push(u);
}

int inverteGrafo() {
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < G[i].size(); ++j)
            R[G[i][j]].push_back(i);
}

int dfs(int u) {
    vis[u] = true;
    for(int i = 0;i < R[u].size(); ++i) {
        int v = R[u][i];
        if(!vis[v]) dfs(v);
    }
}

int Kosajaru() {
    memset(vis, false, sizeof vis);
    for(int i = 0; i < n; ++i)  
        if(!vis[i]) dfsStack(i);

    inverteGrafo();

    memset(vis, false, sizeof vis);

    int cnt_c = 0;
    while(!pilha.empty()) {
        int v = pilha.top(); 
        if(!vis[v]) {
            dfs(v);
            cnt_c++;
        }
        pilha.pop();
    }
    return cnt_c;
}

int main() {

    int u, v;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &v);
        G[u-1].push_back(v-1);
    }

    int cnt_c = Kosajaru();
    printf("%s\n", cnt_c > 1 ? "N" : "S");

    return 0;
}