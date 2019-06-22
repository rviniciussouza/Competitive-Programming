#include <bits/stdc++.h>
using namespace std;

const int MN = 11234;
const long long INF = 100000000;
typedef pair<long long, long long> ii;
vector<vector<ii> > G(MN);
int custo[MN];

struct compare
{
    bool operator() (const ii& x, const ii& y) const
    {
        return x.second > y.second;
    }
};

int n;


long long dijkstra() {

    vector<long long> dist(MN, INF);
    priority_queue<ii, vector<ii>, compare> pq;
    pq.push(ii(0, 0));
    dist[0] = 0;

    while(!pq.empty()) {
        ii v = pq.top(); pq.pop();
        for(int i = 0; i < G[v.first].size(); ++i) {
            ii u = G[v.second][i];
            if(dist[u.first] > dist[v.first] + u.second + custo[u.first]) {
                dist[u.first] = dist[v.first] + u.second + custo[u.first];
                pq.push(ii(u.first, dist[u.first]));
            }
        }
    }

    return dist[n + n + 1];
}

int main() {


    long long v, w;

    while(scanf("%d", &n) == 1) {

        for(int i = 0; i < MN; ++i) {
            custo[i] = 0;
            G[i].clear();
        }

        cin >> w;
        G[0].push_back(ii(1, w));
        cin >> w;
        G[0].push_back(ii(n + 1, w));

        for(int i = 1; i <= n; ++i) {
            cin >> custo[i];
        }

        for(int i = 1; i <= n; ++i) {
            cin >> custo[n + i];
        }

        for(int i = 1; i < n; ++i) {
            G[i].push_back(ii(i+1, 0));
            G[n+i].push_back(ii(n+i+1, 0));
        }

        for(int i = 1; i < n; ++i) {
            cin >> w;
            G[i].push_back(ii(n + i + 1, w));
        }

        for(int i = 1; i < n; ++i) {
            cin >> w;
            G[n+i].push_back(ii(i + 1, w));
        }

        cin >> w;
        G[n].push_back(ii(n + n + 1, w));

        cin >> w;
        G[n + n].push_back(ii(n + n + 1, w));
    
        cout << dijkstra() << '\n';
    
    }

    return 0;
}