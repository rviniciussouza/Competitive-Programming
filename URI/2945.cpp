#include <bits/stdc++.h>
using namespace std;

const int MN = 100100;
const int MX = 101;

vector<int> G[MN];
int notas[MN], grupo[MN], BIT[MN][MX];

void dfs(int u, int k) {
    grupo[u] = k;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (grupo[v] == -1)
            dfs(v, k);
    }
}

int getSum(int index, int gr) {
    int sum = 0;
    index = index + 1;
    while (index > 0) {
        sum += BIT[gr][index];
        index -= index & (-index);
    }
    return sum;
}

int query(int u, int gr) {
    return getSum(u, gr);
}

void updateBIT(int n, int gr, int index, int val) {
    index = index + 1;
    while (index <= n) {
        BIT[gr][index] += val;
        index += index & (-index);
    }
}

int main() {

    int N, M, Q, u, v, k, op;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &notas[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    memset(grupo, -1, sizeof grupo);
    for (int i = 1, k = 0; i <= N; ++i) {
        if (grupo[i] == -1) {
            dfs(i, k++);
        }
    }

    for(int i = 1; i <= N; ++i) {
        updateBIT(MX, grupo[i], notas[i], 1);
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d", &u);
            if(notas[u] == 0) puts("0");
            else printf("%d\n", query(notas[u] - 1, grupo[u]));
        } 
        else {
            scanf("%d %d", &u, &k);
            updateBIT(MX, grupo[u], notas[u], -1);
            notas[u] = k;
            updateBIT(MX, grupo[u], notas[u], 1);
        }
    }

    return 0;
}