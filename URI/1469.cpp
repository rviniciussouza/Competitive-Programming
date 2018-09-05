#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N, M, P, i, u, v, aux, tmp;
    char O;

    stack<int> pilha;

    ios_base :: sync_with_stdio(0); cin.tie(0);

    while(cin>>N>>M>>P)
    {
        int idade[N];
        int set[N];
        int setPos[N];

        vector<vector<int> > G(N);

        //Lendo idades
        for (i = 0; i < N; ++i) {
            cin>>idade[i];
            set[i] = i;
            setPos[i] = i;
        }

        //Lendo arestas - invertidas
        for (i = 0; i < M; ++i) {
            cin>>u>>v;
            u--; v--;
            G[v].push_back(u);
        }

        for (i = 0; i < P; ++i) {
            cin>>O;

            if(O == 'T')
            {
                cin>>u>>v; u--; v--;
                
                aux = set[u];
                set[u] = set[v];
                set[v] = aux;

                setPos[set[u]] = u;
                setPos[set[v]] = v;
            }

            else
            {
                cin>>u; u--;
                vector<int> vis(N, false);

                int menor = INT_MAX;

                pilha.push(set[u]);
                while(!pilha.empty())
                {
                   aux = pilha.top();
                   pilha.pop();
                   vis[aux] = true;

                  
                   for(unsigned j = 0; j < G[aux].size(); j++) {
                        if(!vis[G[aux][j]]) {
                            if(idade[setPos[G[aux][j]]] < menor)
                                menor = idade[setPos[G[aux][j]]];
                            pilha.push(G[aux][j]);
                        }
                   }
                }

                if(menor == INT_MAX)
                    cout<<"*"<<endl;
                else
                    cout<<menor<<endl;
            }
        }
    }

    return 0;
}