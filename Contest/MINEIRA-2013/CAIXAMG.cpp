#include <bits/stdc++.h>
using namespace std;



int main() {

    int A, B;

    while(scanf("%d %d", &A, &B) == 2 && A != 0) {

        int best = 0, idx;
        for(int i = 1; i <= min(A,B)/2; ++i) {
            int v = (A - 2*i) * (B - 2*i) * i;
            if(v > best) {
                best = v;
                idx = i;
            }
        }

        long double C = (long double)A;
        long double D = (long double)B;

        long double idxD, bestD = 0.0;
        for(long double i = (long double)(idx-1); i <= (long double)(idx+1); i += 0.0001) {
            long double v = (C - 2 * i) * (B - 2 * i) * i;
            if(v > bestD) {
                bestD = v;
                idxD = i;
            }
        }
    
        printf("%.4Lf %.4Lf\n", idxD, bestD);

    }

    return 0;
}