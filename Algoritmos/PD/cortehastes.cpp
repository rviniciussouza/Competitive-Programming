#include <bits/stdc++.h>
using namespace std;

int p[1100];
int dp[1100];
int bt;

//Solucao topdown
int topdown(int n) {
    
    if(n == 0) return dp[0] = 0;
    if(dp[n] != -1) return dp[n];
    bt = INT_MIN;
    for(int i=0; i < n; ++i) {
        bt = max(bt, p[i] + topdown(n-i-1));
    }
    dp[n] = bt;

    return dp[n] = bt;
}

//Solucao botton_up
int bttup(int n) {

    int dp[n+1];
    dp[0] = 0;

    for(int j=1; j <=n; ++j) {
        bt = INT_MIN;
        for(int i=0; i < j; ++i) {
            bt = max(bt, p[i] + dp[j-i-1]);
        }

        dp[j] = bt;
    }

    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i < n; ++i) {
        cin>>p[i];
    }

    memset(dp, -1, sizeof dp);
    cout<<topdown(n)<<endl;
    cout<<bttup(n)<<endl;
}