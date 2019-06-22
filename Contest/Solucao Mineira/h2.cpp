#include <bits/stdc++.h>

#define maxn 302
#define mp make_pair

typedef long long ll;

using namespace std;

bool menor(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == -1) return 0;
    if (b.first == -1) return 1;
    return a.first * b.second <= a.second * b.first;
}

pair<ll, ll> mini(pair<ll, ll> a, pair<ll, ll> b) {
    return menor(a, b) ? a : b;
}

pair<ll, ll> soma(pair<ll, ll> a, pair<ll, ll> b) {
    return mp(a.first+b.first, a.second+b.second);
}

ll ans_n, ans_d;
pair<ll, ll> dist[maxn][maxn];

main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            dist[i][j] = mp(-1, 1);
            
    for (int i=0;i<m;i++) {
        int u, v;
        ll c, b;
        scanf("%d %d %lld %lld", &u, &v, &c, &b);
        
        dist[u][v] = mini(dist[u][v], mp(c, b));
        
        //~ printf("so far d[%d][%d] = <%lld, %lld>\n", u, v, c, b);
    }
    
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                if (dist[i][k].first == -1 || dist[k][j].first == -1) continue;
                dist[i][j] = mini(dist[i][j], soma(dist[i][k], dist[k][j]));
                //~ printf("so far d[%d][%d] = <%lld, %lld>\n", i, j, dist[i][j].first, dist[i][j].second);                
            }
        }
    }
    pair<ll, ll> ans = mp(-1, 1);
    for (int i=1;i<=n;i++)
        ans = mini(ans, dist[i][i]);
    
    //~ printf("%lld %lld\n", ans.first, ans.second);
    printf("%.6lf\n", double(ans.first) / ans.second);
}