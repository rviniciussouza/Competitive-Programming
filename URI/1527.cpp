#include <bits/stdc++.h>
using namespace std;

#define max_n 100100

vector<int> rankk(max_n);
vector<int> parent(max_n);
vector<long long> pontos(max_n);


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
        pontos[x] += pontos[y];
    }
    else {
        parent[x] = y;
        pontos[y] += pontos[x];        
        if(rankk[x] == rankk[y]) rankk[y]++;
    }
}

int main() {
    int n, m, a, b, q;

    while(1) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) return 0;

        for(int i=0; i < n; ++i ) {
            scanf("%lld", &pontos[i]);
            rankk[i] = 0;
            parent[i] = i;
        }

        int ans = 0;
        for(int i=0; i < m; ++i) {
            scanf("%d %d %d", &q, &a, &b); --a; --b;
            if(q == 1) {
                unionSet(a, b);
            }

            else {
                int x = find(a);
                int y = find(b);
                int z = find(0);

                if(pontos[x] > pontos[y] && z == x) ans++;
                else if(pontos[y] > pontos[x] && z == y) ans++;
            }
        }

        printf("%d\n", ans);
    }


    return 0;
}