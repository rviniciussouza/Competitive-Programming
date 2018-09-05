#include <bits/stdc++.h>
using namespace std;

int main() {
    string v;
    bool ans = true;

    cin >> v;

    int end = v.size();

    for(int i=0, j = end - 1;  i <= j; ++i) {
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
            while(!(v[j] == 'a' || v[j] == 'e' || v[j] == 'i' || v[j] == 'o' || v[j] == 'u') && i<=j) --j;
            if(v[i] != v[j]) ans = false;
            --j;
        }
    }

    if(ans) printf("S\n");
    else printf("N\n");

}