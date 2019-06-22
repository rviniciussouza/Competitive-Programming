#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 1010;
const int INF = 10000100;

vector<pair<int, int> > G[2 * MN];
int demanda[MN], reserva[MN];
int rGraph[2 * MN][2 * MN], graph[2 * MN][2 * MN];
int N, P, sum_demanda;
int visited[2 * MN];
int posto;

bool dfs(int u, int t, int e, int parent[]) {

    visited[u] = true;
    int i;
    if(u == ) i = posto;

    for(; i < G[u].size(); ++i) {
        int v = G[u][i].first;
        int w = G[u][i].second;
        if(visited[v] == false && rGraph[u][v] > 0 && w <= e) {
            parent[v] = u;
            if(v == t) return true;
            if(dfs(v, t, e, parent)) return true;
        }
    }

    if(u >= 1 and u <= P) posto++;
    return false;

}
 

bool dfs_B(int s, int t, int e, int parent[]) 
{ 
    
    memset(visited, 0, sizeof(visited));    
    visited[s] = true; 
    parent[s] = -1; 
    return dfs(s, t, e, parent);
}
  
  
bool solve(int s, int t, int e) 
{ 
    int u, v;  

    for (u = 1; u <= N; u++) 
        for (v = 1; v <= N; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[N+1]; 
  
    int max_flow = 0;  // There is no flow initially 
    posto = 0;

    while (dfs_B(s, t, e, parent)) 
    { 
        // printf("BFS");
        int path_flow = INF; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  

        for (v=t; v != s; v=parent[v]) 
        { 
        // printf("BFS");

            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
  
        max_flow += path_flow; 
    } 
  
    return max_flow == sum_demanda; 
}

int main() {

    int R, C, u, v, w, maior_custo = 0;

    scanf("%d %d %d", &P, &R, &C);

    int s = P + R + 1; //fonte
    int t = s + 1; //servdedouro
    N = t; // total de vertices 

    // memset(graph, 0, sizeof graph);

    sum_demanda = 0;
    for(int i = 1; i <= P; ++i) {
        scanf("%d", &demanda[i]);
        sum_demanda += demanda[i];
    }
    for(int i = 1; i <= R; ++i) scanf("%d", &reserva[i]);
    for(int i = 0; i < C; ++i) {
        scanf("%d %d %d", &u, &v, &w); v += P;
        maior_custo = max(maior_custo, w);
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
        graph[u][v] = demanda[u]; // posto par refinaria - posto
        graph[s][u] = demanda[u]; // fonte para posto - posto 
        graph[v][t] = reserva[v - P]; // refinaria para servedouro - refinaria
    }

    for(int i = 1; i <= P; ++i) {
        G[s].push_back(make_pair(i, 0));
        G[i].push_back(make_pair(s, 0));
    }

    for(int i = 1; i <= R; ++i) {
        G[i+P].push_back(make_pair(t, 0));
        G[t].push_back(make_pair(i+P, 0));
    }


    // printf("%d\n", solve(s, t, 4));


    int ini = 1, fim = maior_custo, ans = 0; 

    // if(solve(s, t, INF)) printf("aa");

    // printf("%d", maior_custo);

    while(ini <= fim) {
        int meio = (ini + fim) / 2;

        // printf("aquiiiiiii");

        if(solve(s, t, meio)) {


            ans = meio;
            fim = meio - 1;
        }
        else {

            ini = meio + 1;
        }
    }

    printf("%d\n", ans == 0 ? -1 : ans);

    return 0;
}