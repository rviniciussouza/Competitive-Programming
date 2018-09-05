#include <bits/stdc++.h>
using namespace std;
#define MAXN 110

int BIT[MAXN][MAXN];
int n, m;

int getSum(int x, int y) {
    int sum = 0;
    for(; x > 0; x -= x & -x) {
        for(; y > 0; y -= y & -y) {
            sum += BIT[x][y];
        }
    }

    return sum;
}

void update(int x, int y, int v) {
    for(; x <= n; x += (x & -x)) {
        for(; y <= m; y += (y & -y))
            BIT[x][y] += v;
    }
}

int main() {
    scanf("%d %d", &n, &m);

    update(1,1,1);
    update(1,2,1);
    update(2,1,1);
    update(2,2,1);
    
    cout << getSum(1,1) << '\n';
    cout << getSum(1,2) << '\n';
    cout << getSum(2,1) << '\n';
    cout << getSum(2,2) << '\n';
    

    return 0;
}