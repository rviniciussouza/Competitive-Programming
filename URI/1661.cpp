#include <bits/stdc++.h>
using namespace std;

#define max_n 100000

long long v[max_n];

int main(){

    int n;

    while(1) {
        scanf("%d", &n);

        if(n == 0) break;

        for(int i=0; i < n; ++i) {
            scanf("%lld", &v[i]);
        }

        long long ans = 0, custo = 0;
        
        ans = v[0];
        for(int i=1; i < n; ++i) {
            custo += fabs(ans);            
            ans = ans + v[i];          
        }

        printf("%lld\n", custo);
    }

    return 0;
}