#include <bits/stdc++.h>
using namespace std;

const int MN = 500;
typedef pair<int, int> ii;
typedef vector<pair<int, ii>> edges;
int grid[MN][MN], children[MN], pi[MN];
edges A, B;

int find_parent(int u)
{
    while (u != pi[u])
    {
        u = pi[u];
    }
    return u;
}

void UnionSet(int ku, int kv)
{
    if (children[kv] > children[ku])
    {
        pi[kv] = ku;
        children[ku] += children[kv];
    }
    else
    {
        pi[ku] = kv;
        children[kv] += children[ku];
    }
}

int Kruskal(edges& arestas)
{
    int n = arestas.size();
    int custo_total = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int u = arestas[i].second.first;
        int v = arestas[i].second.second;
        int ku = find_parent(u);
        int kv = find_parent(v);

        if (ku != kv)
        {
            UnionSet(ku, kv);
            custo_total += arestas[i].first;
        }
    }
    return custo_total;
}


int main()
{

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int custo_total_remover = 0;    
    for (int i = 0; i < N; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (grid[j][i] == 0)
            {
                A.push_back(make_pair(grid[i][j], ii(i, j)));
            }
            else
            {
                custo_total_remover += grid[i][j]; 
                B.push_back(make_pair(grid[i][j], ii(i, j)));
            }
        }
    }

    for (int i = 0; i < N; ++i)
        pi[i] = i, children[i] = 1;
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int ans = Kruskal(B);
    ans = custo_total_remover - ans;
    ans += Kruskal(A);
    
    printf("%d\n", ans);

    return 0;
}