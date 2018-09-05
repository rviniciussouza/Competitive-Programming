#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define swap(x, y)((x)^=(y)^=(x)^=(y))

int bit[MAXN][MAXN];
int n, m;

int rsq(int i, int j) { // returns RSQ((1,1), (i,j))
	int sum = 0, k = j;
	
	for(; i > 0; i -= (i & -i)) {
		j = k;
		for(; j > 0; j -= (j & -j))
			sum += bit[i][j];
	}

	return sum;
}

void update(int i, int j, int v) {
	int k = j;
	for(; i <= n; i += (i&-i)) {
		for(j = k; j <= m; j += (j&-j))
			bit[i][j] += v;
	}
}

int getSum(int c1, int r1, int c2, int r2) {
    if(c1 > c2) swap(c1, c2);
    if(r1 > r2) swap(r1, r2);

	return rsq(c2+1, r2+1) - rsq(c1, r2+1) - rsq(c2+1, r1) + rsq(c1, r1);
}

int main() {

    int p, q, x, y, z, w, v;
    char op;

    while(1) {
    	scanf("%d %d %d", &n, &m, &p);
        // cin >> n >> m >> p;

        if(n == 0 && m == 0 && p == 0) return 0;

        for(int i=0; i < MAXN; ++i)
	    for(int j=0; j < MAXN; ++j) bit[i][j] = 0;
    
        scanf("%d", &q);
        // cin >> q;

        for(int i=0; i < q; ++i) {
            // cin.get();
            scanf(" %c", &op);
            // cin >> op;
            
            if(op == 'A') {
                scanf("%d %d %d", &v, &x, &y);
                // cin >> v >> x >> y;
                
                update(x+1, y+1, v);
            }

            else {
                scanf("%d %d %d %d", &x, &y, &z, &w);
                // cin >> x >> y >> z >> w;
                printf("%d\n", getSum(x,y,z,w) * p);
            }
        }

        printf("\n");
    }

    return 0;
}
