/*****************************
 * TAG: PD
 * Sum min elements
 * Problema classico: troco com o minimo de moedas (garantia que sempre tem solucao)
 * ***************************/

int max_sum(int n, int m, int v[])
{
    int dp[m];

    dp[0] = 0;

    for(int i=0; i <= m; ++i) {
        dp[i] = INT_MAX;
        for(int j=i; j < n; ++j)
            if( i - v[j] >= 0)
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
    }

    return dp[m];
}
