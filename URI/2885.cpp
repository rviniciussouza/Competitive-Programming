#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > pontos(110);

#define INF 10000000

struct aresta {
    int u;
    int v;
    double w;

    aresta(int x, int y, int dist) {
        u = x; v = y; dist = w;
    }
};

vector<aresta> arestas;

double dist(int p1, int p2) {
    int x1 = pontos[p1].first;
    int x2 = pontos[p2].first;
    int y1 = pontos[p1].second;
    int y2 = pontos[p2].second;

    return sqrt(((x1-x2)<<1) + ((y1-y2)<<1));
}

int main() {

    int n, k, x, y;

    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
    }

    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            if(i != j) {

                int melhor_ponto, dist_melhor_ponto = INF;

                for(int p = k; p < n; ++p) {
                    int dist_i = dist(i, p);
                    int dist_j = dist(j, p);

                    if(dist_i + dist_j < dist_melhor_ponto) {
                        melhor_ponto = p;
                        dist_melhor_ponto = dist_i + dist_j;
                    }
                }

                arestas.push_back(aresta(i, melhor_ponto, dist(i, melhor_ponto)));
                arestas.push_back(aresta(j, melhor_ponto, dist(j, melhor_ponto)));
            }
        }
    }

    cout << arestas[0].u << ' ' << arestas[0].v << ' ' << arestas[0].w;


    return 0;
}