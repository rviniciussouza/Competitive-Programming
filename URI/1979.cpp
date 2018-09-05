#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > G;

bool bipartido(int n) {

    vector<int> lado(n, -1);
    queue<int> q;

    lado[0] = 0;
    q.push(0);
    bool no = true;

    while(!q.empty() && no) {
        int u = q.front(); q.pop();
        
        for(int i=0; i < G[u].size(); ++i) {
            int v = G[u][i]; 
            if(lado[v] != -1 && lado[v] == lado[u]) {
                no = false;
                break;
            }

            else if(lado[v] == -1) {
                lado[v] = 1 - lado[u];
                q.push(v);
            }
        }
    }

    while(!q.empty()) q.pop();
    lado.clear();
    return no;
}



int main() {
    int n, u, v;
    stringstream ss;
    string amigos;

    while(1) {
        cin >> n;
        if(!n) break;

        G.assign(n, vector<int>());

        for(int i=0; i < n; ++i) {
            cin >> u; --u;
            cin.ignore();
            
            getline(cin, amigos);
            ss << amigos;
            while(ss >> v) {
                G[u].push_back(v-1);
            }

            ss.clear();
        }

        if(bipartido( n) ) cout << "SIM" << '\n';
        else cout << "NAO" << '\n';

        G.clear();
    }
    return 0;
}