#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<vector<int> > vv;
vector<vector<ii> > adj;
int n, e;

void Floyd(vv &dist)
{
    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            for(int k=0; k < n; ++k)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]); 
}

int main()
{
    int u, v, w;

    cin>>n>>e;
    vv dist(n, vector<int>(n));

    for(int i=0; i < e; ++i) {
        cin>>u>>v>>w;
        dist[u][v] = w;
    }

    return 0;
}
