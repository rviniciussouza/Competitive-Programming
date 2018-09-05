#include <bits/stdc++.h>
using namespace std;

#define max_n 10000
typedef pair<int, int> ii;

int is[max_n];

int busca_binaria(vector<ii>& v, int n, int key) {
    int x = 0, y = n - 1, z;
    while(x <= y) {
        z = (x + y) / 2;
        if(key == v[z].first) return z;
        if(key < v[z].first) y = z-1;
        else x = z + 1;
    }

    return -1;
}

int main() {

    int n, q, key, t, J, p, k;

    J = 0;
    while(scanf("%d %d", &n, &q) && n != 0 && q != 0) {
        vector<ii> v(n);
        vector<int> qtd(max_n, 0);

        for(int i=0; i < n; ++i) {
            scanf("%d", &p);
            v[i] = ii(p, ++qtd[p]);
        }

        sort(v.begin(), v.end());
        printf("CASE# %d:\n", ++J);
        for(int i=1; i <= q; ++i) {
            scanf("%d", &key);
            t = busca_binaria(v,n,key);
            if(t == -1) printf("%d not found\n", key);
            else{
                k = v[t].second - 1;
                printf("%d found at %d\n", key, (t-k)+1);
            }     
        }
    }

    return 0;
}