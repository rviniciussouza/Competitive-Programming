#include <bits/stdc++.h>
using namespace std;

struct aresta {
    int u;
    int v;
    int w;

    aresta() {}

    aresta(int x, int y, int dist) {
        u = x; v = y; w = dist;
    }
};

const int MANN = 1000 * 1000;

int boss[MANN];
int qtd_f[MANN];
vector<aresta> arestas(MANN);

bool compare(aresta a, aresta b) {
    return a.w < b.w;
}

int BossFind(int u)
{
	int aux = u;
	while(aux != boss[aux])
		aux = boss[aux];
	return aux;
}


void FUnion(int u, int v)
{
	if(qtd_f[u] < qtd_f[v]) {
		boss[u] = v;
		qtd_f[v] += qtd_f[u];
	}

	else {
		boss[v] = u;
		qtd_f[u] += qtd_f[v];
	}
}

int main() {

    int n, m, u, v, w;

    while(scanf("%d %d", &n, &m) == 2) {
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            arestas[i] = aresta(u,v,w);
        }

        for(int i = 1; i <= n; ++i) {
            qtd_f[i] = 1;
            boss[i] = i;
        }

        sort(arestas.begin(), arestas.begin() + m, compare);

        int custo = 0;
        for(int i = 0; i < m; ++i) {
            u = BossFind(arestas[i].u);
            v = BossFind(arestas[i].v);

            if(u != v) {
                FUnion(u, v);
                custo += arestas[i].w;
            }
        }

        bool flag = false;
        for(int i = 1; i <= n; ++i) {
            if(qtd_f[i] == n) flag = true;
        }

        if(flag) printf("%d\n", custo);
        else printf("impossivel\n");

    }

    return 0;
}