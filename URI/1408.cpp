#include <bits/stdc++.h>
using namespace std;

const int MN = 100010;
const long long INF = 1231234550;
long long v[MN];
int dp[MN], N, M;

bool solve(long long k) {

    long long ans = 0;
    for(long long i = 0, j = 0, cnt = 0; i < M; ++i) {
        while(j < M-1 && cnt + v[j+1] - v[j] - 1 <= k) {
            cnt += v[j+1] - v[j] - 1;
            j++;
        }

        ans = max(ans, v[j] - v[i] + 1);
        if(i > 0 && cnt > 0)
            cnt -= v[i] - v[i-1] - 1;
        if(j <= i) j = i+1;
    }

    return ans >= N;

}

int main() {

    int x, ans, d;

    while(scanf("%d %d", &N, &M) && N != 0) {

        for(int i = 0; i < M; ++i) {
            scanf("%lld", &v[i]);
        }

        long long ini = 0, fim = N;
        long long res = INF;
        while(ini <= fim) {
            long long meio = (ini + fim) / 2;
            if(solve(meio)) {
                // printf("%d YES\n", meio);
                res = min(res, meio);
                fim = meio -1;
            }  else {
                // printf("%d NO\n", meio);
                ini = meio + 1;
            }
        }
        printf("%lld\n", res);

    }

    return 0;
}