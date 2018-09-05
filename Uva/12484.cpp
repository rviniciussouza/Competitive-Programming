#include <bits/stdc++.h>
using namespace std;

#define MAX 10010

int v[MAX];

long long solve (int esq, int dir) {
    if(esq <= dir) {
        return max(solve(esq+1, dir), solve(esq, dir-1)) + min(max(solve(esq+1, dir), solve(esq, dir-1)));
    }

    return LONG_MAX;
}

int main() {

    int n;

    while(scanf("%d", &n) == 1) {
        for(int i=0; i < n; ++i) {
            scanf("%d", &v[i]);
        }
        
        printf("%lld\n", max(solve(0, n-1), solve());
    }

    return 0;
}