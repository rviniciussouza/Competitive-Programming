#include <bits/stdc++.h>

using namespace std;
int c[10];
main () {
    int n;
    scanf("%d", &n);
    
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d", &a);
        
        for (int j=1;j<=6;j++) {
            if (j == a) continue;
            else if (j + a == 7) c[j] += 2;
            else c[j]++;
        }
    }
    int ans = c[1];
    for (int i=1;i<=6;i++)
        ans = min(ans, c[i]);
    printf("%d\n", ans);
}