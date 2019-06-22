#include <bits/stdc++.h>
using namespace std;

const int INF = 1016462;

vector<int> G[1400];
int dist[1400], vis[1400];
int A[12], B[12];
int k;

int solve() {
	
	for(int i = 0; i < 1400; ++i) {
		vis[i] = 0;
		dist[i] = INF;
	}
	
	queue<int> fila;
	fila.push(100);
	
	dist[100] = 0;
	vis[100] = 1;
		
	while(!fila.empty()) {
	
		int u = fila.front(); fila.pop();
		for(int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if(vis[v] == 0) {
				dist[v] = dist[u] + 1;
				vis[v] = 1;
				if(v == 0) break;
				fila.push(v);
			} 
		}
	}
	return dist[0];
}


int main() {

	while(true) {
	
		scanf("%d", &k);
		if(k == 0) break;
		
		for(int i = 0; i < 1400; ++i) G[i].clear();
		
		for(int i = 0; i < k; ++i) {
			scanf("%d", &A[i]);
		}
		
		for(int i = 0; i < k; ++i) {
			scanf("%d", &B[i]);
		}
		
		for(int i = 0; i < 1400; ++i) {
			for(int j = 0; j < k; ++j) {
				
				if(A[j] > i) continue;
				
				if(A[j] - i == 0) {
					G[i].push_back(0);
				}
				
				G[i].push_back((i - A[j]) + B[j]);
			}
		}
		
		int ans = solve();		
		if(ans == INF) puts("cavaleiro morreu");
		else printf("%d\n", ans);
		
	}

	return 0;
	
}
