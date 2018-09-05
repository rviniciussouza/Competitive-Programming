#include <bits/stdc++.h>
using namespace std;

#define max_n 7500

int m[] = {50, 25, 10, 5, 1};
int memo[max_n][5];

int f(int valor, int index) {

    if(valor == 0) return 1;
    if(memo[valor][index] != -1) return memo[valor][index];

    int ans = 0;
    for(int i=index; i < 5; ++i) {
        if(valor >= m[i])
            ans += f(valor - m[i], i); 
    }

    return memo[valor][index] = ans;
}

int main() {
    int n;
    while (cin >> n) {

        memset(memo, -1, sizeof memo);
        cout << f(n, 0)<<endl;
    }
    return 0;
}