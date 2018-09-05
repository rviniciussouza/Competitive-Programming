#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a;

    while(1) {
        cin >> a;
        if(!a) break;

        double x = a/90.0;

        int bra = floor(x);
        int ale = ceil(7 * x);

        printf("Brasil %d x Alemanha %d\n", bra, ale);
 
    }
    return 0;
}