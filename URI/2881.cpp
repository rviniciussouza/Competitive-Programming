#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> ii;

// const int NM = 1123;
// const lli INF = 1123456789123;

#define INF 1222333444555
#define NM 1222

vector<pair<ii, ii> > shows;
lli pd[NM][NM], vis[NM][NM];
lli numShows, all_set;

lli f(lli pos, lli mask) {

    if(pos == numShows) return mask == all_set ? 0LL : -INF;
    if(vis[pos][mask] == 1) return pd[pos][mask];
    vis[pos][mask] = 1;

    lli prox_show = numShows;
    for(lli i = pos + 1; i < numShows; ++i) {
        if(shows[pos].first.second <= shows[i].first.first) {
            prox_show = i;
            break;
        }
    }

    lli op1 = f(pos+1, mask);
    lli op2 = f(prox_show, mask | (1 << shows[pos].second.second)) + shows[pos].second.first;
    return pd[pos][mask] = max(op1, op2);

}

int main(){

    lli n, m, ini, fim, t;

    scanf("%lld", &n);

    for(lli i = 0; i < n; ++i) {
        scanf("%lld", &m);
        for(lli j = 0; j < m; ++j) {
            scanf("%lld %lld %lld", &ini ,&fim, &t);
            shows.push_back(make_pair(make_pair(ini, fim), make_pair(t, i)));
        }
    }

    sort(shows.begin(), shows.end());

    numShows = shows.size();
    all_set = (1 << n) - 1;

    memset(vis, 0, sizeof vis);
    printf("%lld\n", f(0, 0) > 0 ? f(0,0) : -1);

    return 0;
}