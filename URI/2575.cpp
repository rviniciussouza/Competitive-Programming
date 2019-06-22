#include <bits/stdc++.h>
using namespace std;

const long long MN = 1e6 + 10;
typedef pair<int, int> ii;

struct aresta {
    int id;
    int v;
    int w;

    aresta() {}
    aresta(int a, int b, int c) {
        id = a; v = b; w = c; 
    }
};

vector<vector<aresta> > G(MN);
int beleza_sub_arvore[MN];
bool galho_cortado[MN];

int qtd_cortes = 0;

void corte(int cur, int ant) {

    for(int i = 0; i < G[cur].size(); ++i) {
        int v = G[cur][i].v;
        if(v != ant) {
            if(G[cur][i].w + beleza_sub_arvore[v] <= 0) {
                qtd_cortes++;
                galho_cortado[G[cur][i].id] = true;
            }

            else {
                corte(v, cur);
            }
        }
    }
}

int dfs(int cur, int ant) {

    int soma_beleza = 0;
    for(int i = 0; i < G[cur].size(); ++i) {
        if(G[cur][i].v != ant) {
            int result = dfs(G[cur][i].v, cur);
            if(result + G[cur][i].w >= 0) {
                soma_beleza += result + G[cur][i].w;
            } 
        }
    }
    return beleza_sub_arvore[cur] = soma_beleza;
}

int main() {


    int n, u, v, w, id;

    cin >> n;

    for(int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d %d", &id, &u, &v, &w);
        G[u].push_back(aresta(id, v, w));
        G[v].push_back(aresta(id, u, w));
    }

    memset(galho_cortado, false, sizeof galho_cortado);
    memset(beleza_sub_arvore, 0, sizeof beleza_sub_arvore);

    int beleza = dfs(0, -1);
    corte(0, -1);

    printf("%d %d\n", beleza, qtd_cortes);

    bool flag = true;
    for(int i = 0; i < n - 1; ++i) {
        if(galho_cortado[i]) {
            if(flag) printf("%d", i), flag = false;
            else printf(" %d", i);
        } 
    }printf("\n");

    return 0;
}