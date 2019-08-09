#include <bits/stdc++.h>
using namespace std;

const int MN = 1123;
int h[MN], L[MN], R[MN];

int main() {


    int N;

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &h[i]);
    for(int i = 0; i < N; ++i) {
        L[i] =  R[i] = 1;
    }

    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < i; ++j) {
            if(h[i] > h[j]) {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }

    for(int i = N-1; i >= 0; --i) {
        for(int j = N-1; j > i; --j) {
            if(h[i] > h[j]) {
                R[i] = max(R[i], R[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; ++i) {
        ans = max(ans, R[i] + L[i]);
    }   

    printf("%d\n", ans);

    return 0;
}