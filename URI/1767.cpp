#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int dp[55];
int kp[55];
int v[110];
int peso[110];
int n;

bool maximo(int a, int b) {
    return b > a;
}

void knapsack(int n, int C)
{
    int i, j, maxT, maxK;
    dp[0] = 0;
    for(int i=1; i <= C; ++i)
    {
        maxT = 0;
        maxK = 0;

        for(int j=0; j < n; ++j) {
            if(i - peso[j] >= 0) {
                if(maximo(maxT, v[j] + dp[i - peso[j]])) {
                    maxT = v[j] + dp[i - peso[j]];
                    maxK += peso[j];
                }
            }
        }   

        dp[i] = maxT;
        kp[i] = maxK;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i=0; i < n; ++i)
            scanf("%d %d", &v[i], &peso[i]);

        knapsack(n, 50);

        printf("%d brinquedos\n", dp[50]);
        printf("Peso: %d kg\n", kp[50]);
        // printf("sobra(m) %d pacote(s)\n", dp[C] - n
        
    }
    
    return 0;
}