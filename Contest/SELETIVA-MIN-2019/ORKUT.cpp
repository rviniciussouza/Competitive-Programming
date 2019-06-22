#include <bits/stdc++.h>
using namespace std;

bool flag;
const int MN = 35;
string nomes[MN];
int vis[MN];
vector<int> ordem, G[MN];

void dfs(int u) {

    vis[u] = 0;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v] == 0) {
            flag = true;
        }
        
        else if(vis[v] == -1) {
            dfs(v);
        }
    }

    vis[u] = 1;
    ordem.push_back(u);
}

int getIdxNome(int n, string nome) {

    for(int i = 1; i <= n; ++i) {
        if(nome == nomes[i]) return i;
    }
}

int main() {

    int n, qtd, u, v, caso, k = 1;
    string nome;


    while(true) {

        if(k > 1) printf("\n");

        cin >> n;
        if(n == 0) break;    

        for(int i = 0; i < MN; ++i) {
            G[i].clear();
        }

        for(int i = 1; i <= n; ++i) {
            cin >> nome;
            nomes[i] = nome;
        }

        for(int i = 0; i < n; ++i) {
            cin >> nome >> qtd;

            u = getIdxNome(n, nome);

            if(qtd == 0) {
                G[0].push_back(u);
            }

            else {
                for(int j = 0; j < qtd; ++j) {
                    cin >> nome;
                    v = getIdxNome(n, nome);

                    G[v].push_back(u);
                }
            }
        }

        flag = false;

        memset(vis, -1, sizeof vis);
        dfs(0);

        reverse(ordem.begin(), ordem.end());
        

        printf("Teste %d\n", k++);

        if(flag == true or ordem.size() == 1 or ordem.size() <= n) {
            cout << "impossivel" << '\n';
        }

        else {
            cout << nomes[ordem[1]];            
            for(int i = 2; i <= ordem.size(); ++i) {
                cout << " " << nomes[ordem[i]];
            }
            printf("\n");
        }

        ordem.clear();
    }

    return 0;

}