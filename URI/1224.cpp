#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10010
//Recorrencia: memo[i][j] = max(v[i] + min(solve(i+2, j), solve(i+1, j-1)),
//                              v[j] + min(solve(i, j-2), solve(i+1, j-1)));

long long v[MAX_N];
long long memo[MAX_N][2];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0; i < n; ++i) scanf("%lld", &v[i]);

        for(int i=0; i < n-1; ++i)
            memo[i][0] = max(v[i], v[i+1]);
        
        int sp = 0, st = 1;

        for(int k=4; k <= n; k+=2) {
            for(int i=0, j = k-1; j < n; ++i, ++j)
                memo[i][st] = max(v[i] + min(memo[i+1][sp], memo[i+2][sp]), v[j] + min(memo[i][sp], memo[i+1][sp]));

            sp = st;
            st = (sp+1) % 2;
        }

        printf("%lld\n", memo[0][sp]);

    }

    return 0;
}