// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {

    int n, p;
    string rota;

    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> p;
        cin >> rota;

        string ans;

        for(int j = 1; j <= 2 * p - 2; ++j) {
            if(rota[j-1] == 'S') ans.push_back('E');
            else ans.push_back('S');
        }

        cout << "Case #" << i << ": " << ans << '\n';

    }

    return 0;
}