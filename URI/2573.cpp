#include <bits/stdc++.h>
using namespace std;

int main() {


    int n, m, ai, bi, aj, bj;

    cin >> n >> m;
    cin >> ai >> aj;
    cin >> bi >> bj;

    long double distA, distB; 
    long double A = 0.000, B = 0.0000;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            distA = sqrt(pow(abs(i - ai), 2) + pow(abs(j - aj), 2));        
            distB += sqrt(pow(abs(i - bi), 2) + pow(abs(j - bj), 2));        
        
            printf("%.6Le %.6Le", distA, distB);


            A += 1.00000 - (distA / (distA + distB));
            B += 1.00000 - (distB / (distA + distB));
        }    
    }

    printf("%.6Le %.6Le", A, B);


}