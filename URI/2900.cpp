#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q;
    while(scanf("%d", &n) && n) {

        int x, k = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &q, &x);
            k += x / 2;
        }

        printf("%d\n", k/2);

    }
    puts("");
    return 0;
}