#include <bits/stdc++.h>
using namespace std;

/*
 * Heavy Light Decomposition
 * query and update 0(log n)
 */


const int MAXN = 5e3 + 10;
const int INF = 1e9 + 10;

#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)

int ncha;
int parent[MAXN], fson[MAXN], size[MAXN];
int nchain[MAXN], id[MAXN], depth[MAXN], up[MAXN];
vector<int> G[MAXN], chain[MAXN];

class SegmentTree {
private:

    vector<int> st, lazy;
    int size;

    void update(int si, int l, int r, int a, int b, int value) {
        if(lazy[si] != 0) {
            st[si] += (r - l + 1) * lazy[si];
            if(l != r) {
                lazy[left(si)] += lazy[si];
                lazy[right(si)] += lazy[si];
            }
            lazy[si] = 0;
        }
        
        if(a > r || b < l) return;

        if(l >= a && r <= b) {
            st[si] += (r -l + 1) * value;
            if(l != r) {
                lazy[left(si)] += value;
                lazy[right(si)] += value;
            }
        }

        else {
            update(left(si), l, (l + r) / 2, a, b, value);
            update(right(si), (l + r) / 2 + 1, r, a, b, value);
            st[si] = st[left(si)] + st[right(si)];
        }
    }

    int query(int si, int l, int r, int a, int b) {
        if(lazy[si] != 0) {
            st[si] += (r - l + 1) * lazy[si];
            if(l != r) {
                lazy[left(si)] += lazy[si];
                lazy[right(si)] += lazy[si];
            }
            lazy[si] = 0;
        }    

        if(l >= a && r <= b) return st[si];
        if(a > r || l > b) return 0;
        return query(left(si), l, (l + r) / 2, a, b) +
            query(right(si), (l + r) / 2 + 1, r, a, b);
    }


public:
    SegmentTree(int sz) {
        size = sz;
        st.assign(size * 4, 0);
        lazy.assign(size * 4, 0);
    }

    int query(int a, int b) {
        return query(1, 0, size - 1, a, b);
    }

    void update(int a, int b, int value) {
        update(1, 0, size - 1, a, b, value);
    }

};

int chainsz(int u, int p) {
    size[u] = 1; fson[u] = -1; parent[u] = p;
    int heavy = 0;
    for(int i=0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(v == p) continue;
        size[u] += chainsz(v, u);
        if(size[v] > heavy) {
            fson[u] = v; heavy = size[v];
        }
    }
    return size[u];
}

void build(int u, int ch, int h) {
    nchain[u] = ch; id[u] = chain[ch].size();
    chain[ch].push_back(u);
    for(int i=0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if(v == parent[u]) continue;
        if(v == fson[u]) build(v, ch, h + 1);
        else {
            up[ncha] = u; depth[ncha] = h;
            chain[ncha].clear();
            build(v, ncha++, h + 1);
        }
    }
}

vector<SegmentTree> hld;

void HLD(int root) {
    chainsz(root, -1);
    ncha = 0;
    chain[ncha].clear();
    up[ncha] = -1; depth[ncha] = 0;
    build(root, ncha++, 1);

    for(int i=0; i < ncha; ++i) {
        hld.push_back(SegmentTree(chain[i].size()));
    }
}

void update(int u, int v, int value) {
    int cu = nchain[u], cv = nchain[v];
    while(cu != cv) {
        if(depth[cu] > depth[cv]) {
            hld[cu].update(0, id[u], value);
            u = up[cu];
        }

        else {
            hld[cv].update(0, id[v], value);
            v = up[cv];
        }
        cu = nchain[u]; cv = nchain[v];
    }

    if (id[u] < id[v]) {
        hld[cu].update(id[u], id[v], value);
    }
    else {
        hld[cu].update(id[v], id[u], value);
    }
}



int main() {

    int n, d, u, v, w, m, q;

    scanf("%d %d", &n , &q);

    for(int i=0; i < n -1; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    HLD(1);

    int x, y;

    u = 1; v = 4;    

    update(u, v, 1);
    update(u, v, 1);
    update(u, v, 1);

    cout << hld[nchain[u]].query(id[1], id[4]) << '\n';
    cout << hld[nchain[u]].query(id[u], id[3]) << '\n';


    // for(int i = 0; i < q; ++i) {

    //     scanf("%d %d %d %d", &u, &v, &x, &y);
    //     update(u, v, 1);
    //     cout << hld[nchain[u]].query(id[u], id[v]) << '\n';
    //     update(u, v, 0);

    // }

    return 0;
}