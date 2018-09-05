#include <bits/stdc++.h>
using namespace std;

#define MAX_n 1010

int memo[MAX_n][MAX_n];
int v[MAX_n];

int solve(int i, int j) {
    if(memo[i][j] != -1) return memo[i][j];
    if(j == i+1){
        if(!(v[i]%2) || !(v[j]%2)) return memo[i][j] = 1;
        else return memo[i][j] = 0;
    }
    return memo[i][j] = max(!(v[i]%2) + min(solve(i+2, j), solve(i+1, j-1)),
                            !(v[j]%2) + min(solve(i, j-2), solve(i+1, j-1)));
}

int main(){

    int n;
    while(scanf("%d", &n) && n != 0) {
        for(int i=0; i < 2*n; ++i ) scanf("%d", &v[i]);

        memset(memo, -1, sizeof memo);
        cout<<solve(0, 2*n-1)<<endl;
    }

    return 0;
}