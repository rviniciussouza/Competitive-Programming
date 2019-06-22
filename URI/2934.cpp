#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000 + 10

int dp[MAXN], dp_reverse[MAXN], data[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }

    dp[0] = 1;
    for(int i = 1; i < n; ++i) {
        int ans = 1;
        for(int j = 0; j < i; ++j) {
            if(data[i] == data[j] + 1) {
                ans = max(ans, 1 + dp[j]);
            }
        }
        dp[i] = ans;
    }

    dp_reverse[n-1] = 1;
    for(int i = n-2; i >= 0; --i) {
        int ans = 1;
        for(int j = n-1; j > i; --j) {
            if(data[i] + 1 == data[j]) {
                ans = max(ans, 1 + dp_reverse[j]);
            }
        }
        dp_reverse[i] = ans;
    }

    // int ans = 0;
    // for(int i = 0; i < n; ++i) {
    //     for(int j = i+1; j < n; ++j) {
    //         if(data[i] + 2 == data[j]) {
    //             ans = max(ans, dp[i] + dp_reverse[j] + 1);
    //             break;
    //         }
    //     }
    // }

    // for(int i = 0; i < n; ++i) {
    //     cout << dp[i] << ' ';
    // } cout << '\n';

    // for(int i = 0; i < n; ++i) {
    //     cout << dp_reverse[i] << ' ';
    // } cout << '\n';

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = max(ans, dp[i] + 1);
    }

    printf("%d\n", ans);

    return 0;
}