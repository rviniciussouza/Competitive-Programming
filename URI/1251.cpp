#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int compare(const void *a, const void *b) {
    ii x = *(ii*)a;
    ii y = *(ii*)b;

    if(x.second > y.second) return 1;
    if(x.second == y.second) return 1;
    return -1;
}

int main() {

    string str;
    bool k = false;
    while(cin>>str) {

        if(k) cout << '\n';
        k = true;

        ii frequencia[100];
        for(int i=0; i < 100; ++i) frequencia[i] = ii(32 + i, 0);        
        for(int i=0; i < str.size(); ++i) frequencia[str[i]-32].second++;
        qsort(frequencia, 100, sizeof(ii), compare);
        for(int i=0; i < 100; ++i)
            if(frequencia[i].second > 0)
                cout << frequencia[i].first << " " << frequencia[i].second << '\n';       
    }

    return 0;
}