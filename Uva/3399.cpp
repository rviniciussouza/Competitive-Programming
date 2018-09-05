#include <bits/stdc++.h>
using namespace std;

#define MAX 10010
vector<bool> p(MAX, true);
vector<int> primo;
int valor;


void sieve() {
    for(int i=2; i*i < MAX; ++i)
        if(p[i])
            for(int j=i*2; j < MAX; j += i)
                p[j] = false;

    for(int i=2; i < MAX; ++i)
        if(p[i]) primo.push_back(i);
}

int solve(int idx, int n) {
    if(primo[idx] > n) return 0;
    if(primo[idx] == n) return 1;
    return solve(idx+1, n - primo[idx]);
    return 0;
}


int main() {

    sieve();

    while(1) {
        scanf("%d", &valor);
        if(valor == 0) break;

        int ans = 0;
        for(int i=0; i < primo.size(); ++i) 
                ans += solve(i, valor);

        printf("%d\n", ans);
    }

    return 0;
}