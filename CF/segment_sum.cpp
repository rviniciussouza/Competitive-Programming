#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353LL; 
typedef long long int lli;
typedef pair<lli, lli> ii; 

ii dp[20][1<<10][2];
int vis[20][1<<10][2];
lli pow10[20];
vector<int> number;

int K;

ii calc(int pos, int mask, int f) {

    if(pos == number.size()) {
        int bitset = __builtin_popcount(mask);
        // printf("BIT %d", bitset);
        if(bitset > 0 && bitset <= K) return ii(0,1);
        else return ii(0LL,0LL);
    }

    if(vis[pos][mask][f] != -1) return dp[pos][mask][f];
    vis[pos][mask][f] = 1;

    int LIM = number[pos];
    if(f) LIM = 9;

    ii ans = ii(0LL,0LL);

    for(int i = 0; i <= LIM; ++i) {

        int nmask = mask;
        if( i> 0 || mask > 0) nmask = (nmask|(1<<i));
        ii result = calc(pos+1, nmask, f || (i < LIM));
        ans.first += result.first;
        ans.first += (((i * pow10[pos])%MOD) * ((result.second)%MOD))%MOD;
        ans.first %= MOD;
        ans.second += result.second;
        ans.second %=MOD;
    }

    return dp[pos][mask][f] = ans;

}

lli solve(lli a) {

    number.clear();
    while(a > 0) {
        number.push_back(a%10);
        a = a/10;
    }

    reverse(number.begin(), number.end());
    memset(vis, -1, sizeof vis);

    pow10[number.size()-1] = 1LL;
    for(int i = number.size()-2; i >= 0; i--) {
        pow10[i] = (pow10[i+1] * 10)%MOD;
    }

    return calc(0,0,0).first;
    // return 0;

}

int main() {

    lli A, B;
    cin >> A >> B >> K;
    // lli ansB = solve(B);
    // lli ansA = solve(A-1) << '\n';

    lli ans = (solve(B) - solve(A-1));
    // cout << B << '\n';
    
    ans %= MOD; ans += MOD; ans%=MOD;
    cout << ans << '\n';
    // cout << ansB - ansA << '\n';
    // cout << ans << '\n';

}