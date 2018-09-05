#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
bool primo[MAXN];

void sieve() {
    for(int i = 2; i <= MAXN; ++i) primo[i] = true;    

    int root = sqrt(MAXN);
    for(int i = 2; i <= root; ++i) {
        if(primo[i] == true)
            for(int j = 2; j * i <= MAXN; j++)
                primo[i * j] = false;
    }
}

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;

    if(n%2 == 0 or n%3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n%i == 0 or n%(i + 2) == 0) return false;
    } 

    return true;
}

void solve(int n) {
    int ans = -1;
    for(int i = 2; i < n; ++i)
        if(primo[i] && primo[n-i]) {
                ans = i;
                break;
        }

    if(ans == -1) printf("Goldbach's conjecture is wrong.\n");
    else printf("%d = %d + %d\n", n, ans, n - ans);
}

int main() {

    int n;

    sieve();

    while(1) {
        cin >> n;
        if(n == 0) break;

        solve(n);
    }

    return 0;
}