#include <bits/stdc++.h>
using namespace std;

#define INF 1000010

int main() {

    int n;

    cin >> n;

    int v[n+1];

    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    long ans = INF, custo;
    for(int i = 1; i <= 6; ++i) {
        custo = 0;
        for(int j = 0; j < n; ++j) {
            if(v[j] != i)
                custo += v[j] + i == 7 ? 2 : 1;
        }
        ans = min(ans, custo);
    }

    printf("%ld\n", ans);

    return 0;

}