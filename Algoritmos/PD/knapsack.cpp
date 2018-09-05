/*********************
 * TAG: PD
 * KNAPSACK
 * *******************
 * 
 * a[i] valor do iesimo elemento
 * b[i] peso do iesimo elemento 
 * N qtd de elementos
 * k capacidade atual
**/

//SEM REPETICAO
int knapsack(int i, int k) {
    if(memo[i][k] != -1) return memo[i][k];
    if(i == N) memo[i][k] = 0;
    else if(k == 0) memo[i][k] = 0;
    else if(b[i] > k) memo[i][k] = knapsack(i+1, k);
    else memo[i][k] = max(knapsack(i+1, k), a[i] + knapsack(i+1, k - b[i]));

    return memo[i][k];
}

//COM REPETICAO: n(numero de elementos), C (capacidade maxima)
int knapsack(int n, int C)
{
    int i, j, maxT;
    int dp[C+1];
    dp[0] = 0;
    for(int i=1; i <= C; ++i)
    {
        maxT = 0;
        for(int j=0; j < n; ++j)
            if(i - b[j] >= 0)
                maxT = max(maxT, a[j] + dp[i - b[j]]);    

        dp[i] = maxT;
    }

    return dp[C];
}