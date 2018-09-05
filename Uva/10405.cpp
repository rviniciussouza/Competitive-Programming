#include <bits/stdc++.h>
using namespace std;
#define max_n 1002


int memo[max_n][max_n];

string x, y;

int (int n, int m) {
    for(int i=0; i <= n; ++i) memo[0][i] = 0;
    for(int i=0; i <= m; ++i) memo[i][0] = 0;

    for(int i=1; i <= n; ++i)
        for(int j=1; j <= m; ++j)
            if(x[i-1] == y[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
            else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);

    return memo[n][m];
}


int main() {

    while(getline(cin,x)) {
        getline(cin, y);
        std::cout<<lcs_bttup(x.size(), y.size())<<endl;
    }

    return 0;
}