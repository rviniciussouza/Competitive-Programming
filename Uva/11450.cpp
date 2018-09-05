#include <bits/stdc++.h>
using namespace std;

int p[25][25];
int dp[210][25];
int n, c;

int solve(int m, int v)
{
    if(m < 0) return INT_MIN;
    if(v == c) return n - m;
    if(dp[m][v] != -1) return dp[m][v];

    int max_value = INT_MIN;
    for(int i=1; i <= p[v][0]; ++i)
        max_value = max(max_value, solve(m - p[v][i], v+1)); 

    dp[m][v] = max_value;
    return dp[m][v];
}

int main()
{
    int t, k;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &c);

        for(int i=0; i < c; ++i) {
            scanf("%d", &k);
            p[i][0] = k;
            for(int j=1;  j <= k; ++j)
                scanf("%d", &p[i][j]);
        }

        memset(dp, -1, sizeof dp);
        int max_value = solve(n, 0);

        if(max_value < 0)
            printf("no solution\n");
        else printf("%d\n", max_value);

    }

    return 0;
}