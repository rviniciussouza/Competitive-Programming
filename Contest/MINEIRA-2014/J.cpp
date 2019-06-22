#include <bits/stdc++.h>
using namespace std;

int main() {

    string P;
    while(cin >> P) {

        int n = P.size(), ans = 0;

        string S = P;
        for(int i = 0, j = n-1; i < n; j--, i++) {
            S[i] = P[j];
        }

        bool flag;
        for(int i = n - 1; i >= 0; --i) {
            flag = true;
            for(int j = 0, k = i; j <= k; ++j, --k) {
                if(S[j] != S[k]) {
                    flag = false; break;
                }
            }
            if(flag) {
                ans = i; break;
            } 
        }

        cout << n - 1 - ans << '\n';
    }

    return 0;
}