#include <bits/stdc++.h>
using namespace std;

const int MN = 10010;
typedef pair<int, int> ii;
vector<ii> G[MN];
int ouro[MN];
int N, C, ans;

int dfs(int u, int pi) {
	
	int carga = ouro[u];
	for(int i = 0; i < G[u].size(); ++i) {
		ii v = G[u][i];
		if(v.first != pi) {
			int k = dfs(v.first, u);
			carga += k;
			if(k % C == 0) ans += (k/C) * v.second;
			else ans += (k/C + 1) * v.second;
		}
	}
	
	return carga; 
}


int main() {

	int u, v, w;

	scanf("%d %d", &N, &C);
	for(int i = 0; i < N; ++i) {
		scanf("%d", &ouro[i]);
	}
	
	for(int i = 0; i < N-1; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		G[u-1].push_back(ii(v-1,w));
		G[v-1].push_back(ii(u-1,w));
	}
	
	dfs(0, -1);
	
	printf("%d\n", ans * 2);
	
	return 0;
}
