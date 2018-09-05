#include <bits/stdc++.h>
using namespace std;

#define MAX_n 1010

int parent[MAX_n];
int qtdF[MAX_n];

typedef pair<int, int> ii;

typedef struct{
    int u, v , w;
}E;

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

void Kruskal(vector<E>& arestas, int n)
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
            k++;
        }
    }
}

int main()
{
    int n, u, v, w;
    scanf("%d", &n);

    E add;
    vector<E> arestas;
    for(int i=0; i < n; ++i)
    {
        scanf("%d %d %d", &E.u, &E.v, &w); E.u--; E.v--;
        arestas.push_back(add);
    }

    Kruskal(arestas);

    return 0;
}