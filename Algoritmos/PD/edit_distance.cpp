#include <bits/stdc++.h>
using namespace std;

/* TOP-DOWN */
int editDistance(string a, string b, int i, int j) {
    if(i == 0) return j;
    if(j == 0) return i;
    
    if(a[i-1] == b[j-1]) return editDistance(a, b, i-1, j-1);
    else {
        return 1 + min(min(editDistance(a, b, i-1, j), editDistance(a, b, i, j-1)), editDistance(a, b, i-1, j-1));
    }
}

/* BOTTON - UP */

int editDistanceB(string a, string b, int m, int n) {
    int dp[m+1][n+1];

    for(int i=0; i <= m; ++i ) {
        for(int j= 0; j <=n; ++j) {

            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;

            else if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1];

            else {
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {

    string a, b;
    cin >> a >> b;

    printf("%d\n", editDistance(a, b, a.size(), b.size()));
    printf("%d\n", editDistanceB(a, b, a.size(), b.size()));    

    return 0;
}