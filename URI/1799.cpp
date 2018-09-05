#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > G;
int vis[4010];
int dist[4010];
int n, m;

int BFS(int src, int dest)
{
    memset(vis, false, sizeof vis);
    // memset(dist, 0, sizeof dist);
    queue<int> fila;

    fila.push(src);
    dist[src] = 0;
    vis[src] = true;
    while(!fila.empty())
    {
        int u = fila.front(); fila.pop();
        for(int i=0; i < G[u].size(); ++i)
        {
            if(!vis[G[u][i]]) {
                fila.push(G[u][i]);
                dist[G[u][i]] = dist[u] + 1;
                vis[G[u][i]] = true;
            }
        }

    }

    return dist[dest];
}

int main()
{
    int u, v;
    string U, V, entrada, saida;

    scanf("%d %d", &n, &m);

    G.resize(n);    

    map<string, int> M; 

    int t = 0;
    for(int i=0; i < m; ++i)
    {
        cin>>U>>V;
        if(M.find(U) == M.end()) M[U]=t++;
        if(M.find(V) == M.end()) M[V]=t++;
        int u = M[U];
        int v = M[V];

        G[u].push_back(v);
        G[v].push_back(u);
    }


    printf("%d\n", BFS(M["Entrada"], M["*"]) + BFS(M["*"], M["Saida"]));

    return 0;
}
