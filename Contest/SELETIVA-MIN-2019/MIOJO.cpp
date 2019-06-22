#include <bits/stdc++.h>
using namespace std;

const long long INF = 100000001110;

int f(int t, int a, int b) {
    for(int i = 1; i <= b; ++i) {
        if((a * i) % b == t) {
            return a * i;
        }
    }
}

int main() {

    int t, a, b;
    cin >> t >> a >> b;
    printf("%d\n", min(f(t, a, b), f(t, b, a)));

    return 0;

}