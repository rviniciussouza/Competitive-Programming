#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define swap(x, y)((x)^=(y)^=(x)^=(y))

int n, m;

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
		for(j = k; j <= m; j += (j&-j))
			bit[i][j] += v;
	}
}

int getSum(vector<vector<int> >& bit, int c1, int r1, int c2, int r2) {
	return rsq(bit, c2, r2) - rsq(bit, c1-1, r2) - rsq(bit, c2, r1-1) + rsq(bit, c1-1, r1-1);
}

int main() {

    int v, x, y, z, w, q, k;

    while(scanf("%d %d", &n, &m) != EOF) {
        
        vector<vector<int> > bit(n+1, vector<int>(m+1,0));
        
        for(int i=1; i <= n; ++i) {
            for(int j=1; j <= m; ++j) {
                scanf("%d", &v);
                if(v == 1) update(bit, i, j, v);
            } 
        }

        scanf("%d", &q);

        for(int i=0; i < q; ++i) {

            scanf("%d %d %d %d %d", &k, &x, &y, &z, &w);
            
            if(k == 0) {
                update(bit, x, y, -1);
                update(bit, z, w,  1);
            }

            else {
                printf("%d\n", getSum(bit, x,y,z,w));            
            }
        }
    }

    return 0;
}
