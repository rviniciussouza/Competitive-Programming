#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for(int x = 0; (x) < (n); ++(x))
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define parent(x) (x >> 1)
#define MOD 1000000007LL
typedef pair<int, int> ii;
const int MN = 2e5 + 10;
const int INF = 1e4 + 10;

ii pokemon[MN];
vector<ii> st(MN * 4, ii(-INF, -1));
int pos[MN];


void build(int p, int l, int r) {
    if(l == r) {
        st[p] = pokemon[l];
        pos[l] = p;
    }

    else {
        build(left(p), l, (l + r) / 2);
        build(right(p), (l + r) / 2 + 1, r);
        st[p] = max(st[left(p)], st[right(p)]);
    }
}

ii find(int p, int l, int r, int a, int b) {
    if(a > r || b < l) return ii(-INF,-1);
    if(l >= a && r <= b) return st[p];
    ii f1 = find(left(p), l, (l + r) / 2, a, b);
    ii f2 = find(right(p), (l + r) / 2 + 1, r, a, b);
    return max(f1, f2);
}

void update(int p, ii valor) {
    st[pos[p]] = valor;
    p = parent(pos[p]);
    while(p > 0) {
        st[p] = max(st[left(p)], st[right(p)]);
        p = parent(p);
    }
}

ii query(int n, int a, int b) {
    return find(1, 0, n - 1, a, b);
}

int main() {
    
    int n, r, k, a, b;

    cin >> n >> k >> r;
    
    FOR(i, n) {
        cin >> pokemon[i].first;
        pokemon[i].second = i;
    }

    // memset(st, ii(-INF, -1), sizeof st);
    build(1, 0, n - 1);

    vector<int> usados;

    FOR(i,r) {
        cin >> a >> b;
        long long ans = 1;
        FOR(j,k) {
            ii maior = query(n, a-1, b-1);
            if(maior.first <= 0) break;
            else {
                ans = (ans * (long long)maior.first) % MOD;
                update(maior.second, ii(-INF, -1));
                usados.push_back(maior.second);
            }
        }

        if(usados.size() == 0) puts("0");
        else {
            printf("%lld\n", ans);
            while(!usados.empty()) {
                update(usados.back(), pokemon[usados.back()]);
                usados.pop_back();
            }
        }
    }


    return 0;
}