#include <bits/stdc++.h>
using namespace std;

#define lim 1000001
#define MAX_n 20010

typedef pair<int, int> ii;
typedef vector<vector<ii> > vv;

typedef struct{
    int u, v , w;
}E;

int parent[MAX_n];
int qtdF[MAX_n];
int level[MAX_n];
int peso[MAX_n];

typedef pair<int, int> ii;

struct{
    bool operator()(E a, E b) const {   
        return b.w < a.w;
    }   
} compare;

void Kruskalinit(int n)
{
    for(int i=0; i < n; ++i)
    {
        parent[i] = i;
        qtdF[i] = 1;
    }
}

int KruskalFind(int u)
{
    while(u != parent[u])
        u = parent[u];
    return u;
}

void Union(int u, int v)
{
    if(qtdF[u] < qtdF[v]) {
        parent[u] = v;
        qtdF[v] += qtdF[u];
    }

    else {
        parent[v] = u;
        qtdF[u] += qtdF[v];
    }
}

void Kruskal(vector<E>& arestas, vv& G, int n)
{
    Kruskalinit(n);
    sort(arestas.begin(), arestas.end(), compare);

    int k = 0;
    for(int i=0; k < n - 1; ++i)
    {
        int u = KruskalFind(arestas[i].u);
        int v = KruskalFind(arestas[i].v);
        if(u != v)
        {
            Union(u, v);
            G[arestas[i].u].push_back(make_pair(arestas[i].v, arestas[i].w));
            G[arestas[i].v].push_back(make_pair(arestas[i].u, arestas[i].w));
            k++;
        }
    }
}

//vertice, peso, altura
void make_tree(vector<bool>& vis, vv& G, int u, int pai, int l)
{
    parent[u] = pai;
    level[u] = l;

    for(unsigned int i=0; i < G[u].size(); ++i)
    {
        int v = G[u][i].first;
        int w = G[u][i].second;

        if(!vis[v])
        {
            vis[v] = true;    
            peso[v] = w;
            make_tree(vis, G, v, u, l+1);
        }
    }
}


int lca(int u, int v)
{
    int m = lim;

    while(u != v)
    {
        if(level[u] > level[v])
        {
            m = min(m, peso[u]);                        
            u = parent[u];
        }    

        else
        {
            m = min(m, peso[v]);                                    
            v = parent[v];
        }
    }

    return m;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s, u, v;
    E add;
    while(scanf("%d %d %d", &n, &m, &s) != EOF)
    {
        vector<E> arestas(m);
        for(int i=0; i < m; ++i)
        {
            scanf("%d %d %d", &add.u, &add.v, &add.w); add.u--; add.v--;
            arestas.push_back(add);
        }

        vv G(n); 
        Kruskal(arestas, G, n);
        vector<bool> vis(n);
        vis[0] = true;
        peso[0] = lim;
        make_tree(vis, G, 0, 0, 0);

        while(s)
        {
            scanf("%d %d", &u, &v);
            printf("%d\n", lca(u-1, v-1)); 
            --s;
        }
    }
}

