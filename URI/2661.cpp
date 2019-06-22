#include <bits/stdc++.h>
using namespace std;
define v 

vector<int> primos;

void getPrimos(long long N) {

    long long M = sqrt(N);

    vector<bool> p(M, false);
    for(int i = 2; i <= M; ++i) {
        if(!p[i]) {
            primos.push_back(i);
            for(int j = i + i; j <= M; j += i) {
                p[j] = true;
            }
        }
    }
}

bool fat(int N,g[v][v]) {

    printf("%lu\n", primos.size());
    for(int i = 0; i < primos.size(); ++i) {
        int rep = 0;
        while(!(N % primos[i])) rep++, N/= primos[i];
        if(rep>0) return false;
    }
    return true;
}

int main() {

    long long N, ans = 0;
    cin >> N;

    getPrimos(N);

    for(int i = 2; i * i <= N; ++i) {
        if(!(N%i)) {
            ans += fat(i);
        }
    }

    cout << ans << '\n';

    return 0;
}