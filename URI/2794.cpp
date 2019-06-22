#include <bits/stdc++.h>
using namespace std;

#define INF 1000000010

int main() {
    
    long long n, u, v;

    vector<pair<long long, long long> > montes;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> u >> v;
        montes.push_back(make_pair(u,v));
    }

    sort(montes.begin(), montes.end());

    bool flag = false;

    long long aux = INF; 
    for(int i = 0; i < n - 1; ++i) {
        if(montes[i].second < montes[i+1].second) flag = true;
    }

    if(flag) puts("N");
    else puts("S");

    
    return 0;

}