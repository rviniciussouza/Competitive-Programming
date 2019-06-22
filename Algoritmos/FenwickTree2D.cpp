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

int getSum(int xa, int ya, int xb, int yb) {
    if(xa > xb) swap(xa, xb);
    if(ya > yb) swap(ya, yb);
	return rsq(xb, yb) - rsq(xb, ya-1) - rsq(xa-1, yb) + rsq(xa-1, yb-1);
}

int main() {


    n = 4; m = 4;

    for(int i=0; i < MAXN; ++i)
	for(int j=0; j < MAXN; ++j) bit[i][j] = 0;
    
    // update(1, 1, 2);
    update(2, 2, 5);
    update(3, 3, 2);
    // update(2, 1, 9);

    // for(int i=0; i < 4; ++i) {
	// for(int j=0; j < 4; ++j) printf("%d\n",bit[i][j]);
        // printf("\n");
    // }

    // cout << getSum(1, 1, 1, 1) << '\n';
    // cout << getSum(0, 0, 2, 2) << '\n';
    cout << getSum(2, 2, 3, 3) << '\n';

    return 0;

}