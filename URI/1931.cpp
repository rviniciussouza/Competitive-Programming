#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

struct compare
{
    bool operator() (const ii& x, const ii& y) const
    {
        return x.second > y.second;
    }
};

int main()
{
    int V, E, u, v, w;
    scanf("%d %d", &V, &E);

    vector<vector<ii> > G;
    G.resize(V);
    for(int i=0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w); u--; v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));        
    }

    //Grafo auxiliar
    vector<vector<ii> > T;
    T.resize(V);

    for(int u=0; u < V; ++u)
        for(int i=0; i < G[u].size(); ++i)
            for(int k=0; k < G[G[u][i].first].size(); ++k)
                if(G[G[u][i].first][k].first != u)
                    T[u].push_back(make_pair(G[G[u][i].first][k].first, G[u][i].second + G[G[u][i].first][k].second));
    
    bool vis[V];
    int dist[V];

    for(int i=0; i < V; ++i)
    {
        dist[i] = INT_MAX;
        vis[i] = false;
    }

    priority_queue<ii,vector<ii>,compare > pq;
    ii aux;
    aux.first = 0; aux.second = 0;
    dist[0] = 0;
    vis[0] = true;

    pq.push(aux);

    while(!pq.empty())
    {
        ii v = pq.top(); pq.pop();
        vis[v.first] = true;

        for(int i=0; i < T[v.first].size(); ++i)
        {
            ii u = T[v.first][i];
            if(vis[u.first] == false)
            {
                if(dist[u.first] > (dist[v.first] + u.second))
                {
                    aux.second = dist[v.first] + u.second;
                    aux.first = u.first;
                    dist[u.first] = aux.second;
                    pq.push(aux);
                }
            }
        }
    }

    if(dist[V - 1] == INT_MAX)
       printf("-1\n");
    else printf("%d\n", dist[V-1]);

    return 0;
}