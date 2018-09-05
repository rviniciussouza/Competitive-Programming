#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a;
    unsigned int b;

    while(1) {
        cin >> a >> b;
        if(!a && !b) break;
    
        int c = 0, ans = 0;
        while(a > 0 || b > 0) {
            int x = a % 10;
            int y = b % 10;
            a = a / 10; b = b / 10;
            c = (c + x + y) / 10;
            ans += c;
        }

        if(ans == 0) printf("No carry operation.\n");
        else if(ans > 1 ) printf("%d carry operations.\n", ans);
        else printf("1 carry operation.\n");
    }

    return 0;
}