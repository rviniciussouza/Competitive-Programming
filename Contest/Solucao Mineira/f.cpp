#include <bits/stdc++.h>
#define INF 100000000000000000LL
using namespace std;
typedef long long int ll;

const int N = 5005;
const int L = 15;

vector < int > g[N];

ll poe[N], tira[N], vende[N], val[N], nv[N], ant[N][L], dp[N][1010];

void build(int u, int p)
{
    val[u] = poe[u];
    for (auto v : g[u])
        if (v != p)
            build(v, u),
            val[u] += val[v] - tira[v];
}

int dfs(int u, int p)
{
    ant[u][0] = p;
    for (int i=1; i<L; i++){
        ant[u][i] = ant[ant[u][i-1]][i-1];
    }
    for (int v :g[u]){
        if(v == p) continue ;
        nv[v] = nv[u] + 1;
        dfs(v, u);
    }
}

int LCA(int u, int v)
{
    if(nv[u] < nv[v]) swap(u, v);
    int dist = nv[u] - nv[v];
    for (int i = 0; i < L; ++i)
        if (dist & (1 << i))
            u = ant[u][i];
    if(u == v)
        return u;
    for (int i=L-1; i>=0; i--){
        if(ant[u][i] != ant[v][i]) {
            u = ant[u][i], v = ant[v][i];
        }
    }
    return ant[u][0];
}

vector < pair < ll, ll > > mochila;

ll back(int id, ll k){
    if(k < 0) return -INF;
    if(id == mochila.size()) return 0;
    if(dp[id][k] != -INF * 2) return dp[id][k];
    return dp[id][k] = max(back(id+1, k - mochila[id].second) + mochila[id].first, back(id+1, k));
}


int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    for (int i=0; i<n-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    nv[1] = 0;
    dfs(1, 1);
    int m;
    scanf("%d", &m);
    memset(vende, -1, sizeof vende);
    while (m--){
        int c, v;
        scanf("%d %d", &c, &v);
        vende[c] = v;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x, y, l;
        scanf("%d %d %d", &x, &y, &l); 
        if (x == y) {
            poe[x] += l,
            tira[x] += l;
            continue;
        }
        int lca = LCA(x, y);
        poe[x] += l;
        poe[y] += l;
        poe[lca] -= l;
        tira[lca] += l;
    }
    build(1, 1);
    for (int i=1; i<=n; i++){
       if(vende[i] != -1){
           mochila.push_back(make_pair(val[i], vende[i]));
       }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 1010; ++j)
            dp[i][j] = -INF * 2;
    printf("%lld\n", back(0, d));
}