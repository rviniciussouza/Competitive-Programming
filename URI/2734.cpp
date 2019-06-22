#include <bits/stdc++.h>
using namespace std;

int presentes[210];
bool vis[210][210][1010], dp[210][210][1010];

/* posicao, qtd de presentes pegos, valor formado */

bool solve(int pos, int n, int w) {
	
	if(n == 0) return w == 0;
	if(pos < 0 || w < 0) return false;
	if(vis[pos][n][w]) return dp[pos][n][w];
	vis[pos][n][w] = true;
	return dp[pos][n][w] = solve(pos - 1, n,  w) || solve(pos - 1, n - 1, w - presentes[pos]); 
}

int main() {

	int N, T, sum;
	scanf("%d", &T);
	for(int k = 0; k < T; ++k) {
		scanf("%d", &N);
		
		memset(vis, false, sizeof(vis));
		memset(dp, false, sizeof(dp));
		
		sum = 0;
		for(int i = 0; i < N; ++i) {
			scanf("%d", &presentes[i]);
			sum += presentes[i];
		}
		
		for(int i = N; i < 2*N; ++i) {
			scanf("%d", &presentes[i]);
			sum += presentes[i];
		}
		
		int ans = sum;
		for(int i = 0; i <= sum; ++i) {
			if(solve(N*2-2, N, i)) {
				ans = min(sum - i, ans);
			}
		}
		
		printf("%d", ans);
		printf("%d\n", (sum - ans) - ans);
		
	}

	return 0;
}
