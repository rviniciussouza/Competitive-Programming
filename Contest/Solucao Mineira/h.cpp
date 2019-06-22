#include <bits/stdc++.h>

#define inf 0x3f3f3f3f3f3f3f3f
#define maxn 302
#define mp make_pair

typedef long long ll;

using namespace std;

struct Aresta{
    int dest;
    ll c, b;
    Aresta(int dest, int c, int b) {
        this->dest = dest;
        this->c = c;
        this->b = b;
    }
};

bool menor(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first * b.second < a.second * b.first;
}

struct Trem{
    int v;
    ll num, den;
    
    Trem (int v, ll num, ll den) {
        this->v = v;
        this->num = num;
        this->den = den;
    }
    bool operator <(const Trem& other) const {
        return !menor(mp(this->num, this->den), mp(other.num, other.den)); // pra retornar o maior msm
    }
};

int n;
ll ans_n, ans_d;
pair<ll, ll> dist[maxn];
vector<Aresta> g[maxn];

void solve(int ini) {
    for (int i=1;i<=n;i++)
        dist[i] = mp(inf, 1);
    
    priority_queue<Trem> pq;
    pq.push(Trem(ini, 0LL, 0LL));
    
    while (!pq.empty()) {
        int v = pq.top().v;
        ll num = pq.top().num;
        ll den = pq.top().den;
        pq.pop();

        for (int i=0;i<g[v].size(); i++) {
            int u = g[v][i].dest;
            ll c = g[v][i].c;
            ll b = g[v][i].b;
            
            if (menor(mp(num+c, den+b), dist[u])) {
                dist[u] = mp(num+c, den+b);
                pq.push(Trem(u, num+c, den+b));
            }
        }
    }

    if (ans_n == inf || menor(dist[ini], mp(ans_n, ans_d))) {
        ans_n = dist[ini].first;
        ans_d = dist[ini].second;
    }
}

main() {
    int m;
    scanf("%d %d", &n, &m);
    
    for (int i=0;i<m;i++) {
        int u, v;
        ll c, b;
        scanf("%d %d %lld %lld", &u, &v, &c, &b);
        g[u].push_back(Aresta(v, c, b));
        g[v].push_back(Aresta(u, c, b));
    }
    
    ans_n = inf;
    ans_d = 1;
    for (int i=1;i<=n;i++)
        solve(i);
    
    printf("%.8lf\n", double(ans_n) / ans_d);
}