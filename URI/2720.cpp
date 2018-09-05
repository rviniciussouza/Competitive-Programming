#include <bits/stdc++.h>
using namespace std;

#define max_n 100000
typedef long long ll;
typedef pair<ll, int> ii;

ii v[max_n];

bool compare(const ii& a, const ii& b) {
    if(a.second > b.second) return true;
    if(a.second == b.second) {
        if(a.first < b.first) return true;
        else return false;
    }
    return false;
}

int main(){

    int t, n, k, h, l, c;
    ll id;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &k);

        for(int i=0; i < n; ++i) {
            scanf("%lld %d %d %d", &id, &h, &l, &c);
            v[i] = ii(id, h*l*c);
        }

        sort(v, v+n, compare);
        sort(v, v+k);

        for(int i=0; i < k-1; ++i) {
            printf("%lld ", v[i].first);
        }
        printf("%lld\n", v[k-1].first);
        

    }

    return 0;
}