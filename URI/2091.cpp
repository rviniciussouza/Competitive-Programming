#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    long long v;

    cin >> n;

    bitset<1000000000> number;
    long long S[n];

    for(int i = 0; i < n; ++i) {
        cin >> v;
        S[i] = v;
        number[v] ^ 1;
    }

    for(int i = 0; i < n; ++i) {
        if(number[S[i]]) {
            printf("%lld\n", S[i]);
            break;
        }
    }

    return 0;

}