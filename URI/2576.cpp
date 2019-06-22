#include <bits/stdc++.h>
using namespace std;

#define INF 1123456

typedef pair<int, int> ii;
const int MN = 11234;

int n, m;

struct compare
{
    bool operator() (const ii& x, const ii& y) const
    {
        return x.second > y.second;
    }
};



int Dijkstra(int src, int dest, vector<vector<ii> >& G) {
    vector<int> dist(n+1, INF);
    priority_queue<ii, vector<ii>, compare> pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;

    while(!pq.empty()) {
        ii v = pq.top(); pq.pop();
        for(int i = 0; i < G[v.first].size(); ++i) {
            ii u = G[v.first][i];
            if(dist[u.first] > dist[v.first] + u.second) {
                pq.push(make_pair(u.first, dist[u.first] = dist[v.first] + u.second));
            }
        }
    }

    return dist[dest];
}

int main() {

    int u, v, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);

    vector<vector<ii> > G(n+1);
    vector<vector<ii> > A(n+1);
    vector<vector<ii> > B(n+1);

    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(make_pair(v, 0));
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < G[i].size(); ++j) {
            int v = G[i][j].first;
            A[v].push_back(make_pair(i, 1));
            A[i].push_back(make_pair(v, 0));

            B[v].push_back(make_pair(i, 1));
            B[i].push_back(make_pair(v, 0));
        }
    }

    int c1 = Dijkstra(a, b, A);
    int c2 = Dijkstra(b, a, B);

    if(c1 == INF or c1 == c2) printf("Bibibibika\n");
    else if(c1 < c2) printf("Bibi: %d\n", c1);
    else printf("Bibika: %d\n", c2);
    
    return 0;
}