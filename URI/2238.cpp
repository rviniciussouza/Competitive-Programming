#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, k;

    cin >> a >> b >> c >> d;

    set<int> pp;

    for(int i=1; i <= sqrt(c); ++i) {
        if(c%i == 0) {
            k = c / i;
            if(i % a == 0 && i%b != 0 && d%i != 0) {
                pp.insert(i);
            }

            if(k % a == 0 && k%b != 0 && d%k != 0) {
                pp.insert(k);
            }            

        }
    }

    if(pp.size() == 0) printf("-1\n");
    else printf("%d\n", *pp.begin());

    return 0;
}