#include <bits/stdc++.h>
using namespace std;

const long long INF = 1234567912;
typedef pair<int, int> ii;

long long dp[11][5000];
ii A[12];
int k;

long long solve(int pos, int c) {
	
	if(c >= 1000 or A[pos].first > c) return INF;
	if(dp[pos][c] != -1) return dp[pos][c];
	if(A[pos].first == c) return dp[pos][c] = 1;
	
	dp[pos][c] = INF;
	for(int i = 0; i < k; ++i) {
		dp[pos][c] = min(dp[pos][c], 1 + solve(i, (c - A[pos].first) + A[pos].second));
	}
	
	return dp[pos][c];
}


int main() {

	while(true) {
	
		scanf("%d", &k);
		if(k == 0) break;
	
		memset(dp, -1LL, sizeof dp);
	
		for(int i = 0; i < k; ++i) {
			scanf("%d", &A[i].first);
		}
				
		for(int i = 0; i < k; ++i) {
			scanf("%d", &A[i].second);
		}
		
		
		sort(A, A + k);
		
		long long ans = INF;
		for(int i = 0; i < k; ++i) {
			ans = min(ans, solve(i, 100));
		}
		
		if(ans == INF) puts("cavaleiro morreu");
		else printf("%lld\n", ans);
		
	}

	return 0;
	
}
