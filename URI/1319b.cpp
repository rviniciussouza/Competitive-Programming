#include <bits/stdc++.h>

using namespace std;

#define NMAX 1222
#define MOD 100000000
#define INF 1000111000

typedef long long int lli;
typedef pair < lli, lli > par;
typedef vector < vector < lli > > grafo;

vector < pair < lli, lli > > atividades;

lli N, M, x, y, T;

lli v[111][111];
lli dp[111][111];

lli f(lli ant, lli pos)
{
    if(pos > N) return 0;
    
    if(atividades[pos].second >= M) return 1;

    if(v[ant][pos] == T) return dp[ant][pos];
    
	v[ant][pos] = T;
    
    lli res = 0;
    
	for(lli i = pos + 1; atividades[i].first <= atividades[pos].second && i < N; i++)
    {
        if(atividades[i].first > atividades[ant].second && atividades[i].second > atividades[pos].second)
        {
            res = (res + f(pos, i)) % MOD;
        }
    }
    
    return dp[ant][pos] = res;
}

lli f1()
{
    lli res = 0;
    
    for(lli i = 1; atividades[i].first == 0 && i < N; i++)
    {
        res = (res + f(0, i)) % MOD;
    }
    
    return res;
}

int main()
{   
    
    while(scanf("%lld %lld", &M, &N) && M + N != 0)
    {
        T++;
        for(lli i = 0; i < N; i++)
        {
            scanf("%lld %lld", &x, &y);
            atividades.push_back(make_pair(x, y));
        }
        atividades.push_back(make_pair(-1, 0));
        N++;
        
        sort(atividades.begin(), atividades.end());
        
        printf("%lld\n", f1());
        
        atividades.clear();
    }
    
	return 0;
}