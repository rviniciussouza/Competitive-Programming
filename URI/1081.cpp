#include <bits/stdc++.h>
using namespace std;

int V, E;
int G[21][21];
int vis[21], setado[21];

void dfsR(int u, int t) {
	vis[u] = -1;
	for(int i=0; i < V; ++i) {
		if(G[u][i] == 1) { 
			if(vis[i] == 0) {
				setado[u] = 1;			
				for(int j=0; j < t; ++j) printf(" ");
				printf("%d-%d pathR(G,%d)\n", u, i, i);
				dfsR(i, t+2);
			}

			else if(vis[i] == -1) {
				for(int j=0; j < t; ++j) printf(" ");
				printf("%d-%d\n", u, i);
			}
		} 
	}
	vis[u] = 1;
}

int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{

		scanf("%d %d", &V, &E);

		memset(G, 0, sizeof G);
		memset(vis, 0, sizeof vis);
		memset(setado, 0, sizeof setado);		

		for (int j = 0; j < E; ++j)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u][v] = 1;
		}

		printf("Caso %d:\n", i);
		
		for(int i=0; i < V; ++i) {
			if(vis[i] == 0 ) {
				dfsR(i, 2);
				if(setado[i])
					printf("\n");	
			}
		}

	}
	return 0;
}