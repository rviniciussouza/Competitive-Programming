#include <bits/stdc++.h>
using namespace std;

const int MN = 2010;

int lis[MN], lds[MN], v[MN];

int main() {

    int n, t;
    scanf("%d", &t);
    for(int k = 0; k < t; ++k) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }

        for(int i = 0; i < n; ++i) {
            lds[i] = 1;
            lis[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(v[i] > v[j]) {
                    lis[i] = max(lis[i], lis[j] + 1); 
                }

                if(v[i] < v[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }   

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans = max(ans, lis[i] + lds[i] - 1);
        }

        printf("%d\n", ans);

    }
    return 0;
}