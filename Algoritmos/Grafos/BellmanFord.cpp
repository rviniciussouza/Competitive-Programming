#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int nvertices;
vector<vector<ii> > adj;

bool BellmanFord(int src)
{
    vector<int> dist(nvertices);
    memset(&dist, INT_MAX, sizeof dist);
    dist[src] = 0;

    //Distancia minima
    for(int i= 0; i <  nvertices - 1; ++i)
        for(int j=0; j < nvertices; ++j)
            for(int k = 0; k < adj[j].size(); ++k) {
                ii u = adj[j][k];
                if(dist[j] != INT_MAX && dist[u.first] > dist[j] + u.second)
                    dist[u.first] = dist[j] + u.second;
            }

    //Detectando ciclo negativo - return true se encontra ciclo negativo
    for(int i= 0; i <  nvertices - 1; ++i)
        for(int j=0; j < nvertices; ++j)
            for(int k = 0; k < adj[j].size(); ++k) {
                ii u = adj[j][k];
                if(dist[j] != INT_MAX && dist[u.first] > dist[j] + u.second) return true;
            }
    
    return false;
}