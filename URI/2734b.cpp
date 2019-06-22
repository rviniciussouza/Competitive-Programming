#include <bits/stdc++.h>
using namespace std;

const int INF = 112345;
int presentes[210];
int dp[210][210][1010];
int N, sum;
/* posicao, qtd de presentes pegos, valor formado */

int solve(int pos, int n, int w) {
	
	if(n == N) {
		if(w > sum/2) return sum - w;
		else return (sum - w) - w;
	}
	if(pos < 0 || n > N) return INF;
	if(dp[pos][n][w] != -1) return dp[pos][n][w];
	return dp[pos][n][w] = min(solve(pos-1, n, w), solve(pos-1, n+1, w + presentes[pos]));
}

int main() {

	int T;
	scanf("%d", &T);
	for(int k = 0; k < T; ++k) {
		scanf("%d", &N);
		
		//memset(vis, false, sizeof(vis));
		memset(dp, -1, sizeof(dp));
		
		sum = 0;
		for(int i = 0; i < N; ++i) {
			scanf("%d", &presentes[i]);
			sum += presentes[i];
		}
		
		for(int i = N; i < 2*N; ++i) {
			scanf("%d", &presentes[i]);
			sum += presentes[i];
		}
		
		printf("%d\n", solve(N*2-1,0,0));
	}

	return 0;
}
