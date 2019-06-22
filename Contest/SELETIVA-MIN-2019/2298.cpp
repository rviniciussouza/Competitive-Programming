#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return b > a;
}

int main() {

    int t;

    for(int k = 1; k <= t; ++k) {

        int v[5];
        int cartas[14];

        for(int i = 0; i < 5; ++i) {
            cin >> v[i];
            cartas[v[i]]++;
        }

        sort(cartas, cartas + 14, compare);
        sort(v, v + 5);

        for(int i = 0; i < 14; ++i) {
            if(cartas[i] == 4) {
                ans = max(ans, 181);
                break;
            }
            else if(cartas[i] == 3 && cartas[i+1] == 2) {
                ans = max(ans, 164);
            }

            else if(cartas[i] == 2 && cartas[i+1] == 2) {
                ans = max(ans, 70);
            }
        }

    }

    return 0;

}