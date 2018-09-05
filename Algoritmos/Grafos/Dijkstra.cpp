#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int INF = 1e9 + 10;

struct compare
{
    bool operator() (const ii& x, const ii& y) const
    {
        return x.second > y.second;
    }
};

vector<vector<ii> > adj;
int aretas, vertices;

void Dijkstra(int src) {
    vector<int> dist(vertices, INF);
    priority_queue<ii, vector<ii>, compare> pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;

    while(!pq.empty()) {
        ii v = pq.top(); pq.pop();
        for(unsigned int i=0; i < adj[v.first].size(); ++i) {
            ii u = adj[v.first][i];
            if(dist[u.first] > dist[v.first] + u.second)
                pq.push(make_pair(u.first, dist[u.first] = dist[v.first] + u.second));
        }
    }
}

int main(){}
