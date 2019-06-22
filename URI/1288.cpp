#include <bits/stdc++.h>
using namespace std;

int poder[55];
int peso[55];
int dp[55][110];

int main() {


    int k, ct, r, n;

    cin >> ct;

    while(ct--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> poder[i] >> peso[i];
        }

        cin >> k;
        cin >> r;

        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n+1; ++i) {
            for(int j = 0; j < 110; ++j) {
                dp[i][j] = dp[i-1][j];
                if(peso[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j - peso[i]] + poder[i]);
                }
            }
        }

        // printf("%d\n",dp[n][k]);
        if(dp[n][k] >= r) printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");

    }

    return 0;
}