#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vv;

vector<bool> visited(10010);
vector<int> parent(10010);

bool findCycle(vector<vv>& g, int root) {
    stack<int> ss;

    ss.push(root);
    while(!ss.empty()) {
        int u = ss.top(); ss.pop();
        visited[u] = true;

        for(auto& v : g[u]) {
            if(parent[u] == v) continue;
            if(visited[v]) return true;
            if(parent[v] == u) return true;
            parent[v] = u;
            ss.push(v);
        }
    }    
    return false;
}

int main() {
    int n, m, u, v;

    while(scanf("%d %d", &n, &m) == 2) {
        vector<vv> g(n);
        bool cycle = false;

        for(int i=0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            g[u-1].push_back(v-1);
            g[v-1].push_back(u-1);

            //auto-arco
            if(u == v) cycle = true;
        }

        for(int i=0; i < n; ++i) {
            parent[i] = i;
            visited[i] = false;
        }

        for(int i=0; i < n; ++i) {
            if(!visited[i])
            cycle |= findCycle(g, i);
        
            if(cycle) break;
        }

        if(cycle) printf("cycle found\n");
        else printf("cycle not found\n");

    } 

    return 0;
}