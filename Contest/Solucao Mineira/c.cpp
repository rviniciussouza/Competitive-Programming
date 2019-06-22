#include <bits/stdc++.h>

using namespace std;

main() {
    int v[5];
    scanf("%d %d %d %d", &v[0], &v[1], &v[2], &v[3]);
    
    for (int i=0;i<4;i++) if(v[i] == 1) printf("%d\n", i+1);
}