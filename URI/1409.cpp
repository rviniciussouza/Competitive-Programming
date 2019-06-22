#include <bits/stdc++.h>
using namespace std;
const int MN = 1010;
const long long INF = 1111222333;

typedef pair<int, int> ii;
typedef long long int LLI; 

int M, N, T, K, vis[MN];
LLI custo[MN], dp[MN];
vector<ii> G[MN];
ii magia[MN], monstro[MN];

long long f(int w) {

    if(w <= 0) return 0;
    if(vis[w] == 1) return dp[w];
    vis[w] = 1;
    for(int i = 0; i < M; ++i) {
        dp[w] = min(dp[w], magia[i].first + f(w - magia[i].second));
    }
    return dp[w];
}

struct compare
{
    bool operator() (const ii& x, const ii& y) const
    {
        return x.second > y.second;
    }
};


int caminho_minimo(int src, int dest) {

    vector<int> dist(N+1, INF);
    priority_queue<ii, vector<ii>, compare> pq;
    pq.push(ii(src, 0));
    dist[src] = custo[src];
    while(!pq.empty()) {
        int u = pq.top().first; pq.pop();
        for(int i = 0; i < G[u].size(); ++i) {
            ii v = G[u][i];
            if(dist[v.first] > dist[u] + custo[v.first]) {
                dist[v.first] = dist[u] + custo[v.first];
                pq.push(ii(v.first, dist[v.first]));
            }
        }   
    }

    return dist[dest];

}

int main() {

    int u, v;
    while(scanf("%d %d %d %d", &M, &N, &T, &K) && M != 0) {

        for(int i = 0; i <= N; ++i) G[i].clear();

        for(int i = 0; i < M; ++i) {
            scanf("%d %d", &magia[i].first, &magia[i].second);
        }

        for(int i = 0; i < T; ++i) {
            scanf("%d %d", &u, &v);
            G[u].push_back(ii(v, 0));
            G[v].push_back(ii(u, 0));
        }

        for(int i = 0; i < K; ++i) {
            scanf("%d %d", &monstro[i].first, &monstro[i].second);
        }

        memset(vis, 0, sizeof vis);
        memset(dp, INF, sizeof dp);
        memset(custo, 0LL, sizeof custo);

        for(int i = 0; i < K; ++i) {
            custo[monstro[i].first] += f(monstro[i].second);
        }

        int ans = caminho_minimo(1, N); 
        
        printf("%lld\n", ans == INF ? -1LL : ans);
    
    }

    return 0;
}