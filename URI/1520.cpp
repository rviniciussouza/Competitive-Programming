#include <bits/stdc++.h>
using namespace std;

int v[10010];

int main() {
    int n, x, y, k;

    while(cin >> n) {
        int ans = 0;
        for(int i=0; i < n; ++i) {
            cin >> x >> y;
            for(int j = x; j <= y; ++j) v[ans++] = j;
        }

        sort(v, v+ans);

        cin >> k;

        int a = lower_bound(v, v + ans, k)-v;
        int b = upper_bound(v, v + ans, k)-v;
        
        if(a < b) printf("%d found from %d to %d\n", k, a, b-1);
        else printf("%d not found\n", k);
    }

    return 0;
}