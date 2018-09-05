#include <bits/stdc++.h>

using namespace std;

#define MAX 10010


typedef pair<int, int> ii;
typedef long long ll;

vector<ii> G[MAX];
vector<int> imposto(MAX);

int V, P;
ll km = 0;

int dfsR(int p, int t, int w)
{
    int T = 0, k;
    for(auto v : G[t]){
        if(v.first == p)
            continue;
        T += dfsR(t, v.first, v.second);
    }
    T += imposto[t];
    
    if(T % P == 0) k = T / P;
    else k = (T / P) + 1;
    km += k * w;
    return T;
}

int main()
{
    int u, v, w;

    // ios_base :: sync_with_stdio(0); cin.tie(0);

    scanf("%d %d", &V, &P);
    for(int i=1; i<=V; i++)
        cin>>imposto[i];
    
    for(int i=1; i < V; i++) {
        scanf("%d %d %d", &u, &v, &w); w = w * 2;
        G[u].push_back(ii(v,w));
        G[v].push_back(ii(u,w));        
    }   

    dfsR(-1, 1, 0);

    printf("%lld\n",km);

    return 0;
}