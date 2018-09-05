#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define swap(x, y)((x)^=(y)^=(x)^=(y))

int n;

int rsq(vector<vector<int> >& bit, int i, int j) { // returns RSQ((1,1), (i,j))
	int sum = 0, k = j;
	
	for(; i > 0; i -= (i & -i)) {
		j = k;
		for(; j > 0; j -= (j & -j))
			sum += bit[i][j];
	}

	return sum;
}

void update(vector<vector<int> >& bit, int i, int j, int v) {
	int k = j;
	for(; i <= n; i += (i&-i)) {
		for(j = k; j <= n; j += (j&-j))
			bit[i][j] += v;
	}
}

int getSum(vector<vector<int> >& bit, int c1, int r1, int c2, int r2) {
	return rsq(bit, c2, r2) - rsq(bit, c1-1, r2) - rsq(bit, c2, r1-1) + rsq(bit, c1-1, r1-1);
}

int main() {

    int m, v, x, y, z, w;

    while(scanf("%d %d", &n, &m) != EOF) {
        
        vector<vector<int> > bit(n+1, vector<int>(n+1,0));
        
        for(int i=1; i <= n; ++i) {
            for(int j=1; j <= n; ++j) {
                scanf("%d", &v);
                if(v == 1) update(bit, i, j, v);
            } 
        }

        for(int i=0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            update(bit, x, y, 1);

            scanf("%d %d %d %d", &x, &y, &z, &w);
            printf("%d\n", getSum(bit, x,y,z,w));
        }
    }

    return 0;
}
