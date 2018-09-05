#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool compare(const ii& a, const ii& b) {
    return a.first > b.first;
}

int main() {

    int t, n, x, k;
    scanf("%d", &t);
    ii v[1010];

    while(t--) {
        scanf("%d", &n);

        for(int i=0; i < n; ++i) {
            scanf("%d", &x);
            v[i] = ii(x, i);
        }

        sort(v, v + n, compare);

        k = 0;
        for(int i=0; i < n; ++i) {
            if(v[i].second == i) k++;
        }            

        printf("%d\n", k);
    }

    return 0;
}