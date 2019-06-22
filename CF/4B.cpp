#include <bits/stdc++.h>
using namespace std;

int a[35], b[35];

int main() {

    int n, s;

    scanf("%d %d", &n, &s);

    int x = 0, y = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        x += a[i];
        y += b[i];
    }

    if(s < x || s > y) puts("NO");
    else {
        puts("YES");
        for(int i = 0; i < n; ++i) {
            while(x < s && a[i] < b[i]) {
                ++x; ++a[i];
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}