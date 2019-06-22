#include <bits/stdc++.h>
using namespace std;

const int MN = 210;

int M[MN][MN], N, C;
bool vis[MN][MN];

int L[] = {0, -1, 0, 1};
int R[] = {1, 0, -1, 0};

int BFS(int x, int y, int cor) {

	queue<pair<int, int> > fila;
	vis[x][y] = true;
	fila.push(make_pair(x, y));
	int ans = 0;
	while(!fila.empty()) {

		pair<int, int> u = fila.front(); fila.pop();
		ans += 1;
		
		for(int i = 0; i < 4; ++i) {
			int v = u.first + L[i];
			int p = u.second + R[i];
			
			if(v < 1 or v > N) continue;
			if(p < 1 or p > C) continue;
			
			if(vis[v][p] == false && M[v][p] == cor) {
				vis[v][p] = true;
				fila.push(make_pair(v, p));
			}
		}
	}

	return ans;
}

int main( ) {
	
	scanf("%d %d", &N, &C);
	
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= C; ++j) {
			scanf("%d", &M[i][j]);
		}
	}
	
	memset(vis, false, sizeof vis);
	
	int ans = 112345;
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= C; ++j) {
			if(vis[i][j] == false) {
				ans = min(ans, BFS(i, j, M[i][j]));
			}
		}
	}
	
	printf("%d\n", ans);

	return 0;
}
