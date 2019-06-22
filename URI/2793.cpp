#include <bits/stdc++.h>
using namespace std;

const long long MOD = (1e9) + 7;

int main() {

    string str;

    int ct = 0;
    cin >> str;
    
    int aux = 0;
    for(int i = 0; i < str.size()-1; ++i) {
        if(str[i] == 'F') aux += -1;
        else aux += 1;

        if(aux == 0) ct++;
    }

    long int ans = 1;
    for(int i = 0; i < ct; ++i) {
        ans = (ans << 1) % MOD;
    }

    cout << ans << '\n';
    

    return 0;
}