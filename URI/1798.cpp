#include <bits/stdc++.h>
using namespace std;

#define max_n 1234
#define max_t 2123

int v[max_n], b[max_n];
long long memo[max_n][max_t];

long long solve(int i, int j){
    if(memo[i][j] != -1) return memo[i][j];
    if(i == 0) return memo[i][j] = 0;
    if(j == 0) return memo[i][j] = 0;
    if(v[i] > j) return memo[i][j] = solve(i-1, j);
    return memo[i][j] = max(max(b[i] + solve(i-1, j - v[i]), b[i] + solve(i, j - v[i])), solve(i-1, j));
}


int main(){

    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i <= n; ++i)
        scanf("%d %d", &v[i], &b[i]);

    memset(memo, -1, sizeof memo);
    printf("%lld\n", solve(n, k));

    return 0;
}