#include <vector>
#include <iostream>
#include <utility>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<long long> vi;

const long long MN = 11;
const long long INF = 10000000001110;

int G[12][12], dist[12][12];
ii inicio;

int BFS() {

    queue<ii> fila;
    fila.push(inicio);
    dist[inicio.first][inicio.second] = 0;

    while(!fila.empty()) {

        ii v = fila.front(); fila.pop();

        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(i != j && i + j != 0) {
                    if(G[v.first + i][v.second + j] == 0) {
                        return dist[v.first][v.second] + 1;
                    }

                    else if(G[v.first + i][v.second + j] == 1) {
                        G[v.first + i][v.second + j] = -1;
                        dist[v.first + i][v.second + j] = dist[v.first][v.second] + 1;
                        fila.push(ii(v.first + i, v.second + j));
                    }
                }
            }
        }
    }

}

int main() {

    int n, m, v;

    cin >> n >> m;

    memset(G, -1, sizeof G);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> v;
            if(v == 3) {
                inicio.first = i;
                inicio.second = j;
            }
            G[i][j] = v;
        }
    }

    printf("%d\n", BFS());

    return 0;
}