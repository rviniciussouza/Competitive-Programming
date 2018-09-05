#include <bits/stdc++.h>
using namespace std;

#define MAX_n 10010
typedef pair<int, int> ii;
typedef vector<vector<int> > vv;

typedef struct
{
    int u, v, w;
}E;

bool vis[MAX_n];
int qtdF[MAX_n];
int parent[MAX_n];

void dfsRStack(vv& G, stack<int>& timeE, int u)
{
    vis[u] = true;
    for(unsigned int i=0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if(!vis[v])
            dfsRStack(G, timeE, v);
    }

    timeE.push(u);
}

int dfs(vv& G, int u)
{
    vis[u] = true;
    int k = 0;
    for(unsigned int i=0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if(!vis[v])
        {
            k += dfs(G, v);
            k++;
        }
    }

    return k;
}

//Componentes conexas
int kosajaru(vv& G, int n)
{
    stack<int> timeE;
    for(int i=0; i < n; ++i)
        dfsRStack(G, timeE, i);

    int k = 0;
    while(!timeE.empty())
    {
        int v = timeE.top();
        timeE.pop();

        if(!vis[v])
        {
            k++;
            dfs(G, v);
        }
    }

    return k;
}

struct{
    bool operator()(E a, E b) const {   
        return b.w > a.w;
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

//Árvore Geradora minima
long long Kruskal(vector<E>& arestas, int n)
{
    Kruskalinit(n);
    sort(arestas.begin(), arestas.end(), compare);

    int k = 0;
    long long custo = 0;
    for(int i=0; i < arestas.size(); ++i)
    {
        int u = KruskalFind(arestas[i].u);
        int v = KruskalFind(arestas[i].v);
        if(u != v)
        {
            Union(u, v);
            custo += arestas[i].w;
            k++;
        }
    }

    return custo;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, k, v;
    E add;
    scanf("%d", &n);

    vv G;
    G.resize(n);
    vector<E> arestas;

    for(int i=0; i < n -1; ++i)
    {
        scanf("%d", &k);
        while(k) {
            scanf("%d %d", &v, &w); v--;
            G[i].push_back(v);  
            G[v].push_back(i);

            add.u = i; add.v = v; add.w = w;
            arestas.push_back(add);

            --k;
        }
    }

    int familias = kosajaru(G, n);
    long long custo = Kruskal(arestas, n);

    printf("%d %lld\n", familias, custo);


    return 0;
}