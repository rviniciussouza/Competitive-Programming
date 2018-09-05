#include <bits/stdc++.h>
using namespace std;

#define max_n 10010

vector<int> rankk(max_n);
vector<int> parent(max_n);
vector<int> nivel(max_n);
vector<int> v(max_n);
map<string, int> mapa;

int find(int i) {
    while(i != parent[i]) i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int x = find(i);
    int y = find(j);
    
    if(x == y) return; //isSameSet
    
    if(rankk[x] > rankk[y]) {
        parent[y] = x;
        nivel[x] = max(nivel[x], nivel[y]);
    }
    else {
        parent[x] = y;
        nivel[y] = max(nivel[y], nivel[x]);
        if(rankk[x] == rankk[y]) rankk[y]++;
    }
}

int main() {
    int n, m, q;
    char ssA[12], ssB[12];

    scanf("%d %d %d", &n, &m, &q);

    mapa.clear();

    for(int i=0; i < n; ++i) {
        scanf(" %s %d", ssA, &v[i]);
        mapa[ssA] = i;
        nivel[i] = v[i];
        rankk[i] = 0;
        parent[i] = i;
    }

    for(int i=0; i < m; ++i) {
        scanf(" %s %s", ssA, ssB);
        unionSet(mapa[ssA], mapa[ssB]);
    }

    for(int i=0; i < q; ++i) {
        scanf(" %s", ssA);
        int k = mapa[ssA];
        
        if(parent[k] == k && rankk[k] == 0) printf("S\n"); //nao ser um sensate
        else if(v[k] >= 5) printf("S\n"); //ser sensate e ter nivel maior igual a 5
        else if(nivel[find(k)] < 5) printf("S\n"); // set com todos sensate < 5
        else printf("N\n");
    }
    
    return 0;
}