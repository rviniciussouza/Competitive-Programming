#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;

int dist[510][510];

int main() 
{

    int n, m, u, w, v, q, k = 0;

    while(true) {
        scanf("%d %d",&n, &m);
        if(n == 0) break;
        
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                dist[i][j] = i == j ? 0 : INF;

        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            if(dist[v][u] < INF) {
                dist[u][v] = dist[v][u] = 0;
            }
            else dist[u][v] = w;
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k <= n; ++k) 
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);

    
        scanf("%d", &q);

        for(int i = 0; i < q; ++i) {
            scanf("%d %d", &u, &v);
            if(dist[u][v] != INF) printf("%d\n", dist[u][v]);
            else printf("Nao e possivel entregar a carta\n");
        }
        printf("\n");

    }

    return 0;

}