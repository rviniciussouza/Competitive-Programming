#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while(1) {
        scanf("%d", &n);
        if(!n) break;

        int fat[] = {0,1,2,6,24,120};

        int ans = 0;
        int r, c = 1;
        do {
            r = n % 10;
            n = n / 10;
            ans += (r * fat[c]); c++;
        }
        while(n != 0);

        printf("%d\n", ans);
    }

    return 0;
}