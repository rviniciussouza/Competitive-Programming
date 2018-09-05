#include <bits/stdc++.h>
using namespace std;
#define MAX_n 33000

int dp[MAX_n];
int sum[MAX_n];
int v[MAX_n];
int ans;

int lis_btup(int n) {

    memset(dp, 0, sizeof dp);
    for(int i=1; i <= n; ++i) {
        ans = 0;
        for(int j = 0; j < i; ++j)
            if(v[i] > v[j]) ans = max(dp[j], ans);
        dp[i] = ans + 1;
    }

    ans = 0;
    for(int i=1; i <= n; ++i) ans = max(ans, dp[i]);
    return ans; 
}

int main() {
    
    int n;
    cin>>n;
    for(int i=1; i <= n; ++i) scanf("%d", &v[i]);
    cout<<lis_btup(n)<<endl;
    return 0;
}