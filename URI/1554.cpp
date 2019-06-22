#include <bits/stdc++.h>
using namespace std;


int main() {


    int c, n, bx, by, x, y, bola;

    cin >> c;
    while(c--) {
        cin >> n;
        cin >> bx >> by;
        
        long double menor_dist = 100000.9999;
        
        for(int i = 0; i < n; ++i) {
            cin >> x >> y;
            long double dist = sqrt(pow(max(bx, x) - min(bx, x), 2) + pow(max(by, y) - min(by, y), 2));
            if(dist < menor_dist) menor_dist = dist, bola = i + 1;
        }

        printf("%d\n", bola);
    }

    return 0;
}