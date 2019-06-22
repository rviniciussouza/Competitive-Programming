#include <bits/stdc++.h>
using namespace std;

int n, k;
string S; 

int solve(char b) {

    int ans = 0;
    for(int i = 0, r = 0, count = 0; i < n; ++i) {
        while((S[r] != b || count < k) && r < n) {
            if(S[r] == b) count++;
            r++;
        }

        if(S[i] == b) count--;
        ans = max(ans, r - i);
    }
    return ans;
}

int main() {

    cin >> n >> k;
    cin >> S;
    cout << max(solve('b'), solve('a')) << '\n';

    return 0;
}