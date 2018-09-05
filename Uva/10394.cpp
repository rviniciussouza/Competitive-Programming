#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20e6 + 10;
bool primo[MAXN];
int twin[MAXN];

void sieve() {
    for(int i = 2; i <= MAXN; ++i) primo[i] = true;    

    primo[0] = primo[1] = false;

    int root = sqrt(MAXN);
    for(int i = 2; i <= root; ++i) {
        if(primo[i] == true) {
            for(int j = 2; j * i <= MAXN; j++)
                primo[i * j] = false;
        }
    }
}

void solve() {
    for(int i = 3, j = 1; i < MAXN - 1; ++i)
        if(primo[i] && primo[i + 2]) twin[j++] = i;
}

int main() {

    int n;

    sieve();
    solve();

    while(cin >> n) {
        printf("(%d, %d)\n", twin[n], twin[n] + 2);
    }

    return 0;
}