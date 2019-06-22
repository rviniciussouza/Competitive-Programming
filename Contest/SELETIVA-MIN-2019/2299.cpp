#include <vector>
#include <iostream>
#include <utility>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<long long> vi;

const long long MN = 1010;
const long long INF = 10000000001110;

long long memo[55][MN];
int a[55], b[55];
int m;

int knapsack(int i, int k) {
    if(memo[i][k] != -1) return memo[i][k];
    if(i == m) memo[i][k] = 0;
    else if(k == 0) memo[i][k] = 0;
    else if(b[i] > k) memo[i][k] = knapsack(i+1, k);
    else memo[i][k] = max(knapsack(i+1, k), a[i] + knapsack(i+1, k - b[i]));

    return memo[i][k];
}

int main() {

    int n, u, v, k = 0;

    while(true) {

        cin >> n >> m;
        if(n == 0) break;
        k++;

        for(int i = 0; i < m; ++i) {
            cin >> u >> v;
            b[i] = u;
            a[i] = v;
        }

        memset(memo, -1, sizeof memo);

        int ans = 0;
        for(int i = 0; i < m; ++i) {
            ans = max(ans, knapsack(i, n));
        }

        printf("Teste %d\n", k);
        printf("%d\n\n", ans);

    }    


    return 0;
}