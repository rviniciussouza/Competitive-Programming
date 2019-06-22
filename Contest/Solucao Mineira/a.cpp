#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

pair<int, int> v[5003];

main() {
    int n;
    scanf("%d", &n);
    
    for (int i=0;i<n;++i) {
        scanf("%d %d", &v[i].F, &v[i].S);
    }
    sort(v, v+n);
    
    bool ok = 1;
    for (int i=1;i<n;++i) 
        ok &= v[i].S <= v[i-1].S;
        
    printf("%s\n", ok ? "S" : "N");
}