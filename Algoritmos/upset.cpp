#include <bits/stdc++.h>
using namespace std;

const int MN = 12;
const int INF = 10101010;
int v[MN], p[MN], dp[MN][MN][1 << MN];
int N;

int f(int n, int m, int mask, int c) {
    if(mask == (1 << N)-1) return 0;
    if(dp[n][m][mask] != -1) return dp[n][m][mask];
    int ans = INF;
    for(int i = 0; i < N; ++i) {
        int k = mask & (1 << i);
        if(!k) {
            int custo = v[i] ^ v[n] ^ v[m];
            ans = min(ans, f(m, i, mask | (1 << i), c+1) + custo * p[N-c]);
        }
    }
    return dp[n][m][mask] = ans;
}


int main() {

    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; ++k) {
        scanf("%d", &N);

        for(int i = 0; i < N; ++i) {
            scanf("%d", &v[i]);
        }
        for(int i = 0; i < N; ++i) {
            scanf("%d", &p[i]);
        }

        if(N <= 2) {
            puts("0");
            continue;
        }
        memset(dp, -1, sizeof dp);
        int ans = INF;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int w = 0; w < N; ++w) {
                    if(i != j && j != w && i != w) {
                        int mask = (1 << i) | (1 << j) | (1 << w);
                        int custo = v[i] ^ v[j] ^ v[w];
                        ans = min(ans, f(j, w, mask, 2) + custo * p[N-1]);
                    }
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}