#include <bits/stdc++.h>
using namespace std;

vector<int> primos;

void crivo() {

    bool primo[600];
    memset(primo, true, sizeof primo);
    for(int i = 2; primos.size() <= 100; ++i) {
        if(primo[i]) {
            primos.push_back(i);
            for(int j = i + i; j < 600; j += i) {
                primo[j] = false;
            }
        }
    }
}

long long solve(long long N, long long K) {

    if(K == 0) return -1;
    if(N == 1) return 2;
    long long min = INF;
    for(int e = 0; e <= N; ++e) {
        if(N % (e + 1) == 0) {
            long long x = solve(K-1, N / (e+1)) * pow(primos[K-1], e);
            if(x > 0) {
                if(min > x) min = x;
            }
        }
    }
    return min;

}


int main() {

    int N, C;

    cin >> C;

    while(C--) {

        cin >> N;
        cout << solve(N, 100) << '\n';
    }


    return 0;

}