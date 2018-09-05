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

int main(){
    while(cin>>x>>y) {
        memset(memo, -1, sizeof memo);
        cout<<lcs_td(x.size(), y.size())<<endl;
    }   

    return 0;
}