#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    else return gcd(b%a, a);
}

int main() {
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
}