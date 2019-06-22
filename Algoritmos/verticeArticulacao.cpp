#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

//  https://br.spoj.com/problems/MANUT/

const int MN = 500;
set<int> vertice_corte;

int vis[MN];
vector<vector<int> > G(MN);
 
int dfs(int u, int ant, int timer) {
 
    vis[u] = timer++;
    int menor_ancestral = vis[u];
    int qtd_filhos = 0;
 
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v] == 0) {
            qtd_filhos++;
            int m = dfs(v, u, timer);
            menor_ancestral = min(menor_ancestral, m);
        
            if(vis[u] <= m && (u!=1 || qtd_filhos >=2 )){
               vertice_corte.insert(u);
            }
        }
 
        else if(v != ant) {
            menor_ancestral = min(menor_ancestral, vis[v]);
        }
    }
 
    return menor_ancestral;
}
 
int main() {
 
    int n, m, u, v, k = 1;
 
    while(true) {
        scanf("%d %d", &n, &m);
        if(n == 0) break;
        
        memset(vis, 0, sizeof vis);
        vertice_corte.clear();
 
        for(int i = 1; i <= n; ++i)
            G[i].clear();
        
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
 
        dfs(1, -1, 1);
 
        if(k > 1) printf("\n");
 
        if(vertice_corte.size() == 0) {
            printf("Teste %d\n", k++);
            printf("nenhum\n");
        }
 
        else {
            printf("Teste %d\n", k++);
            for(set<int>::iterator i = vertice_corte.begin(); i != vertice_corte.end(); i++) {
                if(i != vertice_corte.begin()) printf(" ");
                printf("%d", *i);
            }
            printf("\n");
        }
    }
 
    return 0;
} 