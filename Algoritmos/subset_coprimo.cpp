#include <bits/stdc++.h>
using namespace std;

const int MN = 55;

vector<int> primos, v;
int pd[MN][1 << 16];

void getPrimes() {
    vector<bool> p(MN, false);
    for(int i = 2; i <= MN; ++i)
        if(!p[i]) {
            primos.push_back(i);
            for(int j = i + i; j <= MN; j +=i)
                p[j] = true;
        }
}

int getDiv(int x) {

    int ans = 0;
    for(int i = 1; i <= primos.size(); ++i) {
        if(x % primos[i-1] == 0) ans |= (1 << i); 
    }
    return ans;
}

int f(int pos, int mask) {
    if(pos < 0) return 0;
    if(pd[pos][mask] != -1) return pd[pos][mask];
    int ans = 0;
    int res = mask & v[pos];
    if(!res) ans = 1 + f(pos-1, mask | v[pos]);
    ans = max(ans, f(pos-1, mask));
    return pd[pos][mask] = ans; 
}

int main() {

    int n, x, t, ans = 0;
    scanf("%d", &t);

    getPrimes();

    for(int k = 0; k < t; ++k) {
        scanf("%d", &n);
        ans = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%d", &x);
            if(x == 1) ans++;
            else {
                v.push_back(getDiv(x));
            }
        } 
        memset(pd, -1, sizeof pd);
        printf("%d\n", ans + f(v.size()-1, 0));
        v.clear();
    } 

    return 0;
}