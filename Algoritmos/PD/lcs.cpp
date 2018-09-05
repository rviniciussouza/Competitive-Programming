#include <bits/stdc++.h>
using namespace std;

#define max_n 1234

string x, y;
int memo[max_n][max_n];

int lcs_td(int i, int j) {
    if(i ==0 || j == 0) return memo[i][j] = 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(x[i] == y[j]) return memo[i][j] = 1 + lcs_td(i-1, j-1);
    return memo[i][j] = max(lcs_td(i-1, j), lcs_td(i, j-1));
}

int lcs_bttup(int n, int m) {
    for(int i=0; i < n; ++i) memo[0][i] = 0;
    for(int i=0; i < m; ++i) memo[i][0] = 0;

    for(int i=1; i <= n; ++i)
        for(int j=1; j <= m; ++j)
            if(x[i-1] == y[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
            else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);

    return memo[n][m];
}

int main() {
    cin>>x>>y;
   
    memset(memo, -1, sizeof memo);
    cout<<lcs_td(x.size(), y.size())<<endl;
    cout<<lcs_bttup(x.size(), y.size())<<endl;
    return 0;
}