#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MN = 1010;
const int INF = 10000100;

int demanda[MN], reserva[MN];
int rGraph[2 * MN][2 * MN], graph[2 * MN][2 * MN], tempo[2 * MN][2 * MN];
int N, sum_demanda;

bool bfs(int s, int t, int e, int parent[]) 
{ 
    
    bool visited[N+1]; 
    memset(visited, 0, sizeof(visited)); 
   
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    while (!q.empty()) { 
        int u = q.front(); q.pop(); 
  
        // printf("euu");

        for (int i=1; i <= N; i++) 
        { 
            int v = i;

            if (visited[v] == false && rGraph[u][v] > 0 && tempo[u][v] <= e) 
            { 
                // printf("xamaaa");
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    return (visited[t] == true); 
} 
  
bool solve(int s, int t, int e) 
{ 
    int u, v;  

    for (u = 1; u <= N; u++) 
        for (v = 1; v <= N; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[N+1]; 
  
    int max_flow = 0;  // There is no flow initially 
  
    while (bfs(s, t, e, parent)) 
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

    int P, R, C, u, v, w, maior_custo = 0;

    scanf("%d %d %d", &P, &R, &C);

    int s = P + R + 1; //fonte
    int t = s + 1; //servdedouro
    N = t; // total de vertices 

    memset(graph, 0, sizeof graph);
    memset(tempo, 0, sizeof graph);

    sum_demanda = 0;
    for(int i = 1; i <= P; ++i) {
        scanf("%d", &demanda[i]);
        sum_demanda += demanda[i];
    }
    for(int i = 1; i <= R; ++i) scanf("%d", &reserva[i]);
    for(int i = 0; i < C; ++i) {
        scanf("%d %d %d", &u, &v, &w); v += P;
        maior_custo = max(maior_custo, w);
        
        tempo[v][u] = w;
        tempo[u][v] = 0;

        graph[v][u] = reserva[v - P];
        graph[u][t] = demanda[u]; // u-t posto para servedouto
        graph[s][v] = reserva[v - P]; // s-v source para refinaria
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