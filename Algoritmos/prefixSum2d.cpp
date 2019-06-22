#include <bits/stdc++.h>
using namespace std;

int v[100][100];
int p[101][101];

int getSum(int x, int y, int a, int b) {
    return p[a][b] - p[a][y-1] - p[x-1][b] + p[x-1][y-1];
}

void prefixSum(int n, int m) {
    for(int i=1; i <= n; ++i) {
        for(int j=1; j <=m; ++j) {
            p[i][j] = p[i-1][j] + v[i-1][j-1];
        }
    }

    for(int i=1; i <= n; ++i) {
        for(int j=1; j <=m; ++j) {
            p[i][j] += p[i][j-1];
        }
    }
}

int main() {
    
    int n, m, c1, r1, c2, r2;
    scanf("%d %d", &n, &m);


    for(int i=0; i < n; ++i) {
        for(int j=0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }

    prefixSum(n, m);

    int q; //queries
    scanf("%d", &q);

    for(int i=1; i <= q; ++i) {
        scanf("%d %d %d %d", &c1, &r1, &c2, &r2);
        int sum = getSum(c1, r1, c2, r2);
        printf("%d\n", sum);
    }
    

    return 0;
}