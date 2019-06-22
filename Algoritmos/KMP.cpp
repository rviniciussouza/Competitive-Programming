#include <bits/stdc++.h>
using namespace std;

const int MN = 1000010;

int b[MN];
string P;

void kmp() {
    b[0] = -1;
    int m = P.size();
    for(int i=0, j = -1; i < m;) {
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int main() {

    while(true) {
        cin >> P;
    
        if(P == ".") break;

        kmp();

        int ans = 0;

        for(int i = 1; i <= P.size(); ++i) {
            int cnt = 0;
            int j = b[i];
            while(j >= 0) {
                j = b[j];
                cnt++;
            } 

            ans = max(ans, cnt);
        }

        printf("%d\n", ans);
    
    }

    return 0;
}