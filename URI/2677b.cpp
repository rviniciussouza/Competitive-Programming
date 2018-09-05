#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1010
//Recorrencia: memo[i][j] = max(v[i] + min(solve(i+2, j), solve(i+1, j-1)),
//                              v[j] + min(solve(i, j-2), solve(i+1, j-1)));

int v[MAX_N];
int memo[MAX_N][2];

int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;
    while(scanf("%d", &n) && n != 0) {

        n = 2*n;

        for(int i=0; i < n; ++i) scanf("%d", &v[i]);

        for(int i=0; i < n-1; ++i)
            memo[i][0] = max(!(v[i]%2), !(v[i+1]%2));
        
        int sp = 0, st = 1;

        for(int k=4; k <= n; k+=2) {
            for(int i=0, j = k-1; j < n; ++i, ++j)
                memo[i][st] = max(!(v[i]%2) + min(memo[i+1][sp], memo[i+2][sp]), !(v[j]%2) + min(memo[i][sp], memo[i+1][sp]));

            sp = st;
            st = (sp+1) % 2;
        }

        printf("%d\n", memo[0][sp]);

    }

    return 0;
}