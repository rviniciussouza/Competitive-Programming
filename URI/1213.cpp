#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        int ans = 1, r = 1;
        while(r % n != 0) {
            r = (r * 10 + 1) % n;
            ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}