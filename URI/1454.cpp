#include <bits/stdc++.h>

using namespace std;

#define INF (100*1000*1000)

int main(void)
{

	int V, E, u, v, w,x, y, p;
	int t = 1;
	while(1)
	{
		scanf("%d %d", &V, &E);
		if(V + E == 0)
			return 0;

		vector<vector<int> > D(V, vector<int>(V, INF));

		for (int i = 0; i < V; ++i)
			D[i][i] = 0;

		for (int i = 0; i < E; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			D[u][v] = w;	
			D[v][u] = w;	
		}

		for (int k = 0; k < V; ++k)
			for (int i = 0; i < V; ++i)
				for (int j = 0; j < V; ++j)
					D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));
					

		scanf("%d", &p);
		printf("Instancia %d\n", t++);

		for (int i = 0; i < p; ++i) {
			scanf("%d %d", &x, &y);
			x--; y--;
			if(x == y)
				printf("0\n");
			else printf("%d\n", D[x][y]);
		}
		printf("\n");

	}

	return 0;
}
