#include <bits/stdc++.h>
using namespace std;

const int MN = 10010;
typedef pair<int, pair<int, int> > ii;
ii arestas[MN];
int children[MN], pi[MN];

int find_parent(int u) {

    while(u != pi[u]) {
        u = pi[u];
    }
    return u;
}

void UnionSet(int ku, int kv) {

    if(children[kv] > children[ku]) {
        pi[kv] = ku;
        children[ku] += children[kv];
    }
    else {
        pi[ku] = kv;
        children[kv] += children[ku];
    }
}

int Kruskal(int n) {

    int custo_total = 0;
    sort(arestas, arestas + n);
    for(int i = 0; i < n; ++i) pi[i] = i, children[i] = 1;
    for(int i = 0; i < n; ++i) {

        int u = arestas[i].second.first;
        int v = arestas[i].second.second;
        int ku = find_parent(u);
        int kv = find_parent(v);

        if(ku != kv){
            UnionSet(ku, kv);
            custo_total += arestas[i].first;
        }
    }
    return custo_total;
}


int main() {

    int m, n, u, v, w;

    while(scanf("%d %d", &n, &m) && n) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            arestas[i] = ii(w, {u, v});
        }
        cout << Kruskal(m) << '\n';
    }

    return 0;
}