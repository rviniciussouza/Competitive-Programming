#include <bits/stdc++.h>
using namespace std;
#define MAX_n 2123

int dp[MAX_n];
int v[MAX_n];
int ans;

int lis_cres(int n) {

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

int lis_decr(int n) {

    memset(dp, 0, sizeof dp);
    for(int i=1; i <= n; ++i) {
        ans = 0;
        for(int j = 0; j < i; ++j)
            if(v[i] < v[j]) ans = max(dp[j], ans);
        dp[i] = ans + 1;
    }

    ans = 0;
    for(int i=1; i <= n; ++i) ans = max(ans, dp[i]);
    return ans; 
}

int main() {
    

    int n, t;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1; i <= n; ++i) scanf("%d", &v[i]);
        // cout<<max(lis_cres(n), lis_decr(n))<<endl;
        cout<<lis_decr(n);
    }

    return 0;
}