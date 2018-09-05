#include <bits/stdc++.h>

/************************
 * (x^y) mod p
 * **********************/

int powerMod(int x, int y, int p) {
    int resto = 1;
    x = x % p;

    while(y > 0) {
        if(y & 1) resto = (resto * x) % p;

        y = y >> 1; // y = y / 2
        x = (x * x) % p;
    }

    return resto;
}