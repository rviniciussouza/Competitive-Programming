  
#include <bits/stdc++.h>
using namespace std;

const long long MN = 2348;

long long v[MN][MN];
long long p[MN][MN];

int main() {
    
    long long n, g;
    scanf("%lld %lld", &n, &g);


    memset(p, 0, sizeof p);
    memset(v, 0, sizeof v);


    for(long long i=1; i <= n; ++i) {
        for(long long j=1; j <= n; ++j) {
            scanf("%lld", &v[i][j]);
        }
    }

    //Prefix Sum
    for(long long i=1; i <= n; ++i) {
        for(long long j=1; j <=n; ++j) {
            p[i][j] = p[i-1][j] + v[i][j];
        }
    }


    for(long long i=1; i <= n; ++i) {
        for(long long j=1; j <=n; ++j) {
            p[i][j] += p[i][j-1];
        }
    }

    long long ans;


    for(long long i = 1; i <= n; i = (i<<1)) {
        bool flag = false;
        //  printf("%lld\n", i);

        for(long long j = 1; !flag && j <= n - i + 1; j += i) {
                // printf("%lld\n", j);
            for(int k = 1; !flag && k <= n - i + 1; k += i) {
                long long sum = p[j + i - 1][k + i - 1] - p[j + i - 1][k-1] - p[j-1][k + i - 1] + p[j-1][k-1]; 
                if(sum < g) flag = true;
            }
        }

        if(!flag) {
            ans = i;
            break;
        }

    }


    // for(long long i = 1; i <= n; i = i * 2) {
    //     bool flag = false;
    //     for(long long j = 1; !flag && j <= n - i; j += n) {
    //         for(long long k = 1; !flag && k <= n - i; k += n) {
    //             long long sum = p[j + i - 1][k + i - 1] - p[j-1][k + i -1] - p[j + i - 1][k-1] + p[j-1][k-1];
    //             // printf("%d %d\n", i, sum);
    //             if(sum < g) {
    //                 flag = true;
    //             }
    //         }
    //     }

    //     if(!flag) {
    //         ans = i;
    //         break;
    //     }
    // }

    // printf("%lld\n", ans);

    long long sum = p[n][n] - p[0][n] - p[n][0] + p[0][0];
    // printf("%lld\n", sum);
    
    if(sum < g) {
        puts("0");
    }

    else if(sum == g) puts("1");

    else {
        long long d = n * n;
        long long e = ans * ans;
        // ans = (n * n) / (ans * ans);
        printf("%lld\n", d/e);
    }
    // long long q; //queries
    // scanf("%d", &q);

    // for(long long i=1; i <= q; ++i) {
    //     scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
    //     long long sum = p[c2+1][r2+1] - p[c1][r2+1] - p[c2+1][r1] + p[c1][r1];
    //     printf("%d\n", sum);
    // }
    

    return 0;
}