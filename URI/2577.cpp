#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
typedef pair<LL , LL > ii;
const LL MN = 122345;


vector<LL> G[MN];
LL componente[MN], vis[MN], caixa[MN];
LL pontos[MN], soma_componente[MN], soma_sub[MN];
bool vertice_de_corte[MN];

ii dfs(LL u, LL ant, LL timer, LL idcomp, LL ini) {

    LL menor_ancestral = vis[u] = timer++;
    componente[u] = idcomp;

    LL sum = caixa[u], qtd_filhos = 0LL;

    for(unsigned long long i = 0LL; i < G[u].size(); ++i) {
        LL v = G[u][i];
        if(vis[v] == 0LL) {
            qtd_filhos++;

            ii result = dfs(v, u, timer++, idcomp, ini);
            menor_ancestral = min(menor_ancestral, result.first);
            pontos[u] += result.second > 0LL ? result.second : 0LL;
            
            sum += result.second;

            if(vis[u] <= result.first && (u != ini || qtd_filhos >= 2LL)) {
                vertice_de_corte[u] = true;
            } 
        }

        else{
            menor_ancestral = min(menor_ancestral, vis[v]);
        }
    }   

    soma_sub[u] = sum;

    return ii(menor_ancestral, sum);
}

int main() {


    LL n, m, u, v;

    scanf("%lld %lld", &n, &m);

    for(LL i = 1; i <= n; ++i) {
        scanf("%lld", &caixa[i]);
    }

    for(LL i = 1; i <= m; ++i) {
        scanf("%lld %lld", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    memset(vis, 0LL, sizeof vis);
    memset(vertice_de_corte, false, sizeof vertice_de_corte);
    memset(soma_componente, 0LL, sizeof soma_componente);
    
    LL idcomp = 0LL, timer = 1;
    LL sum_total = 0LL;

    for(LL i = 1; i <= n; ++i) {
        if(vis[i] == 0LL) {
            ii result = dfs(i, -1, timer, idcomp, i);            
            soma_componente[idcomp++] = result.second;
            sum_total += result.second > 0LL ? result.second : 0LL;
        }
    }

    for(LL i = 1; i <= n; ++i) {
        
        LL ans;
        
        if(i > 1) printf(" ");

        if(vertice_de_corte[i]) {
        
            LL t = soma_componente[componente[i]] - soma_sub[i];

            if(soma_componente[componente[i]] > 0LL) {
        
                ans = t > 0LL ? t : 0LL;
                ans += pontos[i];
                ans = sum_total - soma_componente[componente[i]] + ans;
            }

            else {
                ans = sum_total;
                ans += t > 0LL ? t : 0LL;
                ans += pontos[i] > 0LL ? pontos[i] : 0LL;
            }
        }

        else {

            LL t = soma_componente[componente[i]];
            if(t > 0LL) {

                if(t - caixa[i] > 0LL) ans = sum_total - caixa[i];
                else ans = sum_total - t;
            }

            else {
                if(t - caixa[i] > 0LL) ans = sum_total + (t - caixa[i]);
                else ans = sum_total;
            }

        }
        printf("%lld", ans <= 0LL ? 0LL : ans);
    }printf("\n");

    return 0LL;
}