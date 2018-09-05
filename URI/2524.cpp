#include <bits/stdc++.h>
#define MAX_n 1010

long long v[MAX_n];
long long memo[MAX_n][MAX_n];
int n, m;
long long q;

long long solve(int i, int j) {
    if(memo[i][j] != -1) return memo[i][j];
    if(i == 0) return memo[i][j] = 0;
    if((v[i] + j) % n == 0) return memo[i][j] = 1 + solve(i-1, 0);
    memo[i][j] = std::max(q = solve(i-1, (v[i] + j)%n), solve(i-1, j));
    if(q) return memo[i][j] = std::max(memo[i][j], q + 1);
    else return memo[i][j];
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i=1; i <= m; ++i) scanf("%lld", &v[i]);
        std::memset(memo, -1, sizeof memo);
        printf("%lld\n", solve(m, 0));
    }

    return 0;
}